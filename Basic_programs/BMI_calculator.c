#include <stdio.h>
/*
Author: Gideon Obiasor

Project: Body Mass Index (BMI) calculator

Date: 18th June, 2022

Level: Beginner
*/

int main()
{
	int age;
	double weight, height, heightSquare, BMI;
	
	printf ("Enter your age: ");
	scanf ("%d", &age);
	printf ("Enter your weight in kg: ");
	scanf ("%lf", &weight);
	printf ("Enter your height in meters:  ");
	scanf ("%lf", &height);
	
	heightSquare = height * height;
	BMI = weight / heightSquare;
	
	printf ("You are %d years old and your BMI is: %.2lf\n", age, BMI);
	
	if(BMI<18.5)
	{
		printf("Remark:  Underweight");
	}
	else if (BMI>=18.5 && BMI<=24.9)
	{
		printf("Remark: Normal weight");
	}
	else if (BMI>=25 && BMI<=29.9)
	{
		printf("Remark: Overweight");
	}
	else if (BMI>=30 && BMI<=34.9)
	{
		printf("Remark: Obese class I");
	}
	else if(BMI>=35 && BMI<=39.9)
	{
		printf("Remark: Obese class II");
	}
	else
	{
		printf("Remark: Obese class III or morbid obesity");
	}
		
	printf ("\nThank you for using our BMI calculator\n");
	
	return 0;
}
