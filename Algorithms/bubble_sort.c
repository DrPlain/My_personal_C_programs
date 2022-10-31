#include <stdio.h>

void print_array(int *array, int size);
void bubble_sort(int *array, int size);
void improved_bubble_sort(int *array, int size);

int main(void)
{
    int size;
    int array[] = {3,6,1,8,2,9,4, 56, 34, 21, 34, 7, 76, 34};

    size = sizeof(array) / sizeof(array[0]);
    improved_bubble_sort(array, size);
    
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
    int i, j, pass, tmp;

    pass = size - 1;

        /*Outer loop is for number of passes in n sized array which is 'n - 1'*/
        for (i = 0; i < pass; i++)
        {
            /*Inner loop controls the number of comparisons for each pass*/
            /*Improvement is on the fact that number of comparisons in each pass*/
            /*is == pass - i*/
            for (j = 0; j < pass - i; j++)
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
    