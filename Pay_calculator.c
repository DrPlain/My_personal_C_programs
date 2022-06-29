#include <stdio.h>
/*
Author: Gideon Obiasor
Date: 29th June, 2022

Project: A C program that calculates weekly pay and gives an output of gross pay, taxes and net pay

Tax rate: 
	15% of the first $300
	20% of the next 150
	25%  of the rest
	
Assumption:
	Basic pay rate= rate per hour
	Over time (in excess of 40hours) = time and a half
*/

int main()
{
    double hours, gross, net, tax, rate;
    
    printf("Enter the number of hours worked in a week: ");
    scanf("%lf", &hours);
    printf("Enter your pay per hour: ");
    scanf("%lf", &rate);
    
    if(hours<=40)
    {
    	gross = hours * rate;
    	printf ("Your gross pay is $%.2lf per week\n", gross);
    
    	if(gross<=300)
    	{
    		tax = 0.15*gross;
    		net = gross - tax;
    		printf("Your tax is $%.2lf\n", tax);
    		printf("Your net pay is $%.2lf\n", net);
    	}
    		else if(gross>300 && gross<=450)
    		{
    			tax = (0.15*gross) + (0.2*(gross-300));
    			net = gross - tax;
    			printf("Your tax is $%.2lf\n", tax);
    			printf("Your net pay is $%.2lf\n", net);
    		}
    		else
    		{
    		tax = ((0.15*gross) + (0.2*(gross-300)) + (0.25*(gross-450)));
    		net = gross - tax;
    		printf("Your tax is $%.2lf\n", tax);
    		printf("Your net pay is $%.2lf\n", net);
    		}
    }
   
    	 else
    {
    	gross = (hours * rate);
    	gross = gross + gross/2;
    	printf("Your gross pay is $%.2lf per week\n", gross);
    	if(gross<=300)
    	{
    		tax = 0.15*gross;
    		net = gross - tax;
    		printf("Your tax is $%.2lf\n", tax);
    		printf("Your net pay is $%.2lf\n", net);
    	}
    		else if(gross>300 && gross<=450)
    		{
    			tax = (0.15*gross) + (0.2*(gross-300));
    			net = gross - tax;
    			printf("Your tax is $%.2lf\n", tax);
    			printf("Your net pay is $%.2lf\n", net);
    		}
    		else
    		tax = ((0.15*gross) + (0.2*(gross-300)) + (0.25*(gross-450)));
    		net = gross - tax;
    		printf("Your tax is $%.2lf\n", tax);
    		printf("Your net pay is $%.2lf\n", net);
    }
    return 0;
}
