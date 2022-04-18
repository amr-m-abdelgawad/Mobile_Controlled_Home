/* =======================================================================
 * 	STDTypes.h
 * 	Macros For Standard Data Types
 *  Created on: Dec 9, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef MCAL_INCLUDES_STD_TYPES_H_
#define MCAL_INCLUDES_STD_TYPES_H_

/*-------- Standard Data Types --------*/
typedef unsigned char		uint8;
typedef unsigned short int	uint16;
typedef unsigned long int	uint32;
typedef signed char			sint8;
typedef signed short int	sint16;
typedef signed long int		sint32;
typedef float				float32;
typedef double				float64;


/*---------- Null Definition ----------*/
#ifndef NULL
  #define NULL 0
#endif


/*------------ Return Type ------------*/
typedef uint8				Std_Return;


/*----------- Register Type -----------*/
typedef uint8				Register_Type;


/*----------- Return Values -----------*/
enum {
	OK,
	UNKNOWN,
	INVALID_PORT,
	WRONG_PIN,
	INVALID_LED,
	UART_FRAME_ERROR,
	UART_DATA_OVER_RUN,
	UART_PARITY_ERROR,
	INVALID_RELAY
} Std_RetCode;

#endif /* MCAL_INCLUDES_STD_TYPES_H_ */
