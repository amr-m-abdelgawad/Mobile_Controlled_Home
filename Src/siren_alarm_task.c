/* =======================================================================
 * 	siren_alarm_task.c
 * 	Source Code For Siren Alarm Task.
 *  Created on: April 17, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	Task Includes
 * ==================================================================== */

#include "os_tasks.h"

/* ==================================================================== */





/* =======================================================================
 * 	Task Semaphores
 * ==================================================================== */

extern xSemaphoreHandle Bluetooth_Data_Access;
extern xSemaphoreHandle Siren_Alarm_Access;

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Frame
 * ==================================================================== */

extern Frame Bluetooth;

/* ==================================================================== */





/* =======================================================================
 * 	Siren Alarm Task
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Siren_Alarm
 * 	@ Brief 	 - Control Siren Alarm task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Siren_Alarm(void*pvParameter){
	uint8 Return;

	while(1){

		// Take Access to Check Siren Alarm Status
		Return = xSemaphoreTake(Siren_Alarm_Access,0);
		if(Return == pdPASS) {
			if(Bluetooth.Data[0] == 1) SirenAlarm_On();
			else SirenAlarm_Off();

			// Give Access to Bluetooth Frame Again
			xSemaphoreGive(Bluetooth_Data_Access);
		}

		vTaskDelay(3);

	}
}

/* ==================================================================== */
