/* =======================================================================
 * 	Atmega32_MCAL_GIE.c
 * 	Global Interrupt Driver APIs For Atmega32
 *  Created on: Dec 25, 2021
 *  Author: Amr Mohamed Abdel-Gawad Mousa
 *  https://github.com/amr-m-abdelgawad/
 * ==================================================================== */


/* =======================================================================
 * 	GIE Driver Includes
 * ==================================================================== */

#include "Atmega32_MCAL_GIE.h"
#include "Macros.h"
#include "Std_Types.h"

/* ==================================================================== */





/* =======================================================================
 * 	GIE Driver APIs
 * ==================================================================== */

/* =======================================================================
 * 	@ Func  	 - MCAL_GIE_Enable
 * 	@ Brief 	 - Enables Global Interrupt
 * 	@ RetVal	 - None.
 * ==================================================================== */
void MCAL_GIE_Enable(void){

	/*---- Enable Global Interrupt ----*/
	SET_BIT(SREG,SREG_I);

}


/* =======================================================================
 * 	@ Func  	 - MCAL_GIE_Disable
 * 	@ Brief 	 - Disables Global Interrupt
 * 	@ RetVal	 - None.
 * ==================================================================== */
void MCAL_GIE_Disable(void){

	/*---- Disable Global Interrupt ----*/
	CLR_BIT(SREG,SREG_I);

}

/* ==================================================================== */
