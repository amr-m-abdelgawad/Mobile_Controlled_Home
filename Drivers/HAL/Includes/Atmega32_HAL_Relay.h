/* =======================================================================
 * 	Atmega32_Relay_LED.h
 * 	Relay Driver Header For Atmega32
 *  Created on: April 17, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


#ifndef HAL_INCLUDES_ATMEGA32_HAL_RELAY_H_
#define HAL_INCLUDES_ATMEGA32_HAL_RELAY_H_


/* =======================================================================
 * 	Relay Driver Includes
 * ==================================================================== */

#include "../../../Drivers/MCAL/Includes/Atmega32_MCAL_DIO.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	Relay Driver Data Types
 * ==================================================================== */

/*-------- Relay Type Structure --------*/
typedef struct{
	uint8 Port;
	uint8 Pin_Number;
} Relay_Type;

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
Std_Return HAL_Relay_Init(Relay_Type Relay);


/* =======================================================================
 * 	@ Func  	 - HAL_Relay_On
 * 	@ Brief 	 - Turns on Relay.
 * 	@ Param [in] - Relay: Relay which is needed to be turn on.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_RELAY" when the entered Relay is not valid.
 * ==================================================================== */
Std_Return HAL_Relay_On(Relay_Type Relay);


/* =======================================================================
 * 	@ Func  	 - HAL_Relay_Off
 * 	@ Brief 	 - Turns off Relay.
 * 	@ Param [in] - Relay: Relay which is needed to be turn off.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_RELAY" when the entered Relay is not valid.
 * ==================================================================== */
Std_Return HAL_Relay_Off(Relay_Type Relay);

/* ==================================================================== */

#endif /* HAL_INCLUDES_ATMEGA32_HAL_RELAY_H_ */
