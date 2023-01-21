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
uint8 i = 0;
int main()
{
   PWM_Start();
   Clock_Start();
 

    while(1)
    {
        for(i = 0; i < 255; ++i)
        {
            PWM_WriteCompare(i);
            CyDelay(10);
        }
        for(i = 255; i > 0; --i)
        {
            PWM_WriteCompare(i);
            CyDelay(10);
        }
        
    }
    
}

/* [] END OF FILE */
