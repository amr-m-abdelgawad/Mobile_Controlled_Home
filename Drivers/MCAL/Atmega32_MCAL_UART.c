/* =======================================================================
 * 	Atmega32_MCAL_UART.c
 * 	UART Driver APIs For Atmega32
 *  Created on: Mar 6, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	UART Driver Includes
 * ==================================================================== */

#include "Atmega32_MCAL_UART.h"
#include "Atmega32_MCAL_DIO.h"
#include "Macros.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	UART Global Variables
 * ==================================================================== */

/*------- Default Configuration -------*/
// If is there is no configuration found in initialization this will be used
static volatile UART_Config UART_DefaultConfig = {
		UART_Polling,
		UART_TX_RX,
		UART_Asynchronous,
		UART_Disable_Double_Transmission_Speed,
		UART_Disable_Multi_Processor_Comm_Mode,
		UART_8_Bits,
		UART_Parity_Disable,
		UART_1_Bit,
		UART_Tx_Rising_Rx_Falling,
		9600,
		NULL,
		NULL,
		NULL
};

/* ==================================================================== */





/* =======================================================================
 * 	UART Driver APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - MCAL_UART_Init
 * 	@ Brief 	 - Initialize the UART according to the specified configuration.
 * 	@ Param [in] - UART_Config: All UART Configuration.
 * 	@ RetVal	 - None.
 *	  Note		 - UART uses Pin 0 & 1 in Port D
 * ==================================================================== */
void MCAL_UART_Init(UART_Config UART_Config){

	/*- Save a Copy of the Configuration -*/
	UART_DefaultConfig = UART_Config;





	/*-------- DIO Configuration --------*/
	// DIO Configure pin 0 in port D as input pin for receiving
	DIO_PinType UART_Rx = {Port_D, Pin0, DIO_Input};
	MCAL_DIO_SetPinDirection(UART_Rx);

	// DIO Configure pin 1 in port D as output pin for transmitting
	DIO_PinType UART_Tx = {Port_D, Pin1, DIO_Output};
	MCAL_DIO_SetPinDirection(UART_Tx);





	/*-- UCSRC Register Configuration --*/
	// Initial value of UCSRC register
	Register_Type UCSRC_Config = 0b10000000;

	// Set UART Configuration
	UCSRC_Config = UCSRC_Config | (UART_DefaultConfig.Synchronization);

	// Set UART Parity
	UCSRC_Config = UCSRC_Config | (UART_DefaultConfig.Parity);

	// Set UART Stop bit select
	UCSRC_Config = UCSRC_Config | (UART_DefaultConfig.Stop_Bit_Select);

	// Set UART Data size
	if((UART_DefaultConfig.Data_Size) == UART_9_Bits) UCSRC_Config = UCSRC_Config | UART_8_Bits;
	else UCSRC_Config = UCSRC_Config | (UART_DefaultConfig.Data_Size);

	// Set UART Clock polarity
	UCSRC_Config = UCSRC_Config | (UART_DefaultConfig.Clock_Polarity);

	// Sets the final configuration to UCSRC register
	UCSRC = UCSRC_Config;





	/*-- UCSRB Register Configuration --*/
	// Initial value of UCSRB register
	Register_Type UCSRB_Config = 0b00000000;

	// Set UART Operation mode
	UCSRB_Config = UCSRB_Config | (UART_DefaultConfig.Operation_Mode);

	// Set UCSZ2 Bit to complete configure if data size is 9 bits
	if((UART_DefaultConfig.Data_Size) == UART_9_Bits) UCSRB_Config = UCSRB_Config | UART_9_Bits;

	// Enable interrupts in case of using UART with interrupt operation mode
	if((UART_DefaultConfig.Operation_Mode) == UART_Interrupt) UCSRB_Config = UCSRB_Config | ((uint8)(1<<UCSRB_RXCIE)) | ((uint8)(1<<UCSRB_TXCIE)) | ((uint8)(1<<UCSRB_UDRIE));

	// Sets the final configuration to UCSRB register
	UCSRB = UCSRB_Config;



	/*-- UCSRA Register Configuration --*/
	Register_Type UCSRA_Config = 0b00000000;

	// Set Double Transmission Speed Configuration
	UCSRA_Config = UCSRA_Config | (UART_DefaultConfig.Double_Transmission_Speed);

	// Set Multi-processor Communication Configuration
	UCSRA_Config = UCSRA_Config | (UART_DefaultConfig.Multi_Processor_Comm_Mode);

	// Sets the final configuration to UCSRA register
	UCSRA = UCSRA_Config;





	/*----- Baud Rate Configuration ----*/
	uint16 UBRR;
	if(UART_DefaultConfig.Synchronization == UART_Synchronous) UBRR = (F_CPU/(2*UART_DefaultConfig.Baud_Rate))-1;
	else {
		if(UART_DefaultConfig.Double_Transmission_Speed == UART_Enable_Double_Transmission_Speed) UBRR = (F_CPU/(8*UART_DefaultConfig.Baud_Rate))-1;
		else  UBRR = (F_CPU/(16*UART_DefaultConfig.Baud_Rate))-1;
	}
	UBRRH = (uint8)(UBRR>>8);
	UBRRL = (uint8)(UBRR & (0xFF));





	/*------ Transmission Modes ------*/
	if(UART_DefaultConfig.Transmission_Mode == UART_TX_Only) SET_BIT(UCSRB,UCSRB_TXEN);
	else if(UART_DefaultConfig.Transmission_Mode == UART_RX_Only) SET_BIT(UCSRB,UCSRB_RXEN);
	else if(UART_DefaultConfig.Transmission_Mode == UART_TX_RX) {
		SET_BIT(UCSRB,UCSRB_TXEN);
		SET_BIT(UCSRB,UCSRB_RXEN);
	}

}

/* =======================================================================
 * 	@ Func  	 - MCAL_UART_ByteReceiveStatus
 * 	@ Brief 	 - Check if there is byte to receive in UART bus.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "UART_BYTE_READY" when there is byte ready to receive,
 *	  			   return "UART_NO_BYTE" when there is nobyte ready to receive.
 * ==================================================================== */
Std_Return MCAL_UART_ByteReceiveStatus(void){

	return GET_BIT(UCSRA,UCSRA_RXC);

}

/* =======================================================================
 * 	@ Func  	 - MCAL_UART_Receive
 * 	@ Brief 	 - Receive data from UART bus.
 * 	@ Param [out]- UART_pRxBuffer: Pointer to the received data buffer.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "UART_FRAME_ERROR" when there is error in the received frame,
 *	  			   return "UART_DATA_OVER_RUN" when the receive buffer is full,
 *	  			   return "UART_PARITY_ERROR" when there is parity error.
 * ==================================================================== */
Std_Return MCAL_UART_Receive(uint16 *UART_pRxBuf){

	/*---- Receive UDR Register Data ---*/
	// Initialize error status with no errors
	Std_Return UART_ReturnError = OK;

	// Read UDR Register Data
	// Receive data in polling operation mode
	while(!GET_BIT(UCSRA,UCSRA_RXC));
	if(UART_DefaultConfig.Data_Size == UART_9_Bits) {
		*(UART_9BitDataType*)UART_pRxBuf = (GET_BIT(UCSRB,UCSRB_RXB8)<<9);
		*(UART_9BitDataType*)UART_pRxBuf = *(UART_9BitDataType*)UART_pRxBuf | UDR;
	}
	else *(UART_8BitDataType*)UART_pRxBuf = UDR;

	// Check if there is frame error
	if(GET_BIT(UCSRA,UCSRA_FE)) UART_ReturnError = UART_FRAME_ERROR;

	// Check if there is data over run error
	else if(GET_BIT(UCSRA,UCSRA_DOR)) UART_ReturnError = UART_DATA_OVER_RUN;

	// Check if there is parity error
	if(UART_DefaultConfig.Parity != UART_Parity_Disable){
		if(GET_BIT(UCSRA,UCSRA_PE)) UART_ReturnError = UART_PARITY_ERROR;
	}

	return UART_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_Send
 * 	@ Brief 	 - Send data to UART bus.
 * 	@ Param [in] - UART_pTxBuf: Data buffer for data to be sent.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void MCAL_UART_Send(uint16 UART_pTxBuf){

	/*----- Send UDR Register Data ----*/
	// Send data in polling operation mode
	while(!GET_BIT(UCSRA,UCSRA_UDRE));
	if(UART_DefaultConfig.Data_Size == UART_9_Bits) {
		switch(GET_BIT(UART_pTxBuf,9)){
			case 0: CLR_BIT(UCSRB,UCSRB_TXB8); break;
			case 1: SET_BIT(UCSRB,UCSRB_TXB8); break;
		}
		UDR = (uint8)(UART_pTxBuf & (0xFF));
	}
	else UDR = (UART_8BitDataType)UART_pTxBuf;
	while(!GET_BIT(UCSRA,UCSRA_TXC));

}


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_SendString
 * 	@ Brief 	 - Send string to UART bus.
 * 	@ Param [in] - UART_String: String which wanted to be sent.
 * 	@ RetVal	 - None.
 * 	  Note		 - This API should be used with 8 bits data size configuration.
 * ==================================================================== */
void MCAL_UART_SendString(const char *UART_String){

	/*-------- Send String Data -------*/
	// Initialize string array index
	uint8 UART_StringIdx = 0;

	// Send first char in the string
	MCAL_UART_Send(*((UART_8BitDataType*)UART_String+UART_StringIdx));

	// Looping in string array and send each character
	while(*((UART_8BitDataType*)UART_String+UART_StringIdx) != '\0'){
		UART_StringIdx++;
		MCAL_UART_Send(*((UART_8BitDataType*)UART_String+UART_StringIdx));
	}

}


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_ReadString
 * 	@ Brief 	 - Read string from UART bus.
 * 	@ Param [Out]- UART_String: Pointer to char array to store string on it.
 * 	@ Param [in] - UART_StringLength: Length of the received string.
 * 	@ RetVal	 - None.
 * 	  Note		 - This API should be used with 8 bits data size configuration.
 * ==================================================================== */
void MCAL_UART_ReadString(char *UART_String){

	/*-------- Receive String Data -------*/
	// Initialize string array index
	uint8 UART_StringIdx = 0;

	// Receive first char in the string
	MCAL_UART_Receive(UART_String+UART_StringIdx);

	// Looping in string array and receive each character
	while(*((UART_8BitDataType*)UART_String+UART_StringIdx) != '#'){
		UART_StringIdx++;
		MCAL_UART_Receive(UART_String+UART_StringIdx);
	}

	// Delete the # and replace it with \0
	*((UART_8BitDataType*)UART_String+UART_StringIdx) = '\0';

}


/* =======================================================================
 * 	@ Brief: Call back function when data received complete interrupt occur.
 * ==================================================================== */
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void){

	/*------- Call Back Function --------*/
	if(UART_DefaultConfig.CallBackFunc_RxComplete != NULL) UART_DefaultConfig.CallBackFunc_RxComplete();

}


/* =======================================================================
 * 	@ Brief: Call back function when data register is empty interrupt occur.
 * ==================================================================== */
void __vector_14 (void) __attribute__((signal));
void __vector_14 (void){

	/*------- Call Back Function --------*/
	if(UART_DefaultConfig.CallBackFunc_DataRegEmpty != NULL) UART_DefaultConfig.CallBackFunc_DataRegEmpty();

}


/* =======================================================================
 * 	@ Brief: Call back function when data transmit is complete interrupt occur.
 * ==================================================================== */
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void){

	/*------- Call Back Function --------*/
	if(UART_DefaultConfig.CallBackFunc_TxComplete != NULL) UART_DefaultConfig.CallBackFunc_TxComplete();

}

/* ==================================================================== */
