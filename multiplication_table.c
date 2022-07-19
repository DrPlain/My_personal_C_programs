#include <stdio.h>
#include <stdlib.h>

/**
 * main - Takes an input integer from user and prints 
 * multiplication table of the integer unless its a negative number or zero.
 *
 * Return: 0 Success
 */

int main(void)
{
	int n, i =1;
	
	while (1)
	{
		printf("Enter number you want to see the multiplaction table: ");
		scanf("%d", &n);
	
		if (n<= 0 || sizeof(n) != 4)
		break;
		
		for (int i = 1; i <=12; i++)
		{
			printf("%d x %d = %d\n", n, i, n*i);
		}
		putchar('\n');
	}
	printf("Invalid input");
	return 0;
}
