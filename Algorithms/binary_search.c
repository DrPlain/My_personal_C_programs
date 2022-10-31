#include <stdio.h>

int main(void)
{
    int arr[] = {2, 4, 6, 8, 13, 16, 23, 45, 67, 80};
    int l, r, n, i, num, mid;
    n = sizeof(arr) / sizeof(arr[0]);
    l = 0;
    r = n - 1;
    printf("Enter number to search: ");
    scanf("%d", &num);

    while (l < r)
    {
        mid =  (l + r) / 2;
        if (num == arr[mid])
        {
            printf("\nFound number at index %d\n", mid);
            return 0;
        }
        else if (num > arr[mid])
        {
            l = mid + 1;   
        }
        else if (num < arr[mid])
        {
            r = mid - 1;
        }
    }
    printf("\nNumber not found\n");
}
