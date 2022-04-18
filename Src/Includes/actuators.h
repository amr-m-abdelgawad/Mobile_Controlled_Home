/* =======================================================================
 * 	actuators.h
 * 	Header File For Actuators.
 *  Created on: April 17, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef INCLUDES_ACTUATORS_H_
#define INCLUDES_ACTUATORS_H_

/* =======================================================================
 * 	Actuators APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - Actuators_Init
 * 	@ Brief 	 - Initialize Actuators according to the specified configuration.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Actuators_Init(void);


/* =======================================================================
 * 	@ Func  	 - SirenAlarm_On
 * 	@ Brief 	 - Turn On Siren Alarm.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void SirenAlarm_On(void);


/* =======================================================================
 * 	@ Func  	 - SirenAlarm_Off
 * 	@ Brief 	 - Turn Off Siren Alarm.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void SirenAlarm_Off(void);


/* =======================================================================
 * 	@ Func  	 - DoorLock_On
 * 	@ Brief 	 - Turn On Door Lock.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void DoorLock_On(void);


/* =======================================================================
 * 	@ Func  	 - DoorLock_Off
 * 	@ Brief 	 - Turn Off Door Lock.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void DoorLock_Off(void);


/* =======================================================================
 * 	@ Func  	 - Room1Light_On
 * 	@ Brief 	 - Turn On Room 1 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room1Light_On(void);


/* =======================================================================
 * 	@ Func  	 - Room1Light_Off
 * 	@ Brief 	 - Turn Off Room 1 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room1Light_Off(void);


/* =======================================================================
 * 	@ Func  	 - Room2Light_On
 * 	@ Brief 	 - Turn On Room 2 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room2Light_On(void);


/* =======================================================================
 * 	@ Func  	 - Room2Light_Off
 * 	@ Brief 	 - Turn Off Room 2 Light.
 * 	@ RetVal	 - None.
 * ==================================================================== */
void Room2Light_Off(void);

/* ==================================================================== */

#endif /* INCLUDES_ACTUATORS_H_ */
