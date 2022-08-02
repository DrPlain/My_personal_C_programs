#include <stdio.h>

/**
 * main - A simple four-operand calculator developed the concept of function pointers
 *
 * Return: 0 on sucess
 *
 * Author: Gideon Obiasor
 */

void add(float a, float b){
	printf("%f + %f= %f", a, b, a+b);
}
void sub(float a, float b){
	printf("%f - %f = %f", a, b, a-b);
}
void mul(float a, float b){
	printf("%f * %f = %f", a, b, a*b);
}
void div(float a, float b){
	if (b == 0)
		printf("Undefined");
	else
	printf("%f / %f = %f", a, b, a/b);
}
	
int main(int argc, char *argv[])
{
	int ch;
	float a, b;
	void (*fptr[4])(float, float) = {add, sub, mul, div};
	
	while (1)
	{
		printf("\nPlease kindly enter the operation to perform\n");
		printf("\n1 for addition\n2 for substraction\n3 for multiplication\n4 for division\n");
		scanf("%d", &ch);
		
		if (ch < 1 || ch > 4)
			{
				printf("Invalid selection\n");
				continue;
			}
		
		ch = ch - 1; /*To align with array indexing*/
		
		printf("Enter first number: ");
		scanf("%f", &a);
		printf("Enter second number: ");
		scanf("%f", &b);
		putchar('\n');
		
		fptr[ch](a, b);
	}
	return 0;
}
