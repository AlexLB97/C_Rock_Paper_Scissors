#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_rng(void);
void rock_paper_scissors(void);

void Version(void)
{
	printf("Lab07 version 1 ");
	printf("Author(s) ");
	printf(" Alex Bourdage ");
	printf("\n");
}

int main(void) // DO NOT ALTER THIS FUNCTION
{
	Version();
	initialize_rng();
	rock_paper_scissors();

	return 0;
}
void initialize_rng(void) // DO NOT ALTER THIS FUNCTION
{
	//This sets the seed for the random number generator.
	//This need only be done once in the program.
	srand((unsigned)time(NULL));
}
void rock_paper_scissors(void)
{
	int num;
	int scores[3] = {0, 0, 0};
	char choice;
	char stringChoices[5][10] = {"ROCK", "PAPER", "SCISSORS", "LIZARD", "SPOCK"};
	int cpuChoice;
	int choiceInt;
	float winPercent;
	int winRound;

	while (choice != 'Q')
	{
		printf("human: %6d\n", scores[0]);
		printf("computer: %3d\n", scores[1]);
		printf("ties: %7d\n", scores[2]);
		printf("Please enter R for Rock, P for Paper, S for Scissors, L for Lizard, V for Spock, or Q to Quit:  ");
		scanf(" %c", &choice);
		if (
			choice == 'R' 
			|| 
			choice == 'P' 
			|| 
			choice == 'S' 
			|| 
			choice == 'L' 
			|| 
			choice == 'V'
			)
		{
			cpuChoice = rand() % 5;
			if (choice == 'R')
			{
				choiceInt = 0;
			}
			else if (choice == 'P')
			{
				choiceInt = 1;
			}
			else if (choice == 'S')
			{
				choiceInt = 2;
			}
			else if (choice == 'L')
			{
				choiceInt = 3;
			}
			else
			{
				choiceInt = 4;
			}

			printf("human: %s\n", stringChoices[choiceInt]);
			printf("computer: %s\n", stringChoices[cpuChoice]);

			if (choiceInt == cpuChoice)
			{
				scores[2] = scores[2] + 1;
				printf("no one won!\n\n");
			}
			else if (
					choiceInt == 0 && (cpuChoice == 2 || cpuChoice == 3) 
					|| 
					choiceInt == 1 && (cpuChoice == 0 || cpuChoice == 4) 
					|| 
					choiceInt == 2 && (cpuChoice == 1 || cpuChoice == 3) 
					|| 
					choiceInt == 3 && (cpuChoice == 1 || cpuChoice == 4) 
					|| 
					choiceInt == 4 && (cpuChoice == 2 || cpuChoice == 0)
					)
			{
				scores[0] = scores[0] + 1;
				printf("human won!\n\n");
			}
			else
			{
				scores[1] = scores[1] + 1;
				printf("computer won!\n\n");
			}
		}
		else if (choice == 'Q')
		{
			winRound = (int)(((double)scores[0] / ((double)scores[0] + (double)scores[1] + (double)scores[2])) * 1000 + 0.5);
			winPercent = (float)winRound / (float)10;
			printf("human win percentage: %.1f%% \n", winPercent);
		}
		else
		{
			printf("Your entry is incorrect. Try again.\n");
		}
	};
}
