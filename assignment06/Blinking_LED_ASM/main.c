#include <stdint.h>

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class
//=====================================================================//
// Assignment-06
// Problem 2 & Bonus Problem 3

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD14   (1<<14)
#define ORD5    (1<<5)

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION_1 100000
#define DELAY_DURATION_2 700000
void delay(uint32_t iteration);
void control_user_led1(uint8_t state, uint32_t duration);
void enable_rcc(uint32_t port);
uint32_t value;
void main(void)
{    
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1 to enable clock to PortB
    // Set bit[0] to 1 to enable clock to PortA
    // 1. Enable clock to Peripheral
    
    // RCC_AHB2ENR |= 0x1;
    
    // <TODO> Replace above statement with function call below
 //*************************************************************//
 //********** BONUS Assignment06 Problem 3 *********************//
 //*************************************************************//
    enable_rcc(0);
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 as output
    // Note: GPIOA_MODER reset value = 0xABFFFFFF
    //       So will only need to clear bit 11
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
     
    while(1)
    {
        // For fun double blink, then pause :)
        control_user_led1(LED_ON, DELAY_DURATION_1);
        control_user_led1(LED_OFF, DELAY_DURATION_1);
        control_user_led1(LED_ON, DELAY_DURATION_1);
        control_user_led1(LED_OFF, DELAY_DURATION_2);
    }
}
