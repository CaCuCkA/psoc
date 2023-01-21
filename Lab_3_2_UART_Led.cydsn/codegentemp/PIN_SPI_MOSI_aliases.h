/*******************************************************************************
* File Name: PIN_SPI_MOSI.h  
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

#if !defined(CY_PINS_PIN_SPI_MOSI_ALIASES_H) /* Pins PIN_SPI_MOSI_ALIASES_H */
#define CY_PINS_PIN_SPI_MOSI_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PIN_SPI_MOSI_0			(PIN_SPI_MOSI__0__PC)
#define PIN_SPI_MOSI_0_PS		(PIN_SPI_MOSI__0__PS)
#define PIN_SPI_MOSI_0_PC		(PIN_SPI_MOSI__0__PC)
#define PIN_SPI_MOSI_0_DR		(PIN_SPI_MOSI__0__DR)
#define PIN_SPI_MOSI_0_SHIFT	(PIN_SPI_MOSI__0__SHIFT)
#define PIN_SPI_MOSI_0_INTR	((uint16)((uint16)0x0003u << (PIN_SPI_MOSI__0__SHIFT*2u)))

#define PIN_SPI_MOSI_INTR_ALL	 ((uint16)(PIN_SPI_MOSI_0_INTR))


#endif /* End Pins PIN_SPI_MOSI_ALIASES_H */


/* [] END OF FILE */
