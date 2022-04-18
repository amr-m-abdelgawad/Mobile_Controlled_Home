/* =======================================================================
 * 	actuator_control_task.c
 * 	Source Code For Actuator Control Task.
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
extern xSemaphoreHandle Actuator_Access;

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Frame
 * ==================================================================== */

extern Frame Bluetooth;

/* ==================================================================== */





/* =======================================================================
 * 	Actuator Control Task
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Actuator_Control
 * 	@ Brief 	 - Control Actuators task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Actuator_Control(void*pvParameter){
	uint8 Return;

	while(1){


		Return = xSemaphoreTake(Actuator_Access,0);
		if(Return == pdPASS){

			// Take Access to Check Door Lock Status
			if(Bluetooth.Type == BLUETOOTH_DOOR_LOCK) {
				if(*(Bluetooth.Data) == 1) DoorLock_On();
				else DoorLock_Off();
			}

			//Take Access to Check Room 1 Light Status
			else if(Bluetooth.Type == BLUETOOTH_ROOM1_LIGHT) {
				if(*(Bluetooth.Data) == 1) Room1Light_On();
				else Room1Light_Off();
			}

			// Take Access to Check Room 2 Light Status
			else if(Bluetooth.Type == BLUETOOTH_ROOM2_LIGHT) {
				if(*(Bluetooth.Data) == 1) Room2Light_On();
				else Room2Light_Off();
			}

			// Give Access to Bluetooth Frame Again
			xSemaphoreGive(Bluetooth_Data_Access);

		}

		vTaskDelay(3);

	}
}

/* ==================================================================== */
