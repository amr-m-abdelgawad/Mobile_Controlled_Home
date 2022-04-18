/* =======================================================================
 * 	Macros.h
 * 	Main Macro functions
 *  Created on: Dec 9, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */

#ifndef MCAL_INCLUDES_MACROS_H_
#define MCAL_INCLUDES_MACROS_H_

/*-------- Setting Specific Bit Macro ---------*/
#define SET_BIT(var,bit)	var|=(1<<bit)

/*-------- Clearing Specific Bit Macro --------*/
#define CLR_BIT(var,bit)	var&=~((1<<bit))

/*-------- Toggling Specific Bit Macro --------*/
#define TOGGLE_BIT(var,bit)	var^=(1<<bit)

/*---------- Get Specific Bit Macro -----------*/
#define GET_BIT(var,bit)	(1&(var>>bit))

#endif /* MCAL_INCLUDES_MACROS_H_ */
