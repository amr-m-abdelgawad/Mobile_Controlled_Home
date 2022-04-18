/* =======================================================================
 * 	Atmega32_MCAL_DIO.h
 * 	DIO Driver Header For Atmega32
 *  Created on: Dec 9, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

/* =======================================================================
 * 	DIO Driver Includes
 * ==================================================================== */

#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	DIO Driver Data Types
 * ==================================================================== */

/*-------- Port Type Structure --------*/
typedef struct{
	uint8 Port;
	uint8 Direction;
} DIO_PortType;


/*--------- Pin Type Structure ---------*/
typedef struct{
	uint8 Port;
	uint8 Pin_Number;
	uint8 Direction;
} DIO_PinType;


/*-------- DIO Status Structure -------*/
typedef uint8 DIO_StatusType;

/* ==================================================================== */





/* =======================================================================
 * 	DIO Driver Macros
 * ==================================================================== */

/*---------- DIO Ports Macros --------*/
#define Port_A		0
#define Port_B		1
#define Port_C		2
#define Port_D		3


/*----------- DIO Pins Macros --------*/
#define Pin0		0
#define Pin1		1
#define Pin2		2
#define Pin3		3
#define Pin4		4
#define Pin5		5
#define Pin6		6
#define Pin7		7


/*------- DIO Direction Macros -------*/
#define DIO_Output	1
#define DIO_Input	0


/*--------- DIO Status Macros --------*/
#define DIO_Reset	0
#define DIO_Set		1
#define DIO_PullUp	1

/* ==================================================================== */





/* =======================================================================
 * 	DIO Driver Registers
 * ==================================================================== */

/*--------- DIO DDR Register ---------*/
#define DDRA *((volatile uint8*)0x3A)
#define DDRB *((volatile uint8*)0x37)
#define DDRC *((volatile uint8*)0x34)
#define DDRD *((volatile uint8*)0x31)


/*--------- DIO PORT Register --------*/
#define PORTA *((volatile uint8*)0x3B)
#define PORTB *((volatile uint8*)0x38)
#define PORTC *((volatile uint8*)0x35)
#define PORTD *((volatile uint8*)0x32)


/*--------- DIO PIN Register ---------*/
#define PINA *((volatile uint8*)0x39)
#define PINB *((volatile uint8*)0x36)
#define PINC *((volatile uint8*)0x33)
#define PIND *((volatile uint8*)0x30)

/* ==================================================================== */





/* =======================================================================
 * 	DIO Driver APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_SetPortDirection
 * 	@ Brief 	 - Sets port direction as input or output.
 * 	@ Param [in] - DIO_Port: Port which is needed to be set.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_SetPortDirection(DIO_PortType DIO_Port);


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_SetPinDirection
 * 	@ Brief 	 - Sets specific pin direction as input or output.
 * 	@ Param [in] - DIO_Pin: Pin which is needed to be set.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_SetPinDirection(DIO_PinType DIO_Pin);


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_WritePort
 * 	@ Brief 	 - Writes port status to set, reset or pull up.
 * 	@ Param [in] - DIO_Port: Port which is needed to be write.
 * 	@ Param [in] - DIO_PortStatus: Port status which is needed to be written.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid
 *	  			   return "UNKNOWN"	when there's unknown error
 * ==================================================================== */
Std_Return MCAL_DIO_WritePort(DIO_PortType DIO_Port, DIO_StatusType DIO_PortStatus);


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_WritePin
 * 	@ Brief 	 - Writes specific pin status to set, reset or pull up.
 * 	@ Param [in] - DIO_Pin: Pin which is needed to be set.
 * 	@ Param [in] - DIO_PinStatus: Pin status which is needed to be written.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_WritePin(DIO_PinType DIO_Pin, DIO_StatusType DIO_PinStatus);


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_GetPort
 * 	@ Brief 	 - Gets port status.
 * 	@ Param [in] - DIO_Port: Port which is needed to be read.
 * 	@ Param [in] - DIO_PortStatusBuf: Port status reading buffer.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid
 *	  			   return "UNKNOWN"	when there's unknown error
 * ==================================================================== */
Std_Return MCAL_DIO_GetPort(DIO_PortType DIO_Port, DIO_StatusType *DIO_PortStatusBuf);


/* =======================================================================
 * 	@ Func  	 - MCAL_DIO_GetPin
 * 	@ Brief 	 - Gets pin status.
 * 	@ Param [in] - DIO_Pin: Pin which is needed to be read.
 * 	@ Param [in] - DIO_PinStatusBuf: Pin status reading buffer.
 * 	@ RetVal	 - Std_Return.
 *	  Note		 - This API return "OK" when no error occurred,
 *	  			   return "INVALID_PORT" when the entered port is not valid,
 *	  			   return "WRONG_PIN" when the entered pin is not valid,
 *	  			   return "UNKNOWN"	when there's unknown error.
 * ==================================================================== */
Std_Return MCAL_DIO_GetPin(DIO_PinType DIO_Pin, DIO_StatusType *DIO_PinStatusBuf);

/* ==================================================================== */

#endif /* MCAL_DIO_INCLUDES_DIO_INTERFACE_H_ */
