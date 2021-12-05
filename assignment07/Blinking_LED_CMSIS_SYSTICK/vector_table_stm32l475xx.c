//====================================================================
// Homework: Assignment07
// Student:  Scott Warner
// File:     vector_table_stm32l475xx.c
//====================================================================

// There is no standard C syntax to place variable in specific sections
// The IAR provided extension to do so is as follows: @ "<section_name>"
// Here we wish to place our  __vector_table in the .intvec section
// so we use: @ ".intvec", which causes the linker to place __vector_table
// at an address associated with .intvec

#include "stm32l4xx_it.h"

#pragma section="CSTACK" // IAR C extension

extern void __iar_program_start(void); // Need this prototype for the array
                                       // below. Symbol is declared, but where
                                       // defined? Linker will look in standard
                                       // IAR libraries for symbol:
                                       // __iar_program_start

int const __vector_table[] @ ".intvec" = {
    (int) __section_end("CSTACK"), // Initial Stack Pointer (SP) value
    (int) __iar_program_start,    // Address to load into PC when reset occurs
    (int) NMI_Handler,            // Non Maskable Interupt Handler
    (int) HardFault_Handler,      // Hard Fault
    (int) MemManage_Handler,      // Memory Management Fault
    (int) BusFault_Handler,       // Bus Fault
    (int) UsageFault_Handler,     // Usage Fault
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    (int) SVC_Handler,           // SVCall
    (int) DebugMon_Handler,
    0,                            // Reserved
    (int) PendSV_Handler,
    (int) SysTick_Handler         // SYSTICK Handler
};

// The above __vector_table is modeled after the one described in:
//     PM0214 - Programming Manual for STM32 Cortex-M4
//              Section 2.3.4
// Standard prototypes for handlers are defined in the CMSIS
// standard header file: "stm32l4xx_it.h" for the microcontroller chip
// used on our development board.

void Handler_NotUsed(void)
{
    while(1); // Loop forever
};
// The weak alias means that if a symbol remains undefined till
// the end of the linking process, the provided aliase will be used.
// So we can define a function with the same name in our main.c file
// and it will used instead of the __weak one defined here.
__weak void NMI_Handler(void){
    Handler_NotUsed();
};

__weak void HardFault_Handler(void){
    Handler_NotUsed();
};

__weak void MemManage_Handler(void){
    Handler_NotUsed(); 
};

__weak void BusFault_Handler(void){
    Handler_NotUsed();
};

__weak void UsageFault_Handler(void){
    Handler_NotUsed();
};

__weak void SVC_Handler(void){
    Handler_NotUsed();
};
__weak void DebugMon_Handler(void){
    Handler_NotUsed();
};

__weak void PendSV_Handler(void){
    Handler_NotUsed();
};

__weak void SysTick_Handler(void){
    Handler_NotUsed();
};