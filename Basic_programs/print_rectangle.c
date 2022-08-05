#include <stdio.h>

/**
 * A program that takes height and breadth from user and prints rectangle.
 *
 * @n: Indicate number of rows
 * Return: 0 success
 */

int main(void)
{
	/* Rectangle pattern 1*/
	int height, breadth, i, j;
	
	printf("Enter height: ");
	scanf("%d", &height);
	printf("\nEnter breadth: ");
	scanf("%d", &breadth);
	
	for (i = 1; i <= height; i++)
	{
		for (j = 1; j <= breadth; j++)
		{
			if (i ==1 || i == height || j == 1|| j == breadth )
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
