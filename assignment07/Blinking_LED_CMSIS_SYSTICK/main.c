//====================================================================
// Homework: Assignment07
// Student:  Scott Warner
// File:     main.c
//====================================================================

#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

// The default CPU clock for our Cortex M4 microcontroller is  4 Mhz
// 4 million clock cycles = 1 second
#define SYS_CLOCK_HZ 0x003D0900     // SysTick interrupt at 1 Sec intervals

// 4000 clock cycles = 1 millisecond
#define SYS_CLOCK_1ms 0x00000FA0    // SysTick interrupt at 1ms intervals

// 400000 clock cycles = 100 milliseconds
#define SYS_CLOCK_100ms 0x00061A80  //SysTick interrupt at 100ms intervals

// 2000000 clock cycles = 500 milliseconds ( 1/2 second )
#define SYS_CLOCK_500ms 0x001E8480  //SysTick interrupt at 500ms intervals

// Homework - Assignment07 
// ************ Using CMSIS ************ //
// ************ Using SYSTICK timer **** //

uint32_t ClockCyclesToLoad = 1;

// Initialize the SYSTICK Interrupt to repeat after waiting
// the number of CPU clock Cycles, specifed in the global
// variable ClockCyclesToLoad, 1 is subtracted to get the period exact.
void SysTick_Init(void)
{
    SysTick->LOAD = ClockCyclesToLoad - 1;
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
};

// This handler is called each time a SysTick interrupt occurs
// We will use it to toggle LED 1 at regular intervals. This handler
// definition overrides the one defined in vector_table_stm32l475xx.c
// as __weak
void SysTick_Handler(void)
{
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x4800000
    // Address offset: 0x5
    // Set bit[5] to 1 --> 0x4000; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    // Flip bit 5 by XORing with a mask where only bit position 5 is a 1
    GPIOA->ODR ^= GPIO_ODR_OD5;
};

#if 0 
// Assignment07, Problem 1.
//     c. Setup the SysTick timer to trigger an interrupt every 1ms
void main(void)
{     
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[12:11] to 0x01  so --> 0x20 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    ClockCyclesToLoad = SYS_CLOCK_1ms; // Of course we can not see it now
                                       // do to persistance-of-vision.
                                       // An Oscilloscope works :)
    
    SysTick_Init();
    
    while(1)
    {
       // When the SysTick timer reaches 0 an interrupt will occur,
       // interrupting this loop until the interrupt handler
       // is complete and returns here.
    }    
}
#endif

#if 1 
// Assignment07, Problem 1.
//     d. Modify the delay() function to be able to accept an input
//        variable indicating the number of milliseconds instead of the
//        loop counter we have been using so far.
//
void main(void)
{     
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[12:11] to 0x01  so --> 0x20 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // Pass delay() the number of milliseconds to wait,
    // before the SysTick interrupt occurs.
    delay(250); // Generate a SysTick interrupt every 1/4 of a second
    
    SysTick_Init();
    
    while(1)
    {
       // When the SysTick timer reaches 0 an interrupt will occur,
       // causing this loop to suspend until the interrupt handler
       // is complete and returns here.
    }    
}
#endif
