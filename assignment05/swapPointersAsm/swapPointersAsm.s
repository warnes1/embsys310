/*******************************************************************************
Assignment05, Bonus problem 4. swapPointersAsm
File name       : swapPointersAsm.s
Description     : Assembly language function for swapping 2 pointers
*******************************************************************************/   
    
    PUBLIC swapPointersAsm  // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
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
Function Name   : swapPointersAsm
Description     : Swaps the pointers contained in the 2 addresses passed in
C Prototype     : int swapPointersAsm( int **PtrPtr1, int **PtrPtr2 )
                : Where **PtrPtr1 and **PtrPtr2 hold the addresses to be swap
Parameters      : returns R0: integer val
Return value    : R0 = 0
*******************************************************************************/

swapPointersAsm 
    LDR      R2,   [R0]     // Move the address value contained in the
                            // memory location referenced by [R0], into R2
                             
    LDR      R3,   [R1]    // Move the address value contained in the 
                           // memory location referenced by [R1], into R3
                             
    STR      R2,   [R1]     // Move the address value contained in R2 to the
                            // memory location referenced by [R1]
                            
    STR      R3,   [R0]     // Move the address value contained in R3 to the
                            // memory location referenced by {R0]
    
    MOV       R0,    #0	     //***** BONUS Return 0 to the caller, since Char1 == Char2
    
//    B.N       L2             // Return a value of 0 to calling routine using R0

//L1  LDRB      R2,    [R0]    // Load R2 with the value from the address in R0, Char1 
//    LDRB      R3,    [R1]    // Load R3 with the value from the address in R1, Char2
//    STRB      R3,    [R0]    // Store value in R3 to address in R0, Char1
//    STRB      R2,    [R1]    // Store value in R2 to address in R1, Char2

//    MOV       R0,    #1	     //***** BONUS Return value of 1, since Char1 != Char2
    
    BX	      LR             // Branch to the location in the Link Register, to resume
                             // at memory location following call to this routine
    END


        

