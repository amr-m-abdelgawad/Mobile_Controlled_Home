/* =======================================================================
 * 	os.c
 * 	Source Code For RTOS OS Initialization.
 *  Created on: Mar 20, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	OS Includes
 * ==================================================================== */

#include "os_tasks.h"

/* ==================================================================== */





/* =======================================================================
 * 	APP Tasks Handles
 * ==================================================================== */

xTaskHandle Bluetooth_Receive_Task_Handle;
xTaskHandle Master_Access_Task_Handle;
xTaskHandle User_Manage_Task_Handle;
xTaskHandle Siren_Alarm_Task_Handle;
xTaskHandle Actuator_Control_Task_Handle;

/* ==================================================================== */





/* =======================================================================
 * 	APP Semaphores
 * ==================================================================== */

xSemaphoreHandle Bluetooth_Data_Access;
xSemaphoreHandle User_Master_Access;
xSemaphoreHandle User_Login_Access;
xSemaphoreHandle User_Add_Access;
xSemaphoreHandle User_Remove_Access;
xSemaphoreHandle Siren_Alarm_Access;
xSemaphoreHandle Actuator_Access;

/* ==================================================================== */





/* =======================================================================
 * 	APP OS Initialization
 * ==================================================================== */

void OS_Init(void) {

	/* =======================================================================
	 * 	APP Semaphores Creation
	 * ==================================================================== */

	// Bluetooth Data Semaphore
	Bluetooth_Data_Access = xSemaphoreCreateCounting(1,1);

	// Master Access Semaphore
	User_Master_Access = xSemaphoreCreateCounting(1,0);

	// User Log In Semaphore
	User_Login_Access = xSemaphoreCreateCounting(1,0);

	// User Add Semaphore
	User_Add_Access = xSemaphoreCreateCounting(1,0);

	// User Remove Semaphore
	User_Remove_Access = xSemaphoreCreateCounting(1,0);

	// Siren Alarm Semaphore
	Siren_Alarm_Access = xSemaphoreCreateCounting(1,0);

	// Door Lock Semaphore
	Actuator_Access = xSemaphoreCreateCounting(1,0);

	/* ==================================================================== */





	/* =======================================================================
	 * 	APP Tasks Creation
	 * ==================================================================== */

	// Receiving Data From Bluetooth Task
	xTaskCreate(Bluetooth_Receive, NULL, configMINIMAL_STACK_SIZE, NULL, BLUETOOTH_RECEIVE_PRIORITY, Bluetooth_Receive_Task_Handle);

	// Master Access Task
	xTaskCreate(Master_Access, NULL, configMINIMAL_STACK_SIZE, NULL, MASTER_ACCESS_PRIORITY, Master_Access_Task_Handle);

	// User Management Task
	xTaskCreate(User_Manage, NULL, configMINIMAL_STACK_SIZE, NULL, USER_PRIORITY, User_Manage_Task_Handle);

	// Siren Alarm Task
	xTaskCreate(Siren_Alarm, NULL, configMINIMAL_STACK_SIZE, NULL, SIREN_ALARM_PRIORITY, Siren_Alarm_Task_Handle);

	// Actuator Control Task
	xTaskCreate(Actuator_Control, NULL, configMINIMAL_STACK_SIZE, NULL, ACTUATOR_CONTROL_PRIORITY, Actuator_Control_Task_Handle);

	/* ==================================================================== */

}

/* ==================================================================== */
