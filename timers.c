#include <xc.h>
#include "timers.h"

/************************************
 * Function to set up timer 0
************************************/
void Timer0_init(void)
{
    T0CON1bits.T0CS=0b010; // Fosc/4
    T0CON1bits.T0ASYNC=1; // see datasheet errata - needed to ensure correct operation when Fosc/4 used as clock source
    T0CON1bits.T0CKPS=0b1000; // 1:256 -> required: 1:244.14
    TMR0H=0b11100111;            
    TMR0L=0b10010101;
    T0CON0bits.T016BIT=1;	//8bit mode
    
    // initialise the time registers to 3035 for the LED to toggle every one second
    T0CON0bits.T0EN=1;	//start the timer
}