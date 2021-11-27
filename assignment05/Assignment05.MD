
EMBSYS 310 - AU21
ASSIGNMENT 05

Goal
The goals for the assignment this week:

    1. To gain in depth understanding of the pass-by-value for function arguments in C.

    2. To gain hands-on experience with the ARM Cortex-M4 assembly language.

Problems:
    1. Create a function in “C” that allows swapping of two pointers.

        a. Explain what the “main” function does in order to setup the input arguments prior to 
        calling the swap_pointer() function?

            The value in R5 (0x20001FD8) is copied into R1 with a MOVS instruction
            The value in R4 (0x20001FDC) are copied to R0 with a MOVS instruction

        b. What are the values in R0 & R1 when swap_pointer() is called?

            The value in R1 is: 0x20001FD8, this is the address that contains the
            pointer, as represented in main.c as **PtrPtr1, and
            passsed as **Arg1 in swap_pointers().
            Memory:    0x20001FD8    .--> 0x20001FE0
                                    /
            Contains:  0x20001FE0 -'      0x00000800 (Decimal 2048)

            The value in R0 is: 0x20001FDC, this is the address that contains the
            second pointer to a pointer, represented in main.c as **PtrPtr2, and
            passed as **Arg2 in swap_pointers().
            Memory:    0x20001FDC    .--> 0x20001FE4
                                    /
            Contains:  0x20001FE4 -'      0x00000400 (Decimal 1024)
            



        c. Share a screen shot of the local variables inside of “main” after the function 
        swap_pointer() returns showing the values of the pointers and what they are pointing to.
        
            For clarity, I'm including before and after screen shots.

            Sharing Screen shot immediately before calling swap_pointer()

                ./assignment05/swap_pointers_in_C/ScreenShotLocalBefore_swap_pointer.PNG

            Sharing Screen shot after returning from swap_pointer()

                ./assignment05/swap_pointers_in_C/ScreenShotLocalAfter_swap_pointer.PNG
          

    2. Create a new file divAsm.s and add the file to the same HelloWorld project above.

        a. Start with the Assembly demo code shared in class (available under Module_06).

             DONE

        b. Write the assembly code to take an input argument, divide it by 2, and return the result.

             DONE

        c. Invoke the function “PrintString” from within divAsm before doing the division
           computation.

             DONE

        d. Add a comment for every statement in your assembly function code.

             DONE

        e. Invoke divAsm() inside of your main function in main.c

             DONE

        f. Run your program on the board and capture a snapshot image of the output from 
        TeraTerm showing the result of the divAsm.

             ./assignment05/HelloWorld_DivAsm/HelloWorld_divAsm.PNG

    3. Implement a swap function in assembly and call it “swapCharsAsm”:

        a. It takes as input two variables of char data type each and swaps the two chars.

             DONE

        b. Add a comment for every statement in your assembly function code.

             DONE

        c. Bonus: Return 0 if the two chars are identical; otherwise, return 1.

             DONE

    4. Bonus: Implement the swap_pointer() function from #1 above in assembly and call it 
       swapPointersAsm().

        a. Add a comment for every statement in your assembly function code.
 
             DONE

        b. Invoke swapPointersAsm() from your main function main.c

             DONE

        c. Run your program on the board and capture a snapshot image of the output from 
        TeraTerm showing the result of the swapPointersAsm() subroutine.

             Oh Darn! missed this instruction, please see the following screen shots:
             ./assignment05/swapPointersAsm/Locals_Before_swapPointersAsm.PNG
             ./assignment05/swapPointersAsm/Locals_After_swapPointersAsm.PNG

What to turn in and how:

    - Check in all your homework in your repo under the folder “assignment05”.

    - Your folder should contain the following:

        o Turn in your source code files only (for example: main.c, …etc.) and any other files that 
        you have authored.

        o Turn in answers to questions in markdown file format.

    - Submit a link to your GitHub repo assignment:

        o Ex: “https://github.com/<account_id>/embsys300/assignment05