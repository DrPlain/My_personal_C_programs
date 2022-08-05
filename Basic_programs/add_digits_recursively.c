#include <stdio.h>

/**
 * main - A program that takes an input integer, evaluates 
 * the sum of the digits recursively and prints the sum
 * 
 * sumDigits - Adds digits of an integer recursively
 *
 * Return: 0 success
 */

int sumDigits(int n)
{
	if (n == 0)
		return 0;
	else
	return (n % 10 + sumDigits(n/10));
}
	

int main(int argc, char *argv[])
{
	int n;
	int sum;
	printf("Enter an integer: ");
	scanf("%d", &n);
	
	sum = sumDigits(n);
	
	printf("\nThe sum of the digits of %d is %d\n", n, sum);
	return 0;
}
