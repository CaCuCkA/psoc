/*******************************************************************************
* File Name: GREEN_PIN.h  
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

#if !defined(CY_PINS_GREEN_PIN_ALIASES_H) /* Pins GREEN_PIN_ALIASES_H */
#define CY_PINS_GREEN_PIN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define GREEN_PIN_0			(GREEN_PIN__0__PC)
#define GREEN_PIN_0_PS		(GREEN_PIN__0__PS)
#define GREEN_PIN_0_PC		(GREEN_PIN__0__PC)
#define GREEN_PIN_0_DR		(GREEN_PIN__0__DR)
#define GREEN_PIN_0_SHIFT	(GREEN_PIN__0__SHIFT)
#define GREEN_PIN_0_INTR	((uint16)((uint16)0x0003u << (GREEN_PIN__0__SHIFT*2u)))

#define GREEN_PIN_INTR_ALL	 ((uint16)(GREEN_PIN_0_INTR))
#define GREEN_PIN_LED1			(GREEN_PIN__LED1__PC)
#define GREEN_PIN_LED1_PS		(GREEN_PIN__LED1__PS)
#define GREEN_PIN_LED1_PC		(GREEN_PIN__LED1__PC)
#define GREEN_PIN_LED1_DR		(GREEN_PIN__LED1__DR)
#define GREEN_PIN_LED1_SHIFT	(GREEN_PIN__LED1__SHIFT)
#define GREEN_PIN_LED1_INTR	((uint16)((uint16)0x0003u << (GREEN_PIN__0__SHIFT*2u)))


#endif /* End Pins GREEN_PIN_ALIASES_H */


/* [] END OF FILE */
