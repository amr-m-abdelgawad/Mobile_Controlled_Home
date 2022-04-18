/* =======================================================================
 * 	Atmega32_MCAL_UART.h
 * 	UART Driver Header For Atmega32
 *  Created on: Mar 6, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


#ifndef INCLUDES_ATMEGA32_MCAL_UART_H_
#define INCLUDES_ATMEGA32_MCAL_UART_H_

/* =======================================================================
 * 	UART Driver Includes
 * ==================================================================== */

#include "Atmega32_MCAL_DIO.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	UART Driver Data Types
 * ==================================================================== */

/*-------- Configuration Structure --------*/
typedef struct {
	// Operation Mode: Specifies how TX & RX operates (Polling or Interrupt).
	uint8	Operation_Mode;

	// Transmission Mode: Specifies what kind of transmission will operates (TX_Only or Rx_Only or TX_RX)
	uint8	Transmission_Mode;

	// Synchronization: Specifies is UART protocol synchronization (Synchronous or Asynchronous).
	uint8	Synchronization;

	// Double Transmission Speed: Doubling the transfer rate for asynchronous communication.
	// !! Only with Asynchronous UART.
	uint8	Double_Transmission_Speed;

	// Multi-processor Communication Mode:  All the incoming frames received by the UART receiver that do not contain address information will be ignored.
	uint8	Multi_Processor_Comm_Mode;

	// Data Size: Specifies the number of bits of the data (5, 6, 7, 8 or 9) bits.
	uint8	Data_Size;

	// Parity: Specifies parity mode (Odd, Even or Disable).
	uint8	Parity;

	// Stop Bit Select: Specifies stop bits in frame to be 1 bit or 2 bits.
	uint8	Stop_Bit_Select;

	// Clock Polarity: Sets the relationship between data output change and data input sample,and the synchronous clock (XCK).
	// !! Only with Synchronous UART
	uint8	Clock_Polarity;

	// Baud Rate: Specifies Baud rate of the transmission.
	uint32	Baud_Rate;

	// Call Back Function: Returns callback function when complete receiving.
	// !! Only with Interrupt Operation Mode.
	void(*CallBackFunc_RxComplete)(void);

	// Call Back Function: Returns callback function when complete Transmitting.
	// !! Only with Interrupt Operation Mode.
	void(*CallBackFunc_TxComplete)(void);

	// Call Back Function: Returns callback function when data register is empty.
	// !! Only with Interrupt Operation Mode.
	void(*CallBackFunc_DataRegEmpty)(void);
} UART_Config;


/*-------- Data Buffer Structure --------*/
typedef uint8 UART_8BitDataType;
typedef uint16 UART_9BitDataType;

/* ==================================================================== */





/* =======================================================================
 * 	UART Driver Macros
 * ==================================================================== */

/*------- CPU Frequency -------*/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif


/*------- UART Synchronization Modes -------*/
#define UART_Asynchronous			(uint8)(0<<UCSRC_UMSEL)
#define UART_Synchronous			(uint8)(1<<UCSRC_UMSEL)


/*----------- UART Parity Modes ------------*/
#define UART_Parity_Disable			(uint8)((0<<UCSRC_UPM1) | (0<<UCSRC_UPM0))
#define UART_Parity_Even			(uint8)((1<<UCSRC_UPM1) | (0<<UCSRC_UPM0))
#define UART_Parity_Odd				(uint8)((1<<UCSRC_UPM1) | (1<<UCSRC_UPM0))


/*------ UART Stop Bit Select Options ------*/
#define UART_1_Bit					(uint8)(0<<UCSRC_USBS)
#define UART_2_Bits					(uint8)(1<<UCSRC_USBS)


/*--------- UART Data Size Options ---------*/
#define UART_5_Bits					(uint8)((0<<UCSRC_UCSZ1) | (0<<UCSRC_UCSZ0))
#define UART_6_Bits					(uint8)((0<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0))
#define UART_7_Bits					(uint8)((1<<UCSRC_UCSZ1) | (0<<UCSRC_UCSZ0))
#define UART_8_Bits					(uint8)((1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0))
#define UART_9_Bits					(uint8)(1<<UCSRB_UCSZ2)


/*------- UART Clock Polarity Modes --------*/
#define UART_Tx_Rising_Rx_Falling	(uint8)(0<<UCSRC_UCPOL)
#define UART_Tx_Falling_Rx_Rising	(uint8)(1<<UCSRC_UCPOL)


/*--------- UART Operations Modes ----------*/
#define UART_Polling				(uint8)((0<<UCSRB_RXCIE) | (0<<UCSRB_TXCIE)| (0<<UCSRB_UDRIE))
#define UART_Interrupt				(uint8)((1<<UCSRB_RXCIE) | (1<<UCSRB_TXCIE)| (1<<UCSRB_UDRIE))


/*-- UART Double Transmission Speed Modes --*/
#define UART_Disable_Double_Transmission_Speed	(uint8)(0<<UCSRA_U2X)
#define UART_Enable_Double_Transmission_Speed	(uint8)(1<<UCSRA_U2X)


/*- UART Multi-processor Communication Modes -*/
#define UART_Disable_Multi_Processor_Comm_Mode	(uint8)(0<<UCSRA_MPCM)
#define UART_Enable_Multi_Processor_Comm_Mode	(uint8)(1<<UCSRA_MPCM)


/*------- UART Transmission Modes --------*/
#define UART_RX_Only				0
#define UART_TX_Only				1
#define UART_TX_RX					2


/*------- UART Receive Return Codes --------*/
#define UART_BYTE_READY				1
#define UART_NO_BYTE				0

/* ==================================================================== */





/* =======================================================================
 * 	UART Driver Registers
 * ==================================================================== */

/*--------- UART UDR Register ---------*/
#define UDR *((volatile uint8*)0x2C)


/*-------- UART UCSRA Register --------*/
#define UCSRA *((volatile uint8*)0x2B)
#define UCSRA_MPCM	Pin0
#define UCSRA_U2X	Pin1
#define UCSRA_PE	Pin2
#define UCSRA_DOR	Pin3
#define UCSRA_FE	Pin4
#define UCSRA_UDRE	Pin5
#define UCSRA_TXC	Pin6
#define UCSRA_RXC	Pin7


/*-------- UART UCSRB Register --------*/
#define UCSRB *((volatile uint8*)0x2A)
#define UCSRB_TXB8	Pin0
#define UCSRB_RXB8	Pin1
#define UCSRB_UCSZ2	Pin2
#define UCSRB_TXEN	Pin3
#define UCSRB_RXEN	Pin4
#define UCSRB_UDRIE	Pin5
#define UCSRB_TXCIE	Pin6
#define UCSRB_RXCIE	Pin7


/*-------- UART UCSRC Register --------*/
#define UCSRC *((volatile uint8*)0x40)
#define UCSRC_UCPOL	Pin0
#define UCSRC_UCSZ0	Pin1
#define UCSRC_UCSZ1	Pin2
#define UCSRC_USBS	Pin3
#define UCSRC_UPM0	Pin4
#define UCSRC_UPM1	Pin5
#define UCSRC_UMSEL	Pin6
#define UCSRC_URSEL	Pin7


/*-------- UART UBRRH Register --------*/
#define UBRRH *((volatile uint8*)0x40)
#define UBRRH_URSEL	Pin7


/*-------- UART UBRRL Register --------*/
#define UBRRL *((volatile uint8*)0x29)

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
void MCAL_UART_Init(UART_Config UART_Config);


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_ByteReceiveStatus
 * 	@ Brief 	 - Check if there is byte to receive in UART bus.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "UART_BYTE_READY" when there is byte ready to receive,
 *	  			   return "UART_NO_BYTE" when there is nobyte ready to receive.
 * ==================================================================== */
Std_Return MCAL_UART_ByteReceiveStatus(void);


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
Std_Return MCAL_UART_Receive(uint16 *UART_pRxBuf);


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_Send
 * 	@ Brief 	 - Send data to UART bus.
 * 	@ Param [in] - UART_pTxBuf: Data buffer for data to be sent.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void MCAL_UART_Send(uint16 UART_pTxBuf);


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_SendString
 * 	@ Brief 	 - Send string to UART bus.
 * 	@ Param [in] - UART_String: String which wanted to be sent.
 * 	@ RetVal	 - None.
 * 	  Note		 - This API should be used with 8 bits data size configuration.
 * ==================================================================== */
void MCAL_UART_SendString(const char *UART_String);


/* =======================================================================
 * 	@ Func  	 - MCAL_UART_ReadString
 * 	@ Brief 	 - Read string from UART bus.
 * 	@ Param [Out]- UART_String: Pointer to char array to store string on it.
 * 	@ Param [in] - UART_StringLength: Length of the received string.
 * 	@ RetVal	 - None.
 * 	  Note		 - This API should be used with 8 bits data size configuration.
 * ==================================================================== */
void MCAL_UART_ReadString(char *UART_String);

/* ==================================================================== */

#endif /* INCLUDES_ATMEGA32_MCAL_UART_H_ */
