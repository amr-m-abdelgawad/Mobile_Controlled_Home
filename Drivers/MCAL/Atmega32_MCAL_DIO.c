/* =======================================================================
 * 	Atmega32_MCAL_DIO.c
 * 	DIO Driver APIs For Atmega32
 *  Created on: Dec 9, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	DIO Driver Includes
 * ==================================================================== */

#include "Atmega32_MCAL_DIO.h"
#include "Macros.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	DIO Driver APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_SetPortDirection
 * 	@ Brief 	 - Sets port direction as input or output.
 * 	@ Param [in] - DIO_Port: Port which is needed to be set.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_SetPortDirection(DIO_PortType DIO_Port){

	/*---------- Return Values ----------*/
	// Initialize error status with no errors
	Std_Return DIO_ReturnError = OK;

	// Check if there is any errors in the parameter
	if(((DIO_Port.Port) > Port_D) || ((DIO_Port.Port) < 0)) DIO_ReturnError = INVALID_PORT;
	else if((DIO_Port.Port) <= Port_D) DIO_ReturnError = OK;
	else DIO_ReturnError = UNKNOWN;





	/*------- Set Port Direction -------*/
	if(DIO_Port.Direction == DIO_Output) DIO_Port.Direction = 0xFF;
	if(DIO_ReturnError == OK) {
		switch(DIO_Port.Port){

		case Port_A: DDRA = (DIO_Port.Direction); break;
		case Port_B: DDRB = (DIO_Port.Direction); break;
		case Port_C: DDRC = (DIO_Port.Direction); break;
		case Port_D: DDRD = (DIO_Port.Direction); break;

		}
	}

	return DIO_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_SetPinDirection
 * 	@ Brief 	 - Sets specific pin direction as input or output.
 * 	@ Param [in] - DIO_Pin: Pin which is needed to be set.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_SetPinDirection(DIO_PinType DIO_Pin){

	/*---------- Return Values ----------*/
	// Initialize error status with no errors
	Std_Return DIO_ReturnError = OK;

	// Check if there is any error in the parameter
	if(((DIO_Pin.Port) > Port_D) || ((DIO_Pin.Port) < 0)) DIO_ReturnError = INVALID_PORT;
	else if(((DIO_Pin.Pin_Number) > 7) || ((DIO_Pin.Pin_Number) < 0)) DIO_ReturnError = WRONG_PIN;
	else if((DIO_Pin.Port) <= Port_D) DIO_ReturnError = OK;
	else DIO_ReturnError = UNKNOWN;





	/*-------- Set Pin Direction -------*/
	if(DIO_ReturnError == OK) {
		switch(DIO_Pin.Port){

		case Port_A:
			switch(DIO_Pin.Direction){
			case DIO_Output: SET_BIT(DDRA,DIO_Pin.Pin_Number); break;
			case DIO_Input:	CLR_BIT(DDRA,DIO_Pin.Pin_Number); break;
			}
			break;

		case Port_B:
			switch(DIO_Pin.Direction){
			case DIO_Output: SET_BIT(DDRB,DIO_Pin.Pin_Number); break;
			case DIO_Input:	CLR_BIT(DDRB,DIO_Pin.Pin_Number); break;
			}
			break;

		case Port_C:
			switch(DIO_Pin.Direction){
			case DIO_Output: SET_BIT(DDRC,DIO_Pin.Pin_Number); break;
			case DIO_Input:	CLR_BIT(DDRC,DIO_Pin.Pin_Number); break;
			}
			break;

		case Port_D:
			switch(DIO_Pin.Direction){
			case DIO_Output: SET_BIT(DDRD,DIO_Pin.Pin_Number); break;
			case DIO_Input: CLR_BIT(DDRD,DIO_Pin.Pin_Number); break;
			}
			break;

		}
	}

	return DIO_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_WritePort
 * 	@ Brief 	 - Writes port status to set, reset or pull up.
 * 	@ Param [in] - DIO_Port: Port which is needed to be write.
 * 	@ Param [in] - DIO_PortStatus: Port status which is needed to be written.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid
 *	  			   return "UNKNOWN"	when there's unknown error
 * ==================================================================== */
Std_Return MCAL_DIO_WritePort(DIO_PortType DIO_Port, DIO_StatusType DIO_PortStatus){

	/*---------- Return Values ----------*/
	// Initialize error status with no errors
	Std_Return DIO_ReturnError = OK;

	// Check if there is any errors in the parameter
	if(((DIO_Port.Port) > Port_D) || ((DIO_Port.Port) < 0)) DIO_ReturnError = INVALID_PORT;
	else if((DIO_Port.Port) <= Port_D) DIO_ReturnError = OK;
	else DIO_ReturnError = UNKNOWN;





	/*-------- Write Port Status -------*/
	if(DIO_PortStatus == DIO_Set) DIO_PortStatus = 0xFF;
	if(DIO_ReturnError == OK) {
		switch(DIO_Port.Port){

		case Port_A: PORTA = DIO_PortStatus; break;
		case Port_B: PORTB = DIO_PortStatus; break;
		case Port_C: PORTC = DIO_PortStatus; break;
		case Port_D: PORTD = DIO_PortStatus; break;

		}
	}

	return DIO_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_WritePin
 * 	@ Brief 	 - Writes specific pin status to set, reset or pull up.
 * 	@ Param [in] - DIO_Pin: Pin which is needed to be set.
 * 	@ Param [in] - DIO_PinStatus: Pin status which is needed to be written.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_WritePin(DIO_PinType DIO_Pin, DIO_StatusType DIO_PinStatus){

	/*---------- Return Values ----------*/
	// Initialize error status with no errors
	Std_Return DIO_ReturnError = OK;

	// Check if there is any error in the parameter
	if(((DIO_Pin.Port) > Port_D) || ((DIO_Pin.Port) < 0)) DIO_ReturnError = INVALID_PORT;
	else if(((DIO_Pin.Pin_Number) > 7) || ((DIO_Pin.Pin_Number) < 0)) DIO_ReturnError = WRONG_PIN;
	else if((DIO_Pin.Port) <= Port_D) DIO_ReturnError = OK;
	else DIO_ReturnError = UNKNOWN;





	/*--------- Write Pin Status --------*/
	if(DIO_ReturnError == OK) {
		switch(DIO_Pin.Port){

		case Port_A:
			switch(DIO_PinStatus){
			case DIO_Set: SET_BIT(PORTA,DIO_Pin.Pin_Number); break;
			case DIO_Reset: CLR_BIT(PORTA,DIO_Pin.Pin_Number); break;
			}
			break;

		case Port_B:
			switch(DIO_PinStatus){
			case DIO_Set: SET_BIT(PORTB,DIO_Pin.Pin_Number); break;
			case DIO_Reset: CLR_BIT(PORTB,DIO_Pin.Pin_Number); break;
			}
			break;

		case Port_C:
			switch(DIO_PinStatus){
			case DIO_Set: SET_BIT(PORTC,DIO_Pin.Pin_Number); break;
			case DIO_Reset: CLR_BIT(PORTC,DIO_Pin.Pin_Number); break;
			}
			break;

		case Port_D:
			switch(DIO_PinStatus){
			case DIO_Set: SET_BIT(PORTD,DIO_Pin.Pin_Number); break;
			case DIO_Reset: CLR_BIT(PORTD,DIO_Pin.Pin_Number); break;
			}
			break;

		}
	}

	return DIO_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_GetPort
 * 	@ Brief 	 - Gets port status.
 * 	@ Param [in] - DIO_Port: Port which is needed to be read.
 * 	@ Param [in] - DIO_pPortStatusBuf: Pointer to port status reading buffer.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid
 *	  			   return "UNKNOWN"	when there's unknown error
 * ==================================================================== */
Std_Return MCAL_DIO_GetPort(DIO_PortType DIO_Port, DIO_StatusType *DIO_pPortStatusBuf){

	/*---------- Return Values ----------*/
	// Initialize error status with no errors
	Std_Return DIO_ReturnError = OK;

	// Check if there is any errors in the parameter
	if(((DIO_Port.Port) > Port_D) || ((DIO_Port.Port) < 0)) DIO_ReturnError = INVALID_PORT;
	else if((DIO_Port.Port) <= Port_D) DIO_ReturnError = OK;
	else DIO_ReturnError = UNKNOWN;





	/*-------- Get Port Status -------*/
	if(DIO_ReturnError == OK) {
		switch (DIO_Port.Port){

		case Port_A: *DIO_pPortStatusBuf = PINA; break;
		case Port_B: *DIO_pPortStatusBuf = PINB; break;
		case Port_C: *DIO_pPortStatusBuf = PINC; break;
		case Port_D: *DIO_pPortStatusBuf = PIND; break;

		}
	}

	return DIO_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_GetPin
 * 	@ Brief 	 - Gets pin status.
 * 	@ Param [in] - DIO_Pin: Pin which is needed to be read.
 * 	@ Param [in] - DIO_PinStatusBuf: Pointer to pin status reading buffer.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_GetPin(DIO_PinType DIO_Pin, DIO_StatusType *DIO_pPinStatusBuf){

	/*---------- Return Values ----------*/
	// Initialize error status with no errors
	Std_Return DIO_ReturnError = OK;

	// Check if there is any error in the parameter
	if(((DIO_Pin.Port) > Port_D) || ((DIO_Pin.Port) < 0)) DIO_ReturnError = INVALID_PORT;
	else if(((DIO_Pin.Pin_Number) > 7) || ((DIO_Pin.Pin_Number) < 0)) DIO_ReturnError = WRONG_PIN;
	else if((DIO_Pin.Port) <= Port_D) DIO_ReturnError = OK;
	else DIO_ReturnError = UNKNOWN;





	/*---------- Get Pin Status ---------*/
	if(DIO_ReturnError == OK) {
		switch (DIO_Pin.Port){

		case Port_A: *DIO_pPinStatusBuf = GET_BIT(PINA,DIO_Pin.Pin_Number); break;
		case Port_B: *DIO_pPinStatusBuf = GET_BIT(PINB,DIO_Pin.Pin_Number); break;
		case Port_C: *DIO_pPinStatusBuf = GET_BIT(PINC,DIO_Pin.Pin_Number); break;
		case Port_D: *DIO_pPinStatusBuf = GET_BIT(PIND,DIO_Pin.Pin_Number); break;

		}
	}

	return DIO_ReturnError;

}

/* ==================================================================== */
