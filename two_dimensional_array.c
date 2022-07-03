#include <stdio.h>
#include <stdlib.h>

/**
 * main - A two-dimesional array storing montly rainfall (in inches) over 5 years.
 *
 * Return: Always 0 (Success)
 *
 * Author: Gideon Obiasor
 * 
 * Date: 3rd of July, 2022
 *
 * Objective: Learning how to access and manipulate elements of two-dimensional arrays.
 */
 
int main(void)
{
	float rainfall [5][12] = {
		{25.66, 12.55, 65.76, 45.66, 67.12, 34.76, 36.67, 56.78, 67.98, 45.56, 56.54, 65.88},
		{12.67, 54.54, 45.77, 56.88, 78.34, 45.65, 65.98, 67.77, 56.10, 45.65, 80.34, 67.89},
		{40.88, 50.78, 35.87, 67.88, 89.94, 67.45, 56.78, 54.76, 32.67, 76.87, 67.89, 80.32},
		{23.43, 34.12, 45.32, 45.56, 78.55, 67.89, 65.32, 34.54, 65.56, 78.66, 98.54, 50.81},
		{45.65, 59.11, 32.55, 45.87, 78.65, 99.66, 55.61, 36.91, 66.42, 67.63, 70.21, 67.09}
	};
			
			int year;
			int month;
			float sumRainfallA = 0;
			float sumRainfallB = 0;
			float sumRainfallC = 0;
			float sumRainfallD = 0;
			float sumRainfallE = 0;
			float avgRainfall = 0;
			float monthTotal;
			float janTotal;
			float febTotal;
			float marTotal;
			float aprTotal;
			float mayTotal;
			float junTotal;
			float julTotal;
			float augTotal;
			float sepTotal;
			float octTotal;
			float novTotal;
			float decTotal;

			for (year = 0; year< 5; year++)
			{
				for (month = 0; month<5; month++)
				{
					if (year == 0)
						sumRainfallA += rainfall [year][month];
					else if (year ==1)
						sumRainfallB += rainfall [year][month];
					else if (year ==2)
						sumRainfallC += rainfall [year][month];
					else if (year ==3)
						sumRainfallD += rainfall [year][month];
					else if (year ==4)
						sumRainfallE += rainfall [year][month];
				}
			}
			
			printf("TABLE 1\n\n");
			printf("YEAR\t\SUM OF RAINFALL (inches)       AVERAGE\n\n");
			
			printf("2015\t\t%.2f\t\t\t%.2f\n", sumRainfallA, sumRainfallA/12);
			printf("2016\t\t%.2f\t\t\t%.2f\n", sumRainfallB, sumRainfallB/12);
			printf("2017\t\t%.2f\t\t\t%.2f\n", sumRainfallC, sumRainfallC/12);
			printf("2018\t\t%.2f\t\t\t%.2f\n", sumRainfallD, sumRainfallD/12);
			printf("2019\t\t%.2f\t\t\t%.2f\n", sumRainfallE, sumRainfallE/12);
			
				avgRainfall = (sumRainfallA +sumRainfallB + sumRainfallC + sumRainfallD + sumRainfallE) /60;
				
			printf("\nThe average rainfall in 5 years is %.2f\n\n\n", avgRainfall);
		
			printf("TABLE 2\n");	printf("\nJan\tFeb\tMarch\tApril\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n\n");
		
			
			for (month = 0; month < 12; month++)
			{
				for (year = 0; year <5; year++)
				{
					if (month == 0)
					janTotal += rainfall [year][month];
					else if (month == 1)
					febTotal += rainfall [year][month];
					else if (month == 2)
					marTotal += rainfall [year][month];
					else if (month == 3)
					aprTotal += rainfall [year][month];
					else if (month == 4)
					mayTotal += rainfall [year][month];
					else if (month == 5)
					junTotal += rainfall [year][month];
					else if (month == 6)
					julTotal += rainfall [year][month];
					else if (month == 7)
					augTotal += rainfall [year][month];
					else if (month == 8)
					sepTotal += rainfall [year][month];
					else if (month == 9)
					octTotal += rainfall [year][month];
					else if (month == 10)
					novTotal += rainfall [year][month];
					else if (month == 11)
					decTotal += rainfall [year][month];
				}
			}
			
			printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
			 janTotal, febTotal, marTotal, aprTotal, mayTotal,junTotal, julTotal, augTotal, sepTotal, octTotal, novTotal, decTotal);
			 
			 printf("\n%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n\n",
			 janTotal/5, febTotal/5, marTotal/5, aprTotal/5, mayTotal/5, junTotal/5, julTotal/5, augTotal/5, sepTotal/5, octTotal/6, novTotal/5, decTotal/5);
			
			printf("KEY:\nROW 1 = Sum of rainfall per month\nROW 2 = Average of rainfall per month\n");
			return 0;
}
    	
