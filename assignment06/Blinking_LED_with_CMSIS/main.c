#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework - Assignment06 - Problem 1
// LD2 --> PB14 -- In Class

// ************ Using CMSIS ************ //

volatile int counter=0;

#if 1
//===================================================================
// Assignment-06, Problem 1, Blink LED 1 with CMIS.
// Scott Warner - Modifications made to blick LED 1
// instead of LED 2, using appropriate CMSIS calls.
//===================================================================

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
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x4800000
    // Address offset: 0x5
    // Set bit[5] to 1 --> 0x4000; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }    
}
#endif

#if 0
//===================================================================
// Done in Class, Module 7, Blink LED 2 with CMIS
//===================================================================
void main(void)
{     
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
    GPIOB->MODER |= GPIO_MODER_MODE14_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        GPIOB->ODR |= GPIO_ODR_OD14;
        delay(100000);
        
        GPIOB->ODR &= ~GPIO_ODR_OD14;
        delay(100000);
    }    
}
#endif
