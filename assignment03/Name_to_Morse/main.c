

// My name: MARION SCOTT WARNER in Morse Code.
// Homework, part of Assignment 03

/*-----------------------------------------------------------*/
/* Modifications of the in-class LD2 program by Scott Warner     */
/* to allow my name to be displayed in Morse Code on         */
/* LED 1. To make it easier to decipher the actual morse     */
/* code, I have allowed LED 2 to be on for the same duration */
/* of time as LED 1 during dashes. To make it more realistic */
/* I have opted to include my whole name instead of just my  */
/* first name. This demonstrates correct relative spacing    */
/* between words.                                            */
/*-----------------------------------------------------------*/


#if 1
// For controlling clock signals to GPIOs
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))

// Leave this, I will use LED 1 & 2 simultanous for DASHes to
// make it easier to distinguish between the DASHes and DOTs.
// Honestly I could not distinguish the DOTS from the DASHes
// accurately, even though the relative timing was
// correct. Perhaps my persistance of vision is too persistant?
#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

volatile unsigned long dlyCnt=0;

// For setting/unsetting correct pin of GPIOx to control LEDs
#define ODR5 (1<<5)   // For PA5  (LED 1)
#define ODR14 (1<<14) // For PB14 (LED 2)

// 1. Length of dot is one unit
// 2. A dash is three units
// 3. The space between parts of the same letter is one unit
// 4. The space between letters is three units.
// 5. The space between words is seven units

// We can set value for OneUnit to get the correct relative timing
// for other Units
#define OneUnit 60000
#define ThreeUnit OneUnit*3
#define SevenUnit OneUnit*7
#define DOT OneUnit
#define DASH  ThreeUnit
#define SPACE_DD  OneUnit    // time between dot/dashes for single letter
#define SPACE_BL  ThreeUnit // time between letters
#define SPACE_BW  SevenUnit // time between words

// #define DEBUG_DASH
/*------------------------------------------*/
char myName[] = "MARION SCOTT WARNER";
/*------------------------------------------*/
// Used to convert the Letters in the name to DOTs and DASHes
char Letter_to_Morse[36][7]=
{
    "A.-",
    "B-...",
    "C-.-.",
    "D-..",
    "E.",
    "F..-.",
    "G--.",
    "H....",
    "I..",
    "J.---",
    "K-.-",
    "L.-..",
    "M--",
    "N-.",
    "O---",
    "P.--.",
    "Q--.-",
    "R.-.",
    "S...",
    "T-",
    "U..-",
    "V...-",
    "W.--",
    "X-..-",
    "Y-.--",
    "Z--..",
    "1.----",
    "2..---",
    "3...--",
    "4....-",
    "5.....",
    "6-....",
    "7--...",
    "8---..",
    "9----.",
    "0-----"
};

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    RCC_AHB2ENR |= 0x1;  // Connect clock to GBIOA registers
    RCC_AHB2ENR |= 0x2;  // Connect clock to GPIOB resisters
    
    // GPIOA Base Address: 0x48000000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[12:11] to 0x01  // To enable PA5 as output
    GPIOA_MODER &= 0xFFFFF7FF;
    
    // GPIOB Base Address: 0x48000400
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  // To enable PB14 as output
    GPIOB_MODER &= 0xDFFFFFFF;

    char *myNamePtr = myName;
    
    while ( *myNamePtr)
    {
        if ( *myNamePtr == ' ')
        {
           // We are between words delay for SPACE_BW count
            dlyCnt = 0;
            while( dlyCnt < SPACE_BW){ dlyCnt++; }
        }
        else // If not a space, we will assume it's a valid letter
        {
            // Find a match for the current *MyNamePtr
            // in the char_to_Morse array
            for(int i=0; i<36; i++)
            {
                if(Letter_to_Morse[i][0] == *myNamePtr)
                {
                    char *MorsePtr = &Letter_to_Morse[i][1];
                    while( *MorsePtr )
                    {
                        if( *MorsePtr == '.') // Process DOT
                        {
                            // Turn the LED ON
                            GPIOA_ODR |= ODR5;
                            // Delay for 1 Unit (DOT = 1 Unit)
                            dlyCnt =0;
                            while( dlyCnt < DOT){ dlyCnt++; }
                        }
                        if( *MorsePtr == '-') // Process DASH
                        {
                            //Turn the LED ON
                            GPIOA_ODR |= ODR5;
#ifdef DEBUG_DASH
                             GPIOB_ODR |= ODR14; // For Debugging DASH
#endif
                            // Delay for 3 Units (DASH = 3 Units long)
                            dlyCnt =0;
                            while( dlyCnt < DASH){ dlyCnt++;}
#ifdef DEBUG_DASH
                            GPIOB_ODR &= ~ODR14; // For Debugging DASH
#endif
                        }
                        // Turn the LED OFF
                        GPIOA_ODR &= ~ODR5;
                        dlyCnt = 0;
                        while( dlyCnt < SPACE_DD){ dlyCnt++; }
                        MorsePtr++;
                    }
                    break;
                }
            }
            if( *(myNamePtr + 1) )// Any more letters
            {
                // Between letters, delay for three Units
                dlyCnt = 0;
                while( dlyCnt < SPACE_BL){ dlyCnt++;}
            }
        }
        myNamePtr++;
    }
    return; 
}
#endif
