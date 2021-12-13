EMBSYS 310 - AU21
ASSIGNMENT 08

Goal
The goals for the assignment this week:

    1. Explore the use of PWM on our STM32L475 Discovery board.

Problems:
    1. PWM
        a. Study the tutorial: 
        https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM

            DONE

        b. Use the STM32CubeMx similar to what’s described in the tutorial to generate the code 
        that connects one of the PWM channels to one of the user LEDs for our STM32 
        Discovery Board.

            DONE

        c. Modify the code generated like the tutorial in order to control the LED blinking and 
        brightness.

            Well more Like: brighten-dim-brighten-dim--, guess that counts a blinking?

        d. Create a video demonstrating the brightness of the LED changing overtime.

            DONE

        e. Submit your video along with your entire IAR project to your GitHub.

            OK, I guess this means everthing in the assignemnt08 folder.

        Hint: Refer to the STM32L475 Reference Manual RM0351 for details on TIMERs and PWM.
        Also, see the MXCube diagram below for mapping the LEDs to the Timers

            Did LED2 have an associated PWM channel? Did not look like it so I opted for LED3.