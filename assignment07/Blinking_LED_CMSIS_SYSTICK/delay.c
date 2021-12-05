//====================================================================
// Homework: Assignment07
// Student:  Scott Warner
// File:     delay.c
//====================================================================
#include <stdint.h>
#include "delay.h"

// Assignment07, Problem 1.
//     d. Modify the delay() function to be able to accept an input
//        variable indicating the number of milliseconds instead of the
//        loop counter we have been using so far.
//

extern uint32_t ClockCyclesToLoad;

void delay(uint32_t delayInMilliseconds)
{
    // Since our processor dafault clock speed is 4 MHz
    // or 4 million clock cycles per second, we divide 4 million by 1000
    // to get 4000 clock cycles per milliSecond.
    // To get the correct total number of clock cycles, we will
    // multiply the milliSeconds value passed in by 4000.
    
    // Check if the milliSeonds value passed in is greater than
    // 4194, this is the maximum number of milliseconds, so that the
    // calcualted total clock cycles does not exceed a value that
    // can be placed in an unsigned 24bit integer. If it exceeds 4194,
    // then just set to maximum allowed value of 4194
    if (delayInMilliseconds  > 4194){
        delayInMilliseconds = 4194;
    }
    ClockCyclesToLoad = delayInMilliseconds * 4000;   
}