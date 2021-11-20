

// LD1 --> PA5 -- Homework

/*-----------------------------------------------------------*/
/* Modifications of the in-class program by Scott Warner     */
/* to allow blinking of LD1 associated with PA5.             */
/* This version uses XOR to toggle LD1 between ON/OFF states */
/*-----------------------------------------------------------*/

#if 1
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))

volatile int counter=0;
//int counter=0;

#define ORD5 (1<<5)   // For PA5  (LED 1)

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    RCC_AHB2ENR |= 0x1;  // Connect clock to GBIOA registers
    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[12:11] to 0x01  // To enable PA5 as output
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIOA Base Address: 0x48000000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        GPIOA_ODR ^= ORD5;
    }
}
#endif
