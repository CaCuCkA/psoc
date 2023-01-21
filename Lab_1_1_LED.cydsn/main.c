/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable;
    
    LED_B_Write(1);
    LED_R_Write(1);
    
	for(;;)
    {
        
        LED_B_Write(1);
        LED_R_Write(0);
        CyDelay(1000);
        
        LED_R_Write(1);
        LED_B_Write(0);
        CyDelay(1000);
    }
}


