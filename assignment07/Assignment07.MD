EMBSYS 310 - AU21
ASSIGNMENT 07

Goal
The goals for the assignment this week:

    1. Practice setting up a user-defined vector table.

    2. Practice dealing with interrupts and the use of the SysTick timer.

    3. Practice generating and looking thru the map file.

Problems:

    1. Starting from the blinking LED code that you created using the CMSIS definitions:

        a. Add the files “stm32l475xx.h” & “stm32l4xx_it.h” to the folder where “main.c” is saved. 
        You could get these files from our “Code” folder from our canvas site.

            DONE

        b. Define your own vector table as we did during the class.
 
            DONE - file: vector_table_stm32l475xx.c

        c. Setup the SysTick timer to trigger an interrupt every 1ms.

            DONE - 1ms is equal to 4000 CPU clock cycles, at the default frequency of 4 MHz

        d. Modify the delay() function to be able to accept an input variable indicating the number 
        of milliseconds instead of the loop counter we’ve been using so far:
 
            i. void delay(uint32_t delayInMilliseconds)
     
                DONE - file: delay.c & delay.h

            ii. Hint: Implement the delay() function rely on the SysTick interrupt handler to 
            decrement a global variable used by the delay() function
                 
                DONE - thanks for the hint Tammer, my global variable is: ClockCyclesToLoad

    2. Generate the map file for your program and provide details on:
              
            DONE - Map Created for compiled version with redefined delay() function.
            ./assignment07/Blinking_LED_CMSIS_SYSTICK/Debug/List/Blinking_LED_CMSIS_SYSTICK.map

        a. How much total ROM your program is occupying?

            374 bytes for code
            90  bytes for read-only data
            
        b. How much total RAM your program is using?

            4   bytes for r/w data
            8192 (0x2000) for the Stack

        c. What part of your program is using the most ROM?
     
            main.o

        d. What part of your program is using the most RAM?

            Of my actual code, main.o uses 4 bytes of RAM for a global variable.
            The linker of course allocated 0x2000 bytes for the stack.

    3. Bonus: Is there anything that can be done to optimize the usage of ROM or RAM resources? 
    Explain any options that you come up with.

        RAM - Well the most obvious one would be to set the stack size in the IDE to a smaller value.
        We do not have a bunch of nested function calls so there is no need to allow for alot
        of space for stack frames.

        ROM - We could probably get rid of the intializer data in ROM, if we initialize our variable
        when we declare them. Turn on code optimization in the IDE. We could also get rid of the
        hook for the low level initialization.

What to turn in and how:
 
    - Check in all your homework in your repo under the folder “assignment07”.

    - Your folder should contain the following:

        o Turn in your source code files only (for example: main.c, …etc.) and any other files that 
        you have authored.

            /assignment07/Blinking_LED_CMSIS_SYSTICK/main.c
            /assignment07/Blinking_LED_CMSIS_SYSTICK/delay.c
            /assignment07/Blinking_LED_CMSIS_SYSTICK/delay.h
            /assignment07/Blinking_LED_CMSIS_SYSTICK/vector_table_stm32l475xx.c
            /assignment07/Blinking_LED_CMSIS_SYSTICK/Debug/List/Blinking_LED_CMSIS_SYSTICK.map

        o Turn in answers to questions in markdown file format.

    - Submit a link to your GitHub repo assignment:

        o Ex: “https://github.com/<account_id>/embsys310/assignment07"