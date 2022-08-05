#include <stdio.h>
#include <stdlib.h>

/**
 * struct student - Data structure to store student's name, maths and English scores
 *
 * @name: Name of student
 *
 * @maths: Maths score
 *
 * @English: English score
 *
 * Description: Uses an array to store data of n number of students inputed at run time
 * using Dynamic memory allocation.
 */

typedef struct student
{
	char name[20];
	float maths;
	float english;
} student;

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
 
int main(void)
{
	int i, n;
	student *ptr; /*Pointer to struct student*/
	
	printf("Enter the number of students:");
	scanf("%d", &n);
	
	ptr = malloc(sizeof(ptr) * n);
	if (ptr == NULL)
	{
		printf("\nFailure ti allocate memory by malloc\n");
		return (1);
	}
	
	for (i = 0; i < n; i++)
	{
		printf("\nEnter data for student %d\n", i + 1);
		printf("Name: ");
		scanf("%s", ptr[i].name);
		printf("Maths score: ");
		scanf("%f", &ptr[i].maths);
		printf("English score: ");
		scanf("%f", &ptr[i].english);
	}
	
	printf("\nThe values of the students are as below\n");
	printf("Name\tMaths\tEnglish\n");
	
	for (i = 0; i < n; i++)
	{
		printf("%s\t%.2f\t%.2f\n", ptr[i].name, ptr[i].maths, ptr[i].english);
	}
	
	return 0;
}
