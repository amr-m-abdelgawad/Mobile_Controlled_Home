/* =======================================================================
 * 	os_tasks.h
 * 	Header File For OS Tasks.
 *  Created on: April 17, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef INCLUDES_OS_TASKS_H_
#define INCLUDES_OS_TASKS_H_

/* =======================================================================
 * 	OS Includes
 * ==================================================================== */

#include "main.h"
#include "task.h"
#include "semphr.h"
#include "frame.h"

/* ==================================================================== */





/* =======================================================================
 * 	APP Tasks Priorities
 * ==================================================================== */

#define MASTER_PASS		1234

/* ==================================================================== */





/* =======================================================================
 * 	APP Access Macros
 * ==================================================================== */

#define ACCEPT_ACCESS	1
#define REFUSE_ACCESS	0

/* ==================================================================== */





/* =======================================================================
 * 	APP Tasks Priorities
 * ==================================================================== */

#define SIREN_ALARM_PRIORITY		(3)
#define BLUETOOTH_RECEIVE_PRIORITY	(2)
#define MASTER_ACCESS_PRIORITY		(1)
#define USER_PRIORITY				(1)
#define ACTUATOR_CONTROL_PRIORITY	(1)

/* ==================================================================== */





/* =======================================================================
 * 	APP Tasks
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Bluetooth_Receive
 * 	@ Brief 	 - Receiving data from bluetooth task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Bluetooth_Receive(void*pvParameter);


/* =======================================================================
 * 	@ Func  	 - Master_Access
 * 	@ Brief 	 - Master Access to User Management task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Master_Access(void*pvParameter);


/* =======================================================================
 * 	@ Func  	 - User_Manage
 * 	@ Brief 	 - User Management task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void User_Manage(void*pvParameter);


/* =======================================================================
 * 	@ Func  	 - Siren_Alarm
 * 	@ Brief 	 - Control Siren Alarm task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Siren_Alarm(void*pvParameter);


/* =======================================================================
 * 	@ Func  	 - Actuator_Control
 * 	@ Brief 	 - Control Actuators task.
 * 	@ Param [in] - pvParameter: Pointer to task input parameters.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Actuator_Control(void*pvParameter);

/* ==================================================================== */





/* =======================================================================
 * 	APP OS Initialization
 * ==================================================================== */

void OS_Init(void);

/* ==================================================================== */

#endif /* INCLUDES_OS_TASKS_H_ */
