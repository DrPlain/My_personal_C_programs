#include <stdio.h>
#include <time.h>
#include "algorithm.h"

int main()
{
    clock_t begin = clock();
    int size;
    int array[] = {50,2,6,8,3,7,1,0,11,8,21,34};
    size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);
    print_array(array, size);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_spent);
}

/*
 * selectionSort - Sorts an array using selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */

void selectionSort(int *array, int size)
{
    int i, j, pass, min, tmp;
    
    pass = size - 1;
    for (i = 0; i < pass; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i) /*If minimum value changed then swap*/
        {
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}