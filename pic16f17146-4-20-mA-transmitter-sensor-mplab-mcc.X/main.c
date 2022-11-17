 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

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

#include "mcc_generated_files/system/system.h"
#include "sht/sht.h"
#include "TX4_20mA/TX420mA.h"

#define TEMP_MAX                        (100.0F)   //temperature in C corresponding to 20mA
#define TEMP_MIN                        (0.0F)     //temperature in C corresponding to 4mA
#define DAC_COUNT_20mA                  (4015U)    //dac value for 20mA of current
#define DAC_COUNT_4mA                   (810U)     //dac value for 4mA of current
#define TEMP_DIFFERENCE                 (TEMP_MAX - TEMP_MIN)
#define DAC_COUNT_DIFFERENCE_4_20_mA    (DAC_COUNT_20mA - DAC_COUNT_4mA) 
#define DAC_MAX_COUNT                   (4095U)
#define DAC_MIN_COUNT                   (0U)

uint16_t ConvertTemptoDACCount(float temperature);

/*
    Main application
*/
#ifndef CALIBRATION
int main(void)
{
    uint16_t TX4_20mA_dacCount = 0;
    float SHT_temperatureReading = 0;
    
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    printf("\n\t\t**** 4-20 mA Transmitter ****\n\n\r");
           
    SHT_Reset();
       
    while (1) 
    {
        //read temperature from sensor
        SHT_temperatureReading = SHT_GetTemperature();
        printf("Temperature : %.1f C\r\n",SHT_temperatureReading);
        
        //convert temp into equivalent DAC count
        TX4_20mA_dacCount = ConvertTemptoDACCount(SHT_temperatureReading);

        //set current in the 4 to 20 mA range
        TX420mA_Set(TX4_20mA_dacCount);
        printf("Setting 4-20 mA T click DAC value to %u\n\n\r", TX4_20mA_dacCount);
            
        //delay is added to stop continuous operation. User can remove or modify delay according to application needs
        __delay_ms(2000);
    }    
}
#endif

/**
 * @brief This function converts measured temperature into DAC count to set equivalent 
        current between 4mA and 20mA. DAC is present on 4-20 mA T click.
 * @param temperature - measured temperature in degree C
 * @return equivalent current between 4mA and 20mA
*/
uint16_t ConvertTemptoDACCount(float temperature)
{
    float dacCount;
    
    dacCount = (float)DAC_COUNT_DIFFERENCE_4_20_mA/TEMP_DIFFERENCE;
    dacCount = (float)(dacCount * (temperature - TEMP_MIN));
    dacCount = dacCount + DAC_COUNT_4mA;
    
    //limit DAC value between 0 and 4095  
    dacCount = ((dacCount > DAC_MAX_COUNT ) ? (DAC_MAX_COUNT) : (dacCount));
    dacCount = ((dacCount < DAC_MIN_COUNT ) ? (DAC_MIN_COUNT) : (dacCount));
    
    return (uint16_t)dacCount;  
}

/**
 End of File
*/
