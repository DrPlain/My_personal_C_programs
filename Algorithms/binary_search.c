#include <stdio.h>
#include "algorithm.h"

int main(void)
{
    int arr[] = {2, 4, 6, 8, 13, 16, 23, 45, 67, 80};
    int size, num;

    size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter number to search: ");
    scanf("%d", &num);
    binary_search(arr, size, num);

    return (0);
}

void binary_search(int *array, int size, int find_num)
/*
 * binary_search - finds a number in array using binary search algorithm
 * @array: Array to be searched
 * @size: Size of the array
 * @find_num: Number to be searched
 * Return: Nothing
 */
{
    int l = 0, r = size - 1, mid;

    while (l < r)
    {
        mid =  (l + r) / 2;
        if (find_num == array[mid])
        {
            printf("\nFound number at index %d\n", mid);
            return;
        }
        else if (find_num > array[mid])
        {
            l = mid + 1;
        }
        else if (find_num < array[mid])
        {
            r = mid - 1;
        }
    }
    printf("\nNumber not found\n");
}
