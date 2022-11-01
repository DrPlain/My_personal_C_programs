#include <stdio.h>

void print_array(int *array, int size)
{
    int i = 0;   
    while (i < size)
    {
        printf("%d ", array[i]);
        i++;
    }
    putchar('\n');
}