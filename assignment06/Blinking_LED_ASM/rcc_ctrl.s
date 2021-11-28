/*******************************************************************************
File name       : rcc_ctrl.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC enable_rcc        // Exports symbols to other modules

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
Function Name   : enable_rcc
Description     : - Uses Bit-Band registers at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void enable_rcc(uint32_t port)
                : Where port indicates wich port to enable the clock for
Parameters      : R0: uint32_t port

Return value    : None
*******************************************************************************/  

// Bitband address calculation formula
// (0x42000000+(0x2104C *32) + (1*4))) = 0x1;
RCC_BASE_T  EQU 0x4200
RCC_BASE_B  EQU 0x0000
RCC_AHB2ENR_T  EQU 0x0002
RCC_AHB2ENR_B  EQU 0x104C

enable_rcc
    // The bit position of the RCC clock bit to set is
    // passed to this routine in R0
    MOVT    R1,    #RCC_BASE_T  // Top 16 bits of RCC_BASE
    MOVW    R3,    #RCC_BASE_B  // Bottom 16 bits of RCC_BASE
    ADD     R1,    R1, R3       // Combine top and bottom for
                                // 32 bit RCC_BASE
    
    MOVT    R2,    #RCC_AHB2ENR_T // Top 16 bits of RCC_AHB2ENR
    MOVW    R3,    #RCC_AHB2ENR_B // Bottom 16 bits of RCC_AHB2ENR
    ADD     R2,    R2, R3         // Combine top and bottom
                                  // for 32 bit RCC_AHB2ENR
    
    MOV     R3,    #32
    MUL     R2,    R2, R3         // Multiply RCC_AHB2ENR by 32
    
    MOV     R3,    #4 
    MUL     R0,    R0, R3         // Multiply bit position by 4
    
    MOV     R3,    #0x0
    ADD     R3,    R2, R0    // Add up R1, R2 and R0 for bit-band
                             // alias address and put in R3
    ADD     R3,    R3, R1
    MOV     R1,    #0x1   
    STR     R1, [R3]         // Write 1 to the bit-band alias address
    
    END
