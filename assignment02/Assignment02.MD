
EMBSYS 310  - AU21 

ASSIGNMENT 02  - Answers from Scott Warner:

Goals:

    1. To explore the IAR IDE and the different debug views.

    2. Get hands-on practice with machine instructions, addresses, variable, and pointers.

Setup: 

    1. Create a new project in IAR following the steps from the slide deck.

    2. Create a counter local variable and increment the counter several times.
 
    3. Run the program in the simulator environment and answer the following questions: 

Observe and answer: 

Create a new IAR project with the following program in a main.c file, then follow the 
questions below: 
 
            int main() { 
            int counter = 0; 
            counter ++; 
            counter ++; 
            counter ++; 
            counter ++; 
            counter ++; 
            counter ++; 
            counter ++; 
            return 0; 
            } 
 
    1. Inject 0x7FFFFFFF for the counter value in the variable window, then step thru the 
       program only once to increment counter. 

        a) What is the value of the counter from the Local window? 

                Decimal: -2147483648

        b) What is the value of the counter in the Registers window?
 
                Hex:      0x80000000

        c) Please note down which flags are set in the APSR register. And explain why? 

                N flag set indicating last instruction resulted in a negative value
                  as indicate by a 1 in bit position 31.

                V flag set indicating last instruction resulted in an overflow condition
                  because the result of the signed number operation was to large, causing
                  the high order bit to overflow into the sign bit.

    2. If your write all Fs (0XFFFFFFFF) in the Register value for counter then step thru 
       the program once to increment counter 

        a) What happens to the value of counter in the Locals window?

                Becomes Decimal: 0 

        b) Please note down which are set in the APSR register. And explain why.

                Z flag is set indicating last instruction resulted in zero value

                C flag is set indicating last instruction resulted in a carry out
                  condition from bit position 31

 
    3. Change the counter variable type in your code to "unsigned int". Inject the values 
       0x7FFFFFFF then step thru the program to increment the counter once: 

        a) What is the value of counter in the Locals window after incrementing
           for each value? 
                Decimal: 2147483648


        b) Please note down which flags are set in the APSR register. And explain why. 

                N flag set indicating last instruction resulted in a negative value
                  as indicated by a 1 in bit position 31. 

                V flag set indicating last instruction resulted in an overflow condition
                  because the result of the unsigned number operation was too large,
		  causing the high order bit to overflow into the sign bit.

    4. Change the counter variable type in your code to "unsigned". 
       Inject the values 0xFFFFFFFF then step thru the program to 
       increment the counter once: 

        a) What is the value of counter in the Locals window after incrementing for
           each value? 

                Decimal: 0


        b) Please note down which are set in the APSR register. And explain why.
  
                Z flag is set indicating last instruction resulted in a zero value.

                C flag is set indicating last instruction resulted in a carry out
                  condition to bit position 31

 
    5. Move the counter variable outside of main (at the top of the file): 

        a) What is the scope of the variable counter? 

                 Global

        b) Is it still visible in the Locals view?
                  
                 No, it now exist outside of main(), so is not a local to main() 


        c) In which window view can we track counter now? 
                 
                 In the memory window, and the register window since R1 is used to increment
                 the loaded/stored from/to memory.
 


        d) What is the address of the counter variable in memory? 

                 0x20000000


 
    6. Change the source code to the following, then run the program in the simulator: 
 
            int counter = 0x0; 
            int main() { 
            int *p_int = (int *)0x20000000; 
            ++(*p_int); 
            ++(*p_int); 
            ++(*p_int); 
            counter ++; 
            return 0; 
            } 
 
 
        a) What is the value of counter at the end of the program 
           (halting at the return 0 statement)? 

		0x00000004


        b) Explain why the counter value has changed?

		The address of counter is 0x20000000 and its value is initialized to 0.
                It just so happens we initialized the pointer address *P_int to 0x20000000, so when we increment
                the value in the address *P_int points to with ++(*P_int); we are incrementing the value in the
                same memory location associated with counter. Then counter is incremented to get to 4
 
    7. Change the setting of IAR to run the same program on the evaluation board: 

             Setup: 
             1. Connect evaluation board to your computer through ST Link cable. 
             2. Set the IAR to using STLink: 
             3. Project -> Options -> Debugger -> Device: ST-Link 
             4. Download setting is flash loader 
             5. Make sure ST-Link Interface is set to SWD 
             6. Run the same code described in the simulator. 
 
        a) What is the address where counter is stored?
  
                0x20000000

        b) Is the counter variable stored in RAM or ROM? 
              
                RAM

        c) What is the value of counter at the end of the program 
           (halting at the return 0 statement).

                4 
 
What to turn in and how: 
    - Check in all your homework in your repo under the folder assignment02.
 
    - Your folder should contain the following:
 
        o An MD file with the answers to the questions above.
 
        o Source code of your final counter project.
 
    - Submit a link to your GitHub repo assignment:
 
        https://github.com/warnes1/embsys310/assignment02 
