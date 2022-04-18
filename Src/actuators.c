/* =======================================================================
 * 	actuators.c
 * 	Source Code For Actuators.
 *  Created on: April 16, 2022
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	Actuators Includes
 * ==================================================================== */

#include "Atmega32_HAL_Relay.h"

/* ==================================================================== */




/* =======================================================================
 * 	Actuators Relays
 * ==================================================================== */

Relay_Type Siren_Alarm_Relay = {Port_A, Pin0};
Relay_Type Door_Lock_Relay = {Port_A, Pin1};
Relay_Type Room1_Light_Relay = {Port_A, Pin2};
Relay_Type Room2_Light_Relay = {Port_A, Pin3};

/* ==================================================================== */





/* =======================================================================
 * 	Actuators APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Actuators_Init
 * 	@ Brief 	 - Initialize Actuators according to the specified configuration.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Actuators_Init(void) {

	// Initialize Siren Alarm Relay
	HAL_Relay_Init(Siren_Alarm_Relay);

	// Initialize Door Lock Relay
	HAL_Relay_Init(Door_Lock_Relay);

	// Initialize Room 1 Light Relay
	HAL_Relay_Init(Room1_Light_Relay);

	// Initialize Room 2 Light Relay
	HAL_Relay_Init(Room2_Light_Relay);

}


/* =======================================================================
 * 	@ Func  	 - SirenAlarm_On
 * 	@ Brief 	 - Turn On Siren Alarm.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void SirenAlarm_On(void) { HAL_Relay_On(Siren_Alarm_Relay); }


/* =======================================================================
 * 	@ Func  	 - SirenAlarm_Off
 * 	@ Brief 	 - Turn Off Siren Alarm.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void SirenAlarm_Off(void) { HAL_Relay_Off(Siren_Alarm_Relay); }


/* =======================================================================
 * 	@ Func  	 - DoorLock_On
 * 	@ Brief 	 - Turn On Door Lock.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void DoorLock_On(void) { HAL_Relay_On(Door_Lock_Relay); }


/* =======================================================================
 * 	@ Func  	 - DoorLock_Off
 * 	@ Brief 	 - Turn Off Door Lock.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void DoorLock_Off(void) { HAL_Relay_Off(Door_Lock_Relay); }


/* =======================================================================
 * 	@ Func  	 - Room1Light_On
 * 	@ Brief 	 - Turn On Room 1 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room1Light_On(void) { HAL_Relay_On(Room1_Light_Relay); }


/* =======================================================================
 * 	@ Func  	 - Room1Light_Off
 * 	@ Brief 	 - Turn Off Room 1 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room1Light_Off(void) { HAL_Relay_Off(Room1_Light_Relay); }


/* =======================================================================
 * 	@ Func  	 - Room2Light_On
 * 	@ Brief 	 - Turn On Room 2 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room2Light_On(void) { HAL_Relay_On(Room2_Light_Relay); }


/* =======================================================================
 * 	@ Func  	 - Room2Light_Off
 * 	@ Brief 	 - Turn Off Room 2 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room2Light_Off(void) { HAL_Relay_Off(Room2_Light_Relay); }

/* ==================================================================== */
