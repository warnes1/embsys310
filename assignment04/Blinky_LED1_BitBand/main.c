

// LD1 --> PA5 -- Homework Assignment04
// LD2 --> PB14 -- In Class

/*-----------------------------------------------------------*/
/* Modifications of the in-class demo to                     */
/* allow blinking of LD1 associated with PA5.                */
/* by using Bit-Band addressing to set bit location          */
/*                                                           */
/* Student: Marion Scott Warner                              */
/*-----------------------------------------------------------*/

#if 1
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define RCC_AHB2ENR_BB_Bit1 *((unsigned int*)(0x42000000 + (0x2104C*32) + (0x0*4)))
#define RCC_AHB2ENR_BB_Bit2 *((unsigned int*)(0x42000000 + (0x2104C*32) + (0x1*4)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

volatile int counter=0;
//int counter=0;

#define ORD14 (1<<14) // For PB14 (LED 2)
#define ORD5 (1<<5)   // For PA5  (LED 1)

void main(void)
{
#if 0   // Load/Modify/Store, setting bit by masking
    //RCC_AHB2ENR |= 0x2; // Connect clock to GPIOB registers
    RCC_AHB2ENR |= 0x1;  // Connect clock to GBIOA registers
#endif
#if 1   // Modify, setting bit with bit-band aliase
    RCC_AHB2ENR_BB_Bit1 = 0x1;
    //RCC_AHB2ENR_BB_Bit2 = 0x1;
#endif
        
  
    // GPIOB Base Address: 0x48000400
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB_MODER &= 0xDFFFFFFF;
    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[12:11] to 0x01  // To enable PA5 as output
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIOB Base Address: 0x48000400
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF

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
        GPIOA_ODR &= ~ORD5;
        //GPIOB_ODR |= ORD14;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        GPIOA_ODR |= ORD5;
        //GPIOB_ODR &= ~ORD14;
    }
}
#endif
