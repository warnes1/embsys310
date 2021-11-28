/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    MOV   R2, #GPIOA_BASE    // Put GPIO_BASE address in R2
    ADD   R2, R2, #GPIOA_ODR // Add the ODR offset to R2
    
    CMP   R0, #1   // Does the LED state value passed to this routine
                   // in R0 match 1, indicating turn LED1 ON ?
                   
    BNE   NotOne   // If the value in R0 did not match 1
                   // branch to label 'NotOne'
                   
    LDR   R3, [R2] // Get the value in the ODR address
    
    ORR   R3, R3, #GPIOA_BIT_5 // OR with mask to turn ON
                               // just the bit for LED1
                               
    STR   R3, [R2] // Store masked value back to ODR address
                   // to actually switch LED1 ON
                   
    B     DoDelay  // Branch to DoDelay
    
NotOne // was not 1, so see if it is zero?

    CMP   R0, #0   // Does the LED state value passed to this routine
                   // in R0 match 0, indicating turn LED1 OFF ?
                   
    BNE   NotZero  // If the value in R0 did not match 0
                   // branch to the label 'NotZero' We will
                   // not bother with a delay since there was
                   // no valid state.
                   
    LDR   R3, [R2] // Get the value in the ODR address
   
    EOR   R3, R3, #0xFFFFFFFF   // Invert the ODR value
    AND   R3, R3, #GPIOA_BIT_5  // AND with inverted mask to turn OFF
                                // just the bit for LED1
                                
    STR   R3, [R2] // Store masked value back to ODR address
                   // to actually switch LED1 OFF
    
DoDelay   
    
    PUSH {R0, LR} // Since 'delay' will use R0 an LR PUSH on stack
    MOV   R0,    R1
    B    delay
    
    // <TODO> Implement function in assembly
    POP  {R0, LR}
NotZero
    BX LR
    END
