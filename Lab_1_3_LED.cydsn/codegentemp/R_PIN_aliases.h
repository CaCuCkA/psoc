/*******************************************************************************
* File Name: R_PIN.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_R_PIN_ALIASES_H) /* Pins R_PIN_ALIASES_H */
#define CY_PINS_R_PIN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define R_PIN_0			(R_PIN__0__PC)
#define R_PIN_0_PS		(R_PIN__0__PS)
#define R_PIN_0_PC		(R_PIN__0__PC)
#define R_PIN_0_DR		(R_PIN__0__DR)
#define R_PIN_0_SHIFT	(R_PIN__0__SHIFT)
#define R_PIN_0_INTR	((uint16)((uint16)0x0003u << (R_PIN__0__SHIFT*2u)))

#define R_PIN_INTR_ALL	 ((uint16)(R_PIN_0_INTR))


#endif /* End Pins R_PIN_ALIASES_H */


/* [] END OF FILE */
