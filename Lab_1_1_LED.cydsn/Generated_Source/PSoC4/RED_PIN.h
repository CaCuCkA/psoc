/*******************************************************************************
* File Name: RED_PIN.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RED_PIN_H) /* Pins RED_PIN_H */
#define CY_PINS_RED_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RED_PIN_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} RED_PIN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   RED_PIN_Read(void);
void    RED_PIN_Write(uint8 value);
uint8   RED_PIN_ReadDataReg(void);
#if defined(RED_PIN__PC) || (CY_PSOC4_4200L) 
    void    RED_PIN_SetDriveMode(uint8 mode);
#endif
void    RED_PIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   RED_PIN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void RED_PIN_Sleep(void); 
void RED_PIN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(RED_PIN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define RED_PIN_DRIVE_MODE_BITS        (3)
    #define RED_PIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RED_PIN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the RED_PIN_SetDriveMode() function.
         *  @{
         */
        #define RED_PIN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define RED_PIN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define RED_PIN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define RED_PIN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define RED_PIN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define RED_PIN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define RED_PIN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define RED_PIN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define RED_PIN_MASK               RED_PIN__MASK
#define RED_PIN_SHIFT              RED_PIN__SHIFT
#define RED_PIN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RED_PIN_SetInterruptMode() function.
     *  @{
     */
        #define RED_PIN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define RED_PIN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define RED_PIN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define RED_PIN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(RED_PIN__SIO)
    #define RED_PIN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(RED_PIN__PC) && (CY_PSOC4_4200L)
    #define RED_PIN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define RED_PIN_USBIO_DISABLE              ((uint32)(~RED_PIN_USBIO_ENABLE))
    #define RED_PIN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define RED_PIN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define RED_PIN_USBIO_ENTER_SLEEP          ((uint32)((1u << RED_PIN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << RED_PIN_USBIO_SUSPEND_DEL_SHIFT)))
    #define RED_PIN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << RED_PIN_USBIO_SUSPEND_SHIFT)))
    #define RED_PIN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << RED_PIN_USBIO_SUSPEND_DEL_SHIFT)))
    #define RED_PIN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(RED_PIN__PC)
    /* Port Configuration */
    #define RED_PIN_PC                 (* (reg32 *) RED_PIN__PC)
#endif
/* Pin State */
#define RED_PIN_PS                     (* (reg32 *) RED_PIN__PS)
/* Data Register */
#define RED_PIN_DR                     (* (reg32 *) RED_PIN__DR)
/* Input Buffer Disable Override */
#define RED_PIN_INP_DIS                (* (reg32 *) RED_PIN__PC2)

/* Interrupt configuration Registers */
#define RED_PIN_INTCFG                 (* (reg32 *) RED_PIN__INTCFG)
#define RED_PIN_INTSTAT                (* (reg32 *) RED_PIN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define RED_PIN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(RED_PIN__SIO)
    #define RED_PIN_SIO_REG            (* (reg32 *) RED_PIN__SIO)
#endif /* (RED_PIN__SIO_CFG) */

/* USBIO registers */
#if !defined(RED_PIN__PC) && (CY_PSOC4_4200L)
    #define RED_PIN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define RED_PIN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define RED_PIN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define RED_PIN_DRIVE_MODE_SHIFT       (0x00u)
#define RED_PIN_DRIVE_MODE_MASK        (0x07u << RED_PIN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins RED_PIN_H */


/* [] END OF FILE */
