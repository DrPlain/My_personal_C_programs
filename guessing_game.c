/**
 *Author: Gideon Obiasor
 *
 *Program: Guess a secret number game
 *
 *Date: 30th June, 2022
 *
 *main = Entry point
 *
 *Return: Always 0 (Success)
 */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main(void)
{
	unsigned int guess;
	int attempts;
	int hidden_num;

	/*Prompting the user*/
	printf("This is a guessing game and you have 5 attempts\n");
	printf("I have chosen a number between 0 - 20 which you must guess correctly\n");

	/*Randon number generator*/
	time_t t;
	srand((unsigned int)time(&t));
	hidden_num = rand() % 21;
	
	/*Pre-test while loop*/
	attempts = 5;

	while (attempts <= 5 && attempts != 0)
	{
		printf("\nPlease enter your guess: ");
		scanf("%d", &guess);
	
		attempts = attempts - 1;
		if(guess >= 0 && guess <= 20)
		{
			if(hidden_num<guess)
			{
				printf("You entered %d and your guess is wrong\n", guess);
				printf("My hidden number is less than your guess\n");
				printf("You have %d attempt(s) left\n", attempts);
			}
			else if (hidden_num>guess)
			{
				printf("You entered %d and your guess is wrong\n", guess);
				printf("My hidden number is greater than your guess\n");
				printf("You have %d attempt(s) left\n", attempts);
			}
			else if (hidden_num == guess)
			{
				printf("Congratulations, your guess was right!\n");
			break;
			}
		}
		else
		{
			printf("You entered an invalid guess, your guess must be from 0 to 20\n");
			printf("You have %d attempt(s) left!\n", attempts);
			}
	while(attempts == 0)
	{
		printf("\nYou lost! The secret number was %d\n", hidden_num);
		break;
	}
	}
	return 0;
}
