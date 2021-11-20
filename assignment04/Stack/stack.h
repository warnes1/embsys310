/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

void stack_init(void);
int push_stack(int data);
int pop_stack(int* data);
int is_stack_empty(void);
int is_stack_full(void);

#endif
