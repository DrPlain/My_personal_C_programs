#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include <stdio.h>

#define size 50

typedef struct stacks
{
    int top;
    int *array;
} Stack;

Stack *stack;

Stack *createStack(unsigned int arr_size);
void push(int item);
int pop();
void display();

#endif