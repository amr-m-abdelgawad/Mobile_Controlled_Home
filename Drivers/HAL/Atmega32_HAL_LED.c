/* =======================================================================
 * 	Atmega32_HAL_LED.c
 * 	LED Driver APIs
 *  Created on: Dec 10, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	LED Driver Includes
 * ==================================================================== */

#include "Atmega32_HAL_LED.h"
#include "Atmega32_MCAL_DIO.h"
#include "Macros.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	LED Driver APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - HAL_LED_Init
 * 	@ Brief 	 - Initialize the LED according to the specified configuration.
 * 	@ Param [in] - LED: LED which is needed to be initialize.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return HAL_LED_Init(LED_Type LED){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType LED_Pin;
	LED_Pin.Port = LED.Port;
	LED_Pin.Pin_Number = LED.Pin_Number;
	LED_Pin.Direction = DIO_Output;




	/*------ Set Pin as Output Pin ------*/
	Std_Return DIO_Return;
	DIO_Return = MCAL_DIO_SetPinDirection(LED_Pin);

	return DIO_Return;

}


/* =======================================================================
 * 	@ Func  	 - HAL_LED_On
 * 	@ Brief 	 - Turns on LED.
 * 	@ Param [in] - LED: LED which is needed to be turn on.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_LED" when the entered LED is not valid.
 * ==================================================================== */
Std_Return HAL_LED_On(LED_Type LED){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType LED_Pin;
	LED_Pin.Port = LED.Port;
	LED_Pin.Pin_Number = LED.Pin_Number;





	/*---------- Set LED Pin -----------*/
	// Initialize error status with no errors
	Std_Return LED_ReturnError = OK;

	// Write LED pin to set and receive if there is any error from DIO
	Std_Return DIO_Return;
	DIO_Return = MCAL_DIO_WritePin(LED_Pin,DIO_Set);

	// There is error returned from DIO
	if(DIO_Return != OK) LED_ReturnError = INVALID_LED;

	return LED_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - HAL_LED_Off
 * 	@ Brief 	 - Turns off LED.
 * 	@ Param [in] - LED: LED which is needed to be turn off.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_LED" when the entered LED is not valid.
 * ==================================================================== */
Std_Return HAL_LED_Off(LED_Type LED){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType LED_Pin;
	LED_Pin.Port = LED.Port;
	LED_Pin.Pin_Number = LED.Pin_Number;





	/*---------- Reset LED Pin ----------*/
	// Initialize error status with no errors
	Std_Return LED_ReturnError = OK;

	// Write LED pin to reset and receive if there is any error from DIO
	Std_Return DIO_Return;
	DIO_Return = MCAL_DIO_WritePin(LED_Pin,DIO_Reset);

	// There is error returned from DIO
	if(DIO_Return != OK) LED_ReturnError = INVALID_LED;

	return LED_ReturnError;

}


/* =======================================================================
 * 	@ Func  	 - HAL_LED_Toggle
 * 	@ Brief 	 - Toggles LED.
 * 	@ Param [in] - LED: LED which is needed to be toggle.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_LED" when the entered LED is not valid.
 * ==================================================================== */
Std_Return HAL_LED_Toggle(LED_Type LED){

	/*------ DIO Pin Configuration ------*/
	DIO_PinType LED_Pin;
	LED_Pin.Port = LED.Port;
	LED_Pin.Pin_Number = LED.Pin_Number;





	/*------- Get LED Pin Status -------*/
	// Initialize error status with no errors
	Std_Return LED_ReturnError = OK;

	// Get LED pin status and receive if there is any error from DIO
	Std_Return DIO_Return;
	DIO_StatusType LED_PinStatus;
	DIO_Return = MCAL_DIO_GetPin(LED_Pin,&LED_PinStatus);





	/*----- Toggle LED Pin Status -----*/
	// Toggle LED pin status and receive if there is any error from DIO
	if(DIO_Return == OK){
		switch(LED_PinStatus){

		case DIO_Set: DIO_Return = MCAL_DIO_WritePin(LED_Pin,DIO_Reset); break;
		case DIO_Reset: DIO_Return = MCAL_DIO_WritePin(LED_Pin,DIO_Set); break;

		}
	}

	// There is error returned from DIO
	if(DIO_Return != OK) LED_ReturnError = INVALID_LED;

	return LED_ReturnError;

}

/* ==================================================================== */
