/* =======================================================================
 * 	user_manage_task.c
 * 	Source Code For User Management Task.
 *  Created on: April 17, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	Task Includes
 * ==================================================================== */

#include <stdlib.h>
#include "os_tasks.h"

/* ==================================================================== */





/* =======================================================================
 * 	Task Semaphores
 * ==================================================================== */

extern xSemaphoreHandle Bluetooth_Data_Access;
extern xSemaphoreHandle User_Login_Access;
extern xSemaphoreHandle User_Add_Access;
extern xSemaphoreHandle User_Remove_Access;

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Frame
 * ==================================================================== */

extern Frame Bluetooth;

/* ==================================================================== */





/* =======================================================================
 * 	User Management Task
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - User_Manage
 * 	@ Brief 	 - User Management task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void User_Manage(void*pvParameter){

	uint8 Return;

	while(1){

		// Take Access to User Log In Management
		Return = xSemaphoreTake(User_Login_Access,0);
		if(Return == pdPASS) {
			if(User_Search((char*)Bluetooth.Data,atoi((char*)Bluetooth.Pass),NULL) == USER_FOUND) MCAL_UART_Send(ACCEPT_ACCESS);
			else MCAL_UART_Send(REFUSE_ACCESS);

			// Give Access to Bluetooth Frame Again
			xSemaphoreGive(Bluetooth_Data_Access);
		}

		// Take Access to Add User Management
		Return = xSemaphoreTake(User_Add_Access,0);
		if(Return == pdPASS) {
			if(User_Add((char*)Bluetooth.Data,atoi((char*)Bluetooth.Pass)) == USER_ADD_DONE) MCAL_UART_Send(ACCEPT_ACCESS);
			else MCAL_UART_Send(REFUSE_ACCESS);

			// Give Access to Bluetooth Frame Again
			xSemaphoreGive(Bluetooth_Data_Access);
		}

		// Take Access to Remove User Management
		Return = xSemaphoreTake(User_Remove_Access,0);
		if(Return == pdPASS) {
			if(User_Delete((char*)Bluetooth.Data,atoi((char*)Bluetooth.Pass)) == USER_DELETED) MCAL_UART_Send(ACCEPT_ACCESS);
			else MCAL_UART_Send(REFUSE_ACCESS);

			// Give Access to Bluetooth Frame Again
			xSemaphoreGive(Bluetooth_Data_Access);
		}

		vTaskDelay(3);

	}
}

/* ==================================================================== */
