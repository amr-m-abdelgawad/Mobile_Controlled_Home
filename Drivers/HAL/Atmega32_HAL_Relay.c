/* =======================================================================
 * 	Atmega32_HAL_Relay.c
 * 	Relay Driver APIs
 *  Created on: Apr 14, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	Relay Driver Includes
 * ==================================================================== */

#include "Atmega32_HAL_Relay.h"
#include "Atmega32_MCAL_DIO.h"
#include "Macros.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	Relay Driver APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - HAL_Relay_Init
 * 	@ Brief 	 - Initialize the Relay according to the specified configuration.
 * 	@ Param [in] - Relay: Relay which is needed to be initialize.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return HAL_Relay_Init(Relay_Type Relay){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType Relay_Pin;
	Relay_Pin.Port = Relay.Port;
	Relay_Pin.Pin_Number = Relay.Pin_Number;
	Relay_Pin.Direction = DIO_Output;




	/*------ Set Pin as Output Pin ------*/
	Std_Return DIO_Return;
	DIO_Return = MCAL_DIO_SetPinDirection(Relay_Pin);

	return DIO_Return;

}


/* =======================================================================
 * 	@ Func  	 - HAL_Relay_On
 * 	@ Brief 	 - Turns on Relay.
 * 	@ Param [in] - Relay: Relay which is needed to be turn on.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_RELAY" when the entered Relay is not valid.
 * ==================================================================== */
Std_Return HAL_Relay_On(Relay_Type Relay){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType Relay_Pin;
	Relay_Pin.Port = Relay.Port;
	Relay_Pin.Pin_Number = Relay.Pin_Number;





	/*---------- Set Relay Pin -----------*/
	// Initialize error status with no errors
	Std_Return Relay_ReturnError = OK;

	// Write Relay pin to set and receive if there is any error from DIO
	Std_Return DIO_Return;
	DIO_Return = MCAL_DIO_WritePin(Relay_Pin,DIO_Set);

	// There is error returned from DIO
	if(DIO_Return != OK) Relay_ReturnError = INVALID_RELAY;

	return Relay_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - HAL_Relay_Off
 * 	@ Brief 	 - Turns off Relay.
 * 	@ Param [in] - Relay: Relay which is needed to be turn off.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_RELAY" when the entered Relay is not valid.
 * ==================================================================== */
Std_Return HAL_Relay_Off(Relay_Type Relay){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType Relay_Pin;
	Relay_Pin.Port = Relay.Port;
	Relay_Pin.Pin_Number = Relay.Pin_Number;





	/*---------- Set Relay Pin -----------*/
	// Initialize error status with no errors
	Std_Return Relay_ReturnError = OK;

	// Write Relay pin to set and receive if there is any error from DIO
	Std_Return DIO_Return;
	DIO_Return = MCAL_DIO_WritePin(Relay_Pin,DIO_Reset);

	// There is error returned from DIO
	if(DIO_Return != OK) Relay_ReturnError = INVALID_RELAY;

	return Relay_ReturnError;

}

/* ==================================================================== */
