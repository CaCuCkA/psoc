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
#include <stdio.h>
#include <stdlib.h>
#define LED_ON  0
#define LED_OFF 1


void out7seg(uint16, uint8);

uint16 indyk[4] = {0x10FF,0x20FF,0x40FF,0x80FF};
const uint8 KOD7[10] = {0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};

CY_ISR(isr_100Hz)
{
    static uint8 N_indyk = 0u;
    
    SPIM_WriteTxData(indyk[N_indyk]);
    N_indyk++;
    N_indyk &= 3;    
}

void out7seg(uint16 data, uint8 point)
{
    uint8 i;
    for (i = 0; i < 4; i++)
    {
        indyk[i] &= 0xFF00;
        indyk[i] |= (uint16)KOD7[data % 10];  
        if (i == point){
            indyk[i]--;
        }
        data /= 10; 
        if (data == 0) break;
    }
    
    if(point == i + 1){
            indyk[point] &= 0xFF00;
            indyk[point] |= (uint16)KOD7[0] - 1;
            i++;
        }
    if(point == i + 2){
            indyk[point] &= 0xFF00;
            indyk[point] |= (uint16)KOD7[0] - 1;
            
            indyk[point-1] &= 0xFF00;
            indyk[point-1] |= (uint16)KOD7[0];
            
            i+=2;
            
        }
    if(point == i + 3){
            indyk[point] &= 0xFF00;
            indyk[point] |= (uint16)KOD7[0] - 1;
            
            indyk[point-1] &= 0xFF00;
            indyk[point-1] |= (uint16)KOD7[0];
            
            indyk[point-2] &= 0xFF00;
            indyk[point-2] |= (uint16)KOD7[0];
            i+=3;
            
        }

    for (i++; i < 4; i++)
    {
        indyk[i] |= 0x00FF;
    }
}

int main()
{
    uint8 ch;
    char array[5];
    uint8 counter;
    uint16 number;
    
    CyGlobalIntEnable;

    SPIM_Start();
    isr_100Hz_StartEx(isr_100Hz);
                    
    /* Start SCB UART TX+RX operation */    
    UART_Start(); 
    
    CyDelay(1000);
    
	UART_UartPutString("LAB 3.2 \r\n");
    
   for(;;)
    {
        counter = 0;
        uint8 i = 0, dot = 0,
            index = 0;
        while(1) {
            ch = UART_UartGetChar();
            if (!ch) {
                continue;
            }
            if(ch == '\r') {
                array[i] = '\0';
                break;
            }
            if(ch == '.'){
                index = 1;
                dot = i;
                continue;
            }
            if(counter != 4){
                array[(i++)] = ch;
                counter++;
            }
        }
        
        number = atoi(array);
        
        UART_UartPutChar(ch);
        
        if(index == 1){
            dot = i - dot; 
        }
        else{
            dot = 0;
        }
        
        out7seg(number,dot);
    }
}


/* [] END OF FILE */
