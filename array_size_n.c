#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Creates an array of size n where n is defined by the user
 *
 * Return: 0 Success
 */

int main(void)
{
	/*To create an int array of n size entered from stdin*/
	int n;
	
	printf("Please enter size of array: ");
	scanf("%d", &n);
	
	/* Allocating memory to store array of n size*/
	int *A = (int*) malloc(n*sizeof(int)); 
	
	for (int i = 0; i < n; i++)
		A[i] = i + 1; /*same as *(A+i) = 100+i*/
	
	for (int i = 0; i < n; i++)
	{
		printf("%d", *A++);
		
		if (i != n - 1)
		{
			printf(", ");
		}
	}
	return 0;
}
