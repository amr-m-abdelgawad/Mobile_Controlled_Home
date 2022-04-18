/* =======================================================================
 * 	Atmega32_HAL_LED.h
 * 	LED Driver Header For Atmega32
 *  Created on: Dec 10, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


#ifndef HAL_LED_H_
#define HAL_LED_H_

/* =======================================================================
 * 	LED Driver Includes
 * ==================================================================== */

#include "../../../Drivers/MCAL/Includes/Atmega32_MCAL_DIO.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	LED Driver Data Types
 * ==================================================================== */

/*-------- LED Type Structure --------*/
typedef struct{
	uint8 Port;
	uint8 Pin_Number;
} LED_Type;

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
Std_Return HAL_LED_Init(LED_Type LED);


/* =======================================================================
 * 	@ Func  	 - HAL_LED_On
 * 	@ Brief 	 - Turns on LED.
 * 	@ Param [in] - LED: LED which is needed to be turn on.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_LED" when the entered LED is not valid.
 * ==================================================================== */
Std_Return HAL_LED_On(LED_Type LED);


/* =======================================================================
 * 	@ Func  	 - HAL_LED_Off
 * 	@ Brief 	 - Turns off LED.
 * 	@ Param [in] - LED: LED which is needed to be turn off.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_LED" when the entered LED is not valid.
 * ==================================================================== */
Std_Return HAL_LED_Off(LED_Type LED);


/* =======================================================================
 * 	@ Func  	 - HAL_LED_Toggle
 * 	@ Brief 	 - Toggles LED.
 * 	@ Param [in] - LED: LED which is needed to be toggle.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_LED" when the entered LED is not valid.
 * ==================================================================== */
Std_Return HAL_LED_Toggle(LED_Type LED);

/* ==================================================================== */

#endif /* HAL_LED_INCLUDES_LED_INTERFACE_H_ */
