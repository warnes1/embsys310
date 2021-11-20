
//===============================================================
//
// embsys310, Fall 2021
// Homework Assignment04
// Stack routines calls
// Assertion testing of stack routines.
//
// Marion Scott Warner
//
//===============================================================
#include <assert.h>
#include"stack.h"

int main()
{
    int result01;
    int result02;


    int poppedInt;


    //***********************************************************************
    // Test1: POP item from an empty stack
    //***********************************************************************
    // Arrange:
    result01 = 22;
    poppedInt = -378;
    stack_init();

    //Act
    result01 = pop_stack(&poppedInt);

    //Assert:
    assert(-1 == result01); // Was expected error value of -1 returned?
    assert(-378 == poppedInt); // Did the value of poppedInt remain unchanged?


    //***********************************************************************
    // Test2: Successfully POP item off stack after PUSHING item on to stack
    //***********************************************************************
    // Arrange:
    result01 = 22;
    result02 = 22;
    poppedInt = -378;
    stack_init();

    // Act:
    result01 = push_stack(227);
    result02 = pop_stack(&poppedInt);

    // Assert:
    assert(0 == result01);
    assert(0 == result02);
    assert(227 == poppedInt);


    //***********************************************************************
    // Test3: Fill the stack by PUSHING 10 items,
    //        Empty the stack by POPPING 10 items
    //***********************************************************************
    // Arrange:
    poppedInt = 227;
    stack_init();

    // Act:
    push_stack(1);
    push_stack(2);
    push_stack(3);
    push_stack(-2147483648);
    push_stack(5);
    push_stack(6);
    push_stack(2147483647);
    push_stack(32);
    push_stack(64);
    push_stack(4567);

    // Assert:
    assert(0 == pop_stack(&poppedInt));
    assert(4567 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(64 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(32 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2147483647 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(6 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(5 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(-2147483648 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(3 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(1 == poppedInt);
    assert(1 == is_stack_empty());

    //***********************************************************************
    // Test4: Fill the stack by PUSHING 10 items,
    //        PUSH one more item, should fail
    //***********************************************************************
    // Arrange:
    poppedInt = 227;
    stack_init();

    // Act:
    push_stack(1);
    push_stack(2);
    push_stack(3);
    push_stack(-2147483648);
    push_stack(5);
    push_stack(6);
    push_stack(2147483647);
    push_stack(32);
    push_stack(64);
    push_stack(4567);

    // Assert:
    assert(-1 == push_stack(267));

    assert(0 == pop_stack(&poppedInt));
    assert(4567 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(64 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(32 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2147483647 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(6 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(5 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(-2147483648 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(3 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(1 == poppedInt);


    //***********************************************************************
    // Test5: Fill stack and Empty stack 2 times (use different values)
    //***********************************************************************
    // Arrange:
    poppedInt = 227;
    stack_init();

    // Act:
    push_stack(1);
    push_stack(2);
    push_stack(3);
    push_stack(-2147483648);
    push_stack(5);
    push_stack(6);
    push_stack(2147483647);
    push_stack(32);
    push_stack(64);
    push_stack(4567);

    // Assert:

    assert(0 == pop_stack(&poppedInt));
    assert(4567 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(64 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(32 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2147483647 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(6 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(5 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(-2147483648 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(3 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(1 == poppedInt);

    // Act:
    push_stack(27);
    push_stack(92);
    push_stack(40873);
    push_stack(-2147483648);
    push_stack(985);
    push_stack(7536);
    push_stack(2147483647);
    push_stack(-328686868);
    push_stack(6473);
    push_stack(3872);

    // Assert:

    assert(0 == pop_stack(&poppedInt));
    assert(3872 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(6473 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(-328686868 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(2147483647 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(7536 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(985 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(-2147483648 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(40873 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(92 == poppedInt);

    assert(0 == pop_stack(&poppedInt));
    assert(27 == poppedInt);

    //***********************************************************************
    // Test6: Check if the stack is empty
    //***********************************************************************
    // Arrange:
    stack_init();

    // Assert:
    assert( 1 == is_stack_empty());

    //***********************************************************************
    // Test7: Check if the stack is empty (stack will contain one item )
    //***********************************************************************
    // Arrange:
    stack_init();

    // Act:
    push_stack(1);

    // Assert:
    assert( 0 == is_stack_empty());

    //***********************************************************************
    // Test8: Check if the stack is full
    //***********************************************************************
    // Arrange:
    stack_init();

    // Act:
    push_stack(1);
    push_stack(2);
    push_stack(3);
    push_stack(-2147483648);
    push_stack(5);
    push_stack(6);
    push_stack(2147483647);
    push_stack(32);
    push_stack(64);
    push_stack(4567);

    // Assert:
    assert( 1 == is_stack_full());

    //***********************************************************************
    // Test9: Check if the stack is full (will have one less item than full)
    //***********************************************************************
    // Arrange:
    stack_init();

    // Act:
    push_stack(1);
    push_stack(2);
    push_stack(3);
    push_stack(-2147483648);
    push_stack(5);
    push_stack(6);
    push_stack(2147483647);
    push_stack(32);
    push_stack(64);

    // Assert:
    assert( 0 == is_stack_full());
} 

