EMBSYS 310 - AU21
ASSIGNMENT 06

Goal
The goals for the assignment this week:

    1. Practice the use of the Cortex Microcontroller Software Interface Standard (CMSIS).

    2. Gain more practice with the Cortex-M4 assembly language.

Problems:

    1. Use the CMSIS to implement the code to blink the user LED1 (PA5) on the STM32L475 board.

        a. Create a new project.

                DONE

        b. Create a main.c file and add it to the project.

                DONE - Copied in files from Class Demo to modify ?

        c. Add the files “stm32l475xx.h” and “system_stm32l4xx.h” to the folder on your drive 
        where “main.c” is saved. You should be able to get these files thru STM32CubeMX, or 
        you could find them under the “Code” folder in our canvas site.

                DONE - Did not find files in the "Code" folder? But they were in the Demo

        d. Enable use of CMSIS in project options settings.

                DONE 

        e. Implement toggling of LED1 using the CMSIS data structures.

                DONE - modified Class Demo to toggle LED1

    2. Convert the blinking led program into assembly code.

        a. Download the zip file “Module07_Assignment06_Problem2_Starter_Files.zip” from 
        canvas. Use the skeleton files (main.c, user_led.s, and delay.s) inside that zip file.
      
                DONE

        b. Create a new project and add the skeleton files to that project.

                DONE

        c. Make sure to setup the project to connect to your board (follow instructions form 
        Module_02 if you forgot how to do that).

                DONE

        d. Implement the function control_user_led1 in assembly:

            i. The function takes as input the desired led state (0 == OFF, 1 == ON) and the 
            duration for holding that state.

                DONE

            ii. Call delay function from within the control_user_led1

                DONE

            iii. The function returns void.

                DONE ( I guess that mean it returns nothing?)
  
        e. Implement the function delay in assembly:

            i. The function takes as input an integer value.

                DONE

            ii. The function will decrement the value until it reaches 0.

                DONE

            iii. The function returns void.

                DONE

        f. Call the “control_user_led1” function from a while loop inside the main function.

                DONE

        g. For any C code, use only data types defined in the “stdint.h” file.

                DONE

        Hints:
             a. Start with your simple LED1 code that made use of the peripheral registers.
             b. Replace the delay function with the one you implemented in assembly first. 
             c. Once the delay works in assembly, implement control_user_led1 function next.

    3.  Bonus: Implement enable_rcc function in assembly inside the rcc_ctrl.s provided skeleton 
    file. Use the bit-band region to enable the clock associated with LED1 GPIOA. The function takes 
    as input the bit position for the corresponding GPIO bank. Hint: To load the address value in the
    register, you will need to use MOVW & MOVT (discussed in Module_06).

                DONE (Thanks for the hint Tamer, that really helped)

What to turn in and how:

    - Check in all your homework in your repo under the folder “assignment06”.

    - Your folder should contain the following:

        o Turn in your source code files only (for example: main.c, delay.s, user_led.s, 
        rcc_ctrl.s…etc.) and any other files that you have authored.

        o Turn in answers to questions in markdown file format.

    - Submit a link to your GitHub repo assignment:

        o Ex: “https://github.com/<account_id>/embsys310/assignment06"