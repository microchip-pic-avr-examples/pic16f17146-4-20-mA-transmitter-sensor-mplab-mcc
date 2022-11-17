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

#include "sht.h"
#include "../mcc_generated_files/system/pins.h"
#include "../mcc_generated_files/adcc/adcc.h"
#include "../mcc_generated_files/system/clock.h"

#define VDD                     (3.3F)
#define ADC_MAX_COUNT           (4095U)
#define ADC_REFERENCE_VOLTAGE   (3.3F)
#define ADC_STEP_SIZE           (ADC_REFERENCE_VOLTAGE / ADC_MAX_COUNT)

float SHT_GetTemperature(void)
{
    float temperature = 0.0F;
    float equivalentVoltage = 0.0F;
    adc_result_t adcReading = 0;
    
    sht_SEL_SetLow(); //select temperature sensor
    
    ADCC_StartConversion(channel_SHT);
    
    while(!ADCC_IsConversionDone());
    
    adcReading =  ADCC_GetFilterValue();
    
    equivalentVoltage = adcReading * ADC_STEP_SIZE; 
    temperature = -66.875F + 218.75F * equivalentVoltage / VDD;  //conversion formula for temperature in C (refer sensor data sheet)
    
    return temperature;
}

float SHT_GetHumidity(void)
{
    float humidity = 0;
    float equivalentVoltage = 0;
    adc_result_t adcReading = 0;
    
    sht_SEL_SetHigh(); //select humidity sensor 
    
    adcReading =  ADCC_GetSingleConversion(channel_SHT);
    
    equivalentVoltage = adcReading * ADC_STEP_SIZE; 
    humidity = - 12.5F + 125U * equivalentVoltage / VDD;  //conversion formula for humidity (refer sensor data sheet)
    
    return humidity;
}

void SHT_Reset(void)
{
    sht_RST_SetLow();   
    __delay_us(1);
    sht_RST_SetHigh();;  
}