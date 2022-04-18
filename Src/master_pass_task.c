/* =======================================================================
 * 	master_pass_task.c
 * 	Source Code For Master Access Task.
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
extern xSemaphoreHandle User_Master_Access;

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Frame
 * ==================================================================== */

extern Frame Bluetooth;

/* ==================================================================== */





/* =======================================================================
 * 	Master Access Task
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Master_Access
 * 	@ Brief 	 - Master Access to User Management task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Master_Access(void*pvParameter){

	uint8 Return;

	while(1){

		// Take Access to Check the Received Master Pass
		Return = xSemaphoreTake(User_Master_Access,0);
		if(Return == pdPASS) {
			if(atoi((char*)Bluetooth.Data) == MASTER_PASS) MCAL_UART_Send(ACCEPT_ACCESS);
			else MCAL_UART_Send(REFUSE_ACCESS);

			// Give Access to Bluetooth Frame Again
			xSemaphoreGive(Bluetooth_Data_Access);
		}

		vTaskDelay(3);

	}

}

/* ==================================================================== */
