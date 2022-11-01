#include <stdio.h>
#include "algorithm.h"

int main(void)
{
    int A[] = {2,6,8,3,7,1,11,8,21,34};
    int lb, ub, i, size;
    lb = 0;
    size = (sizeof(A) / sizeof(A[0]));
    ub = size - 1;

    mergeSort(A, lb, ub);
    print_array(A, size);
    return 0;
}

/*
 * mergeSort - function that recursively divides the array into
 * sorted sub-arrays and merges the sorted sub-arrays
 * @A: Array to be sorted
 * @lb: lower boundary of array
 * @ub: Upper boundary of array
 * Return: void
 */
void mergeSort(int *A, int lb, int ub)
{
    int mid;

    if (lb < ub) /*Exit case: Array contains more than one element*/
    {
        mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

/*
 * merge - Merges the sorted sub-array
 * @A: Main array
 * @lb: Lower boundary of array
 * @mid: Mid index of array
 * @ub: Upper boundary of array
 * Return: void
 */
void merge(int *A, int lb, int mid, int ub)
{
    int B[ub + 1]; /*Decare an array to store sorted elements*/
    int i, j, k;

    i = lb; /*Loop counter for left sub array*/
    j = mid + 1; /*Loop counter for right sub array*/
    k = lb; /*Loop counter for array B*/

    while (i <= mid && j <= ub)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while ( i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }
    /*Copy the new sorted array into initial array*/
    for (k = lb; k <= ub; i++)
    {
        A[k] = B[k];
        k++;
    }
}