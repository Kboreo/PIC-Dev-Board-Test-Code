/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - pic24-dspic-pic32mm : v1.35
        Device            :  PIC24FJ128GA204
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.31
        MPLAB             :  MPLAB X 3.60
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#define DELAY 16000  //Timer1 Delay
//#define DELAY 31250    //Alt timer delay (hopefully 1 second, need to check)

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    T1CON = 0x8030; // 0b10000000_00110000 TMR1 on, prescaler 1:256 Tclk/2
    
    
    while (1)
    {
        // Add your application code
        
        
        int x = BUTTON_RC8_GetValue();
        int y = BUTTON_RC9_GetValue();
        int z = x+y;
        
        if(z == 0)
        {
            IO_RED_SetHigh();
            TMR1 = 0;
            while(TMR1 < DELAY)
            {
            
            }
        
            IO_RED_SetLow();
            TMR1 = 0;
            while(TMR1 < DELAY)
            {
                
            }
        }       
       
        else
        {
            if(BUTTON_RC9_GetValue() == 0)
            {
                LED_BLUE_SetHigh();
                TMR1 = 0;
                while(TMR1 < DELAY)
                {
            
                }   
        
                LED_BLUE_SetLow();
                TMR1 = 0;
                while(TMR1 < DELAY)
                {
            
                }
            }
        
            if(BUTTON_RC8_GetValue() == 0)
            {
                LED_GREEN_SetHigh();
                TMR1 = 0;
                while(TMR1 < DELAY)
                {
            
                }
        
                LED_GREEN_SetLow();
                TMR1 = 0;
                while(TMR1 < DELAY)
                {
            
                }
            }      
        }
    }

    return -1;
}

/**
 End of File
*/