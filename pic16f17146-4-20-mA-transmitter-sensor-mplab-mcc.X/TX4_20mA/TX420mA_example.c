/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <stdio.h>
#include <stdint.h>
#include "TX420mA.h"
#include "../mcc_generated_files/system/clock.h"

#define DAC_REFERENCE_VOLTAGE   (3.3F)
#define DAC_MAX_COUNT           (4095U)
#define DAC_STEP_SIZE           (DAC_REFERENCE_VOLTAGE / DAC_MAX_COUNT)

void TX420mA_Example(void)
{
    float voltage = 0.0F;
    
    uint16_t dacVoltage;
    
    printf("Ramping voltage UP");
    while(voltage < 3.0F)
    {
        dacVoltage = (uint16_t) (voltage / DAC_STEP_SIZE);
        TX420mA_Set(dacVoltage);
        __delay_ms(100);
        voltage += 0.5F;
    }

    printf("Ramping voltage DOWN\r\n");
    while(voltage > 0.0F)
    {
        dacVoltage = (uint16_t) (voltage / DAC_STEP_SIZE);
        TX420mA_Set(dacVoltage);
        __delay_ms(100);
        voltage -= 0.5F;
    }
}

