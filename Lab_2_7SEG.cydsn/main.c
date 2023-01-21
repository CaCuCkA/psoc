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
#include "project.h"
#include <stdlib.h>
#include <math.h>

void out7seg(uint16, uint8, uint8);

uint16 indyk[4] = {0x10FF,0x20FF,0x40FF,0x80FF};
const uint8 KOD7[10] = {0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};
const uint8 SIGN = 0xFD;
const uint8 DOT = 0x7F;

CY_ISR(isr_100Hz)
{
    static uint8 N_indyk = 0u;
    
    SPIM_WriteTxData(indyk[N_indyk]);
    
    N_indyk++;
    N_indyk &= 3;    
}

void out7seg(uint16 data, uint8 flag, uint8 position)
{
    uint8 i;
    uint8 zero = data < pow(10, position) ? 1 : 0;
    
    for (i = 0; i < 4; i++)
    {
        uint8 sign = 0xFF;
        indyk[i] &= 0xFF00;
        if(position && i == position) sign = 0xFE;
        indyk[i] |= (uint16) (KOD7[data % 10] & sign);
        if(zero) 
        {
            while(i < position - 1)
            {
                indyk[++i] &= 0xFF00;
                indyk[i] |= 0x02;
            }
             indyk[++i] &= 0xFF00;
             indyk[i] |= 0x02 & 0xFE;
        }
        data /= 10;
        if (data == 0) break;
    }
    
    if(flag) 
    {
        indyk[++i] &= 0xFF00;
        indyk[i] |= SIGN;
    }
    
    
    for (i++; i < 4; i++)
    {
        indyk[i] |= 0x00FF;
    }
}

uint16 count_tail(float x)
{
    uint16 count =0;
    while(x!=((int)x))
    {
        count++;
        x*=10;
    }
    return count;
}

int main(void)
{
    float counter = -9;
    float value = 0.6;
    uint16 position = count_tail(value);
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    SPIM_Start();
    isr_100Hz_StartEx(isr_100Hz);

    for(;;)
    {
        counter += value;
        if (counter < -999)
        {
            counter = 0;
        }
        int flag = counter < 0 ? 1:0;
        out7seg(abs(counter * pow(10, position)), flag, position);
        if(PIN_SW2_Read() == 0) 
        {
           counter = 0;
           out7seg(counter, 0, position);
        }
        CyDelay(300);
        
        if (Pin_B1_Read() == 0)
        {
            CyDelay(700);
        }
    }
}

/* [] END OF FILE */
