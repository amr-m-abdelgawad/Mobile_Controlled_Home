/* =======================================================================
 * 	main.h
 * 	Header File For Mobile Home Controlled Application.
 *  Created on: Dec 9, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef INCLUDES_MAIN_H_
#define INCLUDES_MAIN_H_

/* =======================================================================
 * 	Main Includes
 * ==================================================================== */

#include "Atmega32_HAL_LED.h"
#include "Atmega32_MCAL_UART.h"
#include "Std_Types.h"
#include "FreeRTOS.h"
#include "actuators.h"
#include "user_manage_control.h"
#include "os_tasks.h"

/* ==================================================================== */





/* =======================================================================
 * 	Microcontroller Unit Initialization
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - MCU_Init
 * 	@ Brief 	 - Initialize Microcontroller Unit.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void MCU_Init(void);

/* ==================================================================== */

#endif /* INCLUDES_MAIN_H_ */
