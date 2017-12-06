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
//#define DELAY 16000  //Timer1 Delay
#define DELAY 19760    //Alt timer delay (hopefully 1.235 ms, need to check)

void testFunction(void);
void buttonLedFunction(void);
void interruptTimerTest(void);
void __attribute__((__interrupt__, __auto_psv__)) _T1Interrupt(void);
void interruptBookTest(void);
void tmr2Test(void);


int dSec = 0;
int Sec = 0;
int Min = 0;

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //T1CON = 0x8030; // 0b10000000_00110000 TMR1 on, prescaler 1:256 Tclk/2
    //T1CON = 0x8000; // 0b10000000_00000000 TMR1 on, prescaler 1:1 Tclk/2
    //T1CON = 0x8020; // 0b10000000_00000000 TMR1 on, prescaler 1:64 Tclk/2
    
    //interruptBookTest();
    tmr2Test();
   
    while (1)
    {
        
    }

    return -1;
    
}


void testFunction(void)
{
    while(1)
    {
        
    LED_GREEN_SetHigh();
    _LATB9 = 1;
    TMR1 = 0;
    while(TMR1 < DELAY)
    {
        
    }
    
    LED_GREEN_SetLow();
    _LATB9 = 0;
    TMR1 = 0;
    while(TMR1 < DELAY)
    {
                
    }
    }
}

void buttonLedFunction(void)
{       
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

void interruptTimerTest(void)
{
    _T1IP = 4; // this is the default value anyway
    TMR1 = 0; // clear the timer
    PR1 = 0x4D2F; // set the period register, 25,000 * 64 * 1 cycle (62.5ns) = 0.1 s
    T1CON = 0x8000; // enabled, prescaler 1:64, internal clock 
    
    // 2.2 init the Timer 1 Interrupt, clear the flag, enable the source
    _T1IF = 0;
    _T1IE = 1;
    
    
    
}

void __attribute__((__interrupt__, __auto_psv__)) _T1Interrupt(void)  
{
// // 1.1 your code here
// dSec++; // increment the tens of a second counter
// if ( dSec > 9) // 10 tens in a second
// {
// dSec = 0;
// Sec++; // increment the minute counter
//
// if ( Sec > 59) // 60 seconds make a minute
// {
// Sec = 0;
//
// // 1.2 increment the minute counter
// Min++;
// if ( Min > 59)// 59 minutes in an hour
// Min = 0;
// } // minutes
// } // seconds
// // 1.3 clear the interrupt flag
 _LATB9 = !_LATB9;
 _LATC7 = !_LATC7;
 _T1IF = 0;
}

void interruptBookTest(void)
{
    // 2. init Timer 1, T1ON, 1:1 prescaler, internal clock source
 _T1IP = 1; // this is the default value anyway
 TMR1 = 0; // clear the timer
 PR1 = 19760-1; // set the period register
 //TRISA = 0xff00; // set PORTA lsb as output
 // 2.1 configure Timer1 module
 T1CON = 0x8000; // enabled, prescaler 1:1, internal clock
 // 2.2 init the Timer 1 Interrupt, clear the flag, enable the source
 _T1IF = 0;
 _T1IE = 1;
 // 2.3 init the processor priority level
 
 // 3. main loop
 _LATB9 = 1;
 _LATC7 = 0;
 while(1)
 {
 // your main code here
 

 } // main loop
}


tmr2Test(void)
{
    _T2IP = 2;
    PR2 = 0x13880-1;
    T2CON =0x0;
    TMR2 = 0;       //Clear timer 2
    
    while(1)
    {
        
    }
}

/**
 End of File
*/