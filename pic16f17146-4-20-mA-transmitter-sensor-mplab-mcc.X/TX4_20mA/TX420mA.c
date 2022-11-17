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

#include "TX420mA.h"
#include "../mcc_generated_files/spi/mssp1.h"
#include "../mcc_generated_files/spi/spi_interface.h"
#include "../mcc_generated_files/system/pins.h"

// control register values
#define CTRL_DACA	0x00
#define CTRL_UNBUFFERED	0x00
#define CTRL_BUFFERED	0x40
#define CTRL_GAIN_1X	0x20
#define CTRL_GAIN_2X	0x00
#define CTRL_ENABLED	0x10
#define CTRL_DISABLED	0x00

void TX420mA_Set(uint16_t value)
{
    uint8_t ctrl_byte = CTRL_DACA | CTRL_UNBUFFERED | CTRL_GAIN_1X | CTRL_ENABLED;
	
    SPI1.Open(MSSP1_DEFAULT);
    MA420T_nCS_SetLow(); 

    SPI1.ByteExchange(((uint8_t)(value >> 8) & 0x0F) | (ctrl_byte & 0xF0));
    SPI1.ByteExchange((uint8_t) (value & 0x00FF));

    MA420T_nCS_SetHigh(); 
    SPI1_Close();
}