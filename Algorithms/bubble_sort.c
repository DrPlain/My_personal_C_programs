#include <stdio.h>
#include "algorithm.h"
#include <time.h>

int main(void)
{
    clock_t begin = clock();
    int size;
    int array[] = {50,2,6,8,3,7,1,0,11,8,21,34};

    size = sizeof(array) / sizeof(array[0]);
    improved_bubble_sort(array, size);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f seconds\n", time_spent);
}

void bubble_sort(int *array, int size)
/*
 * bubble_sort - Sorts an array of integers using bubble sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
{
    int i, j, pass, tmp;

    pass = size - 1;

        /*Outer loop is for number of passes in n sized array which is 'n - 1'*/
        for (i = 0; i < pass; i++)
        {
            /*Inner loop controls the number of comparisons for each pass*/
            for (j = 0; j < pass; j++)
            {
                if (array[j] > array[j + 1])
                {
                    tmp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = tmp;
                }
            }
        }
        print_array(array, size);
}

void improved_bubble_sort(int *array, int size)
/*
 * improved_bubble_sort - Sorts an array of integers using bubble sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
{
    int i, j, pass, tmp, flag;

    pass = size - 1;

        /*Outer loop is for number of passes in n sized array which is 'n - 1'*/
        /*Inner loop controls the number of comparisons for each pass*/
        /*1. Improvement is on the fact that number of comparisons in each pass*/
        /*is == pass - i*/
        /*2. Loop breaks if array gets sorted before reaching the last pass*/
        /* Any pass without a swap means the array is already sorted*/
        for (i = 0; i < pass; i++)
        {
            flag = 0;
            for (j = 0; j < pass - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    tmp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = tmp;
                    flag = 1; /*set to 1 to indicate that swapping has occurred*/
                }
            }
            if (flag == 0)
                break;
        }
        print_array(array, size);
}
   