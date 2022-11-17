/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA2 aliases
#define channel_SHT_TRIS                 TRISAbits.TRISA2
#define channel_SHT_LAT                  LATAbits.LATA2
#define channel_SHT_PORT                 PORTAbits.RA2
#define channel_SHT_WPU                  WPUAbits.WPUA2
#define channel_SHT_OD                   ODCONAbits.ODCA2
#define channel_SHT_ANS                  ANSELAbits.ANSA2
#define channel_SHT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_SHT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_SHT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_SHT_GetValue()           PORTAbits.RA2
#define channel_SHT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_SHT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_SHT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define channel_SHT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define channel_SHT_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define channel_SHT_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define channel_SHT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define channel_SHT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_RA5 aliases
#define sht_RST_TRIS                 TRISAbits.TRISA5
#define sht_RST_LAT                  LATAbits.LATA5
#define sht_RST_PORT                 PORTAbits.RA5
#define sht_RST_WPU                  WPUAbits.WPUA5
#define sht_RST_OD                   ODCONAbits.ODCA5
#define sht_RST_ANS                  ANSELAbits.ANSA5
#define sht_RST_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define sht_RST_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define sht_RST_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define sht_RST_GetValue()           PORTAbits.RA5
#define sht_RST_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define sht_RST_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define sht_RST_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define sht_RST_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define sht_RST_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define sht_RST_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define sht_RST_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define sht_RST_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_RC3 aliases
#define MA420T_nCS_TRIS                 TRISCbits.TRISC3
#define MA420T_nCS_LAT                  LATCbits.LATC3
#define MA420T_nCS_PORT                 PORTCbits.RC3
#define MA420T_nCS_WPU                  WPUCbits.WPUC3
#define MA420T_nCS_OD                   ODCONCbits.ODCC3
#define MA420T_nCS_ANS                  ANSELCbits.ANSC3
#define MA420T_nCS_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define MA420T_nCS_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define MA420T_nCS_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define MA420T_nCS_GetValue()           PORTCbits.RC3
#define MA420T_nCS_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define MA420T_nCS_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define MA420T_nCS_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define MA420T_nCS_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define MA420T_nCS_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define MA420T_nCS_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define MA420T_nCS_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define MA420T_nCS_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.WPUC6
#define IO_RC6_OD                   ODCONCbits.ODCC6
#define IO_RC6_ANS                  ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define sht_SEL_TRIS                 TRISCbits.TRISC7
#define sht_SEL_LAT                  LATCbits.LATC7
#define sht_SEL_PORT                 PORTCbits.RC7
#define sht_SEL_WPU                  WPUCbits.WPUC7
#define sht_SEL_OD                   ODCONCbits.ODCC7
#define sht_SEL_ANS                  ANSELCbits.ANSC7
#define sht_SEL_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define sht_SEL_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define sht_SEL_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define sht_SEL_GetValue()           PORTCbits.RC7
#define sht_SEL_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define sht_SEL_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define sht_SEL_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define sht_SEL_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define sht_SEL_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define sht_SEL_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define sht_SEL_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define sht_SEL_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/