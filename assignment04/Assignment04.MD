
EMBSYS 310  - AU21 
ASSIGNMENT 04

Student: Marion 'Scott' Warner

Problems:
 
1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-
   band region to enable the clock for Port A, then answer the following:
 
       a. What instructions does the compiler produce in assembly for “writing” to the 
          RCC_AHB2ENR bit when using bit-band address?

              MOVS      R0, #1            ; Write the value 1 to R0, flags get updated
              LDR.N     R1, [PC, #0x64]   ; Load R1 from a word 0x64 bytes above the address in PC
              STR       R0, [R1]          ; Store value in R0 to the address refrenced by R1.
              ; In this case the STR changes the single bit we wish to change in one operation
             
       b. What were the instructions produced when writing to the RCC_AHB2ENR without using 
          bit-banding?

              LDR       R1, [R0]		; Load the value pointed to by R0 into R1
              ORRS.W    R1, R1, #1         ; OR the contents of R1 with 1, and put back in R1
              STR       R1, [R0]		; Store the value in R1 to the address R0 references
              ; In this case we have to load in the 32 bits containing the bit we want
              ; to change, change the bit we want to change with a mask, then write the
              ; 32 bits back to the address we got it from.
              ; This requires 3 operations to change the single bit we wish to change.

2. Create a function “func1” with 5 arguments and call “func1” from within another function 
   “func2”. Trace thru the assembler and note:
 
       a. How does the calling function “func2” pass the values to the called function “func1”?

              Values are passed using the registers and the Stack.
              The 5th argument is placed at the address the SP is pointing to, but not pushed.
              The 4th argument is stored in R3
              The 3rd argument is stored in R2
              The 2nd argument is stored in R1
              The 1st argument is stored in R0
 
       b. What extra code did the compiler generate before calling the function “func1” with the 
          multiple arguments?

              Not exactly sure what you are asking here, so I'm going to assume you are talking about
              func2() where registers R7 and the LR (Link Register) are pushed on the stack before
              we branch to func1.
            
       c. What extra code did the compiler generate inside the called function “func1” with the 
          list of multiple arguments?
            
              On entry R4 is pushed onto the stack
              Just before branching to the address in the link register, R4 is popped off the stack.
 
       d. Any other observations?

            Although R7 was pushed onto the stack upon entry into func2, it does not appear the
            intent was to actually save R7 for later retrival, but to create a location within the
            stack in which to pass the 5th argument to func1. The code in func2 to put the 5th
            argument in the stack is:
                MOVS      R0, #2
                STR       R0, [SP]
            Within func1, the code to retrieve the 5th argument from the stack is:
                LDR       R4, [SP, #0x4]

            Wondering why the 5th argumment is passed this way, instead of just pushing and popping?

       See main.c for func1() & func2(), in folder: assignment04\pass-values
 
3. Following the queue data structure approach, design, implement and test a stack data 
   structure:
 
        a. The following is the list of requirements:
 
            i. The stack should have a predefined size
                    DONE 
            ii. The stack supports “int” data types.
                    DONE 
            iii. Provide a function to initialize the stack internals.
                    DONE 
            iv. Provide a function to push an element onto the stack
                    DONE
            v. Provide a function to pop an element off the stack.
                    DONE 
            vi. Provide a function that returns 1 if stack is empty.
                    DONE 
            vii. Provide a function that returns 1 if stack is full.
                    DONE 
            viii. Return (-1) for error conditions
                    DONE 
        b. Provide a list of the test cases and their implementations inside of main.c

                    See main.c in folder: assignment04\Stack
 
        c. Separate the stack code from the rest of the test code (create stack.h & stack.c)

                    See stack.c & stack.h in folder: assignment04\Stack
                      
 
4. Bonus: Using the power of pointers and type casting, create a function that can determine if a 
   computer is big-endian or little-endian. Test your function in the simulator and modify the 
   Project Options (as shown in the figure below) against: 
       
        a. Cortex M4 (Little endian option)
 
        b. Cortex M4 (Big Endian option)

   See main.c in folder: assignment04\which-endian 
 
What to turn in and how: 
- Check in all your homework in your repo under the folder “assignment04”. 
- Your folder should contain the following: 
o Turn in your source code files only (for example: main.c, stack.c, stack.h) and any other 
files that you have authored. 
o Turn in answers to questions in markdown file format. 
- Submit a link to your GitHub repo assignment: 
o Ex: “https://github.com/<account_id>/embsys310/assignment04” 
