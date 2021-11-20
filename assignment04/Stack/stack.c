//---------------------------------------------------
//
// embsys310, Fall 2021
// Homework Assignment04
// Stack routines
//
// Marion Scott Warner
//
//---------------------------------------------------
#include "stack.h"
#define STACKSIZE 10

// Array for Stack with space for 10 integers
int StackStore[STACKSIZE];

// Pointers to stack elements for pushing popping
int* tos; // Top of Stack
int* bos; // Bottom of Stack
int* sp;  // Pointer to last item pushed to stack

// STACK is full, if sp > tos;
// STACK is Empty, if sp < bos; 

// Initialize internals of the stack
void stack_init(void)
{
    tos = &StackStore[STACKSIZE -1];
    bos = &StackStore[0];
    sp  = &StackStore[0];
}

// Push integer on to stack
// If stack is full return -1 to indicate error
// Otherwise return 0 to indicate success
int push_stack(int pushed)
{
    if (sp > tos) // The stack is full
    {
        return -1;
    }
    *sp = pushed;
    sp++; // Increment to the next address to store at.
    return 0;
}

// Pop integer off of stack
// If stack is empty return -1 to indicate error
// Otherwise return 0 to indicate success
int pop_stack(int *popped)
{
    sp--;
    if( sp < bos ) //stack is empty
    {
        return -1;
    }
    *popped = *sp;
    return 0;
}

int is_stack_full(void)
{
    if (sp > tos) // The stack is full
    {
        return 1;
    }
    return 0;
}

int is_stack_empty(void)
{
    sp--;
    if( sp < bos )
    {
        sp++;
        return 1;
    }
    sp++;
    return 0;
} 
