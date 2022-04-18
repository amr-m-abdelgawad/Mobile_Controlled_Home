/* =======================================================================
 * 	bluetooth_receive_task.c
 * 	Source Code For Bluetooth Receive Task.
 *  Created on: April 17, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	Task Includes
 * ==================================================================== */

#include <stdlib.h>
#include <string.h>
#include "os_tasks.h"

/* ==================================================================== */





/* =======================================================================
 * 	Task Semaphores
 * ==================================================================== */

extern xSemaphoreHandle Bluetooth_Data_Access;
extern xSemaphoreHandle User_Master_Access;
extern xSemaphoreHandle User_Login_Access;
extern xSemaphoreHandle User_Add_Access;
extern xSemaphoreHandle User_Remove_Access;
extern xSemaphoreHandle Siren_Alarm_Access;
extern xSemaphoreHandle Actuator_Access;

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Frame
 * ==================================================================== */

Frame Bluetooth;

/* ==================================================================== */





/* =======================================================================
 * 	Bluetooth Receive Task
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Bluetooth_Receive
 * 	@ Brief 	 - Receiving data from bluetooth task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Bluetooth_Receive(void*pvParameter){

	uint8 Return;
	static uint8 ReceiveIdx = 0;
	static uint8 DataIdx = 0;
	static uint8 PassIdx = 0;
	static uint8 PassFlag = 0;
	UART_8BitDataType DataBuf;

	while(1){

		// Check if There is Bytes to Receive
		if(MCAL_UART_ByteReceiveStatus() == UART_BYTE_READY){

			// Take Access to Write On the Bluetooth Buffers
			Return = xSemaphoreTake(Bluetooth_Data_Access,0);
			if(Return == pdPASS) {

				// Receive Frame Start Byte
				MCAL_UART_Receive(&DataBuf);
				if(DataBuf == BLUETOOTH_FRAME_START) {

					// Clean Data & Pass Buffers
					memset((char*)Bluetooth.Data,'\0',15*sizeof(UART_8BitDataType));
					memset((char*)Bluetooth.Pass,'\0',5*sizeof(UART_8BitDataType));

					// Receive Frame Type Byte
					MCAL_UART_Receive(&DataBuf);
					while(DataBuf != BLUETOOTH_FRAME_STOP) {
						if(ReceiveIdx == FRAME_TYPE_IDX) Bluetooth.Type = DataBuf;
						else {

							// Set Flag That Incoming Bytes Are For Pass When Receiving Pass Indicator
							if(DataBuf == BLUETOOTH_PASS_IND) PassFlag = 1;
							else {

								// Store Bytes in Pass Buffer
								if(PassFlag == 1){
									Bluetooth.Pass[PassIdx] = DataBuf;
									PassIdx++;
								}

								// Store Bytes in Data Buffer
								else {
									Bluetooth.Data[DataIdx] = DataBuf;
									DataIdx++;
								}
							}
						}
						ReceiveIdx++;
						MCAL_UART_Receive(&DataBuf);
					}

					// Set Event For the Desired Task
					if(Bluetooth.Type == BLUETOOTH_USER_LOGIN) xSemaphoreGive(User_Login_Access);
					else if(Bluetooth.Type == BLUETOOTH_MASTER_ACCESS) xSemaphoreGive(User_Master_Access);
					else if(Bluetooth.Type == BLUETOOTH_USER_ADD) xSemaphoreGive(User_Add_Access);
					else if(Bluetooth.Type == BLUETOOTH_USER_REMOVE) xSemaphoreGive(User_Remove_Access);
					else if(Bluetooth.Type == BLUETOOTH_SIREN_ALARM) xSemaphoreGive(Siren_Alarm_Access);
					else if(Bluetooth.Type == BLUETOOTH_DOOR_LOCK) xSemaphoreGive(Actuator_Access);
					else if(Bluetooth.Type == BLUETOOTH_ROOM1_LIGHT) xSemaphoreGive(Actuator_Access);
					else if(Bluetooth.Type == BLUETOOTH_ROOM2_LIGHT) xSemaphoreGive(Actuator_Access);

					// Reset all Receiving Index Variables & Flags
					DataIdx = 0;
					PassFlag = 0;
					PassIdx = 0;
					ReceiveIdx = 0;

				}

			}

		}

		vTaskDelay(2);

	}

}

/* ==================================================================== */
