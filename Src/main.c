/* =======================================================================
 * 	main.c
 * 	Source Code For Mobile Home Controlled Application.
 *  Created on: Mar 20, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	Main Includes
 * ==================================================================== */

#include "main.h"

/* ==================================================================== */




/* =======================================================================
 * 	System Error LED
 * ==================================================================== */

LED_Type SystemErrorLED   = {Port_A,Pin4};

/* ==================================================================== */






/* =======================================================================
 * 	Microcontroller Unit Initialization
 * ==================================================================== */

void MCU_Init(void) {

	// Initialize UART Driver
	UART_Config UART_DefaultConfig = {
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
	MCAL_UART_Init(UART_DefaultConfig);

	// Initialize User Management
	User_Init();

	// Initialize Actuators
	Actuators_Init();

	// Initialize LEDs
	HAL_LED_Init(SystemErrorLED);

}

/* ==================================================================== */





/* =======================================================================
 * 	APP Main
 * ==================================================================== */

int main(void){

	/* =======================================================================
	 * 	Initialize Microcontroller Unit
	 * ==================================================================== */

	MCU_Init();

	/* ==================================================================== */





	/* =======================================================================
	 * 	Initialize APP OS
	 * ==================================================================== */

	OS_Init();

	/* ==================================================================== */





	/* =======================================================================
	 * 	Start APP Task Scheduler
	 * ==================================================================== */

	vTaskStartScheduler();

	/* ==================================================================== */

}

/* ==================================================================== */