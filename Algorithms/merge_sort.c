#include <stdio.h>
#include "algorithm.h"

int main(void)
{
    int A[] = {2,6,8,3,7,1,11,8,21,34};
    int lb, ub, i;
    lb = 0;
    ub = (sizeof(A) / sizeof(A[0])) - 1;
    mergeSort(A, lb, ub);
    for (i = lb; i < ub + 1; i++)
    {
        printf("%d ", A[i]);
    }
    putchar('\n');

    
    return 0;
}

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

    for (k = lb; k <= ub; i++)
    {
        A[k] = B[k];
        k++;
    }
}