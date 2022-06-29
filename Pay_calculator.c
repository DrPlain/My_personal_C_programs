#include <stdio.h>
/*
Author: Gideon Obiasor
Date: 29th June, 2022

Project: A C program that calculates weekly pay and gives an output of gross pay, taxes and net pay

Tax rate: 
	15% of the first $300
	20% of the next $150
	25%  of the rest
	
Assumption:
	Basic pay rate is in per hour
	Over time (in excess of 40hours) = rate * 1.5 per hour
*/

/*Declaring constants*/
# define TAXRATE_300 .15 
# define TAXRATE_150 .20
# define TAXRATE_REST .25

int main(void)
{
	double hours;
	double gross;
	double net;
	double tax;
	double rate;
	
	printf("Enter the number of hours you worked this week: ");
	scanf("%lf", &hours);
	printf("Enter your pay per hour: ");
	scanf("%lf", &rate);
    
   if(hours<=40)
    {
    	gross = hours * rate;
    }
    	 else
    {
    	gross = (hours * rate);
    	gross  +=(hours-40)*1.5; //+= means gross = gross +
    }
    
//calculating tax
    if(gross<=300)
    	{
    		tax = gross * TAXRATE_300;
    	}
    		else if(gross>300 && gross<=450)
    		{
    			tax = gross * TAXRATE_300;
    			tax += (gross-300) * TAXRATE_150;
    		}
    		else
    		{
    			tax = gross * TAXRATE_300;
    			tax += (gross-300) * TAXRATE_150;
    			tax += (gross-450) * TAXRATE_REST;
    		}

//Calculating net pay
	net = gross - tax;
	
//Printing output
    		printf("Your gross pay this week is $%.2lf\n", gross);
    		printf("Your tax this week is $%.2lf\n", tax);
    		printf("Your net pay this week is $%.2lf\n", net);
    
    return 0;
}
