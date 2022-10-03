#include "stack.h"

Stack *createStack(unsigned int arr_size)
{
    int *array;

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return (NULL);
    array = malloc(sizeof(int) * arr_size);
    stack->top = -1;
    stack->array = array;
    return (stack);
}

void push(int item)
{
    if (stack->top == size - 1)
        printf("Overflow condition\n");
    else
    {
        stack->top++;
        stack->array[stack->top] = item;
        printf("%d was pushed succesfully\n", item);
    }
}

int pop()
{
    int item;

    if (stack->top == -1)
    {
        printf("Underflow condition\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        item = stack->array[stack->top];
        --stack->top;
        printf("%d was popped succesfully\n", item);
        return (item);
    }
}
void display(){
    int i, top_ = stack->top;
    if (stack->top == -1)
        printf("Empty stack\n");
    else{
        for (i = stack->top; stack->top >= 0; stack->top--)
            printf("%d\n", stack->array[stack->top]);
            //putchar(stack->array[stack->top]);
        stack->top = top_; 
    }
        
}
