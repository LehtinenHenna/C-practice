/*
File:			Exercise4_5.c
Author:			Henna Lehtinen
Description:	Exercise 4, Task 5:
				Rock-paper-scissors game			
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>

int generateRandom(int number1, int number2);
int readInput();
void checkWinner(int computer, int user);



int main () {

	int computerMove = 0;
	int userMove = 0;

	printf("This is a rock-paper-scissors game. You're playing agains the computer.\n");
	computerMove = generateRandom(1,3);
	userMove = readInput();
	
	printf("Computer's move: %d. User's move: %d.\n", computerMove, userMove);
	
	checkWinner(computerMove, userMove);
	
}


// Generate a random number in range (start, end)
int generateRandom(int number1, int number2) {

	int randomNumber = 0;
	int end = 0;
	int start = 0;
	
	// Use current time as a seed for the random number generator
	srand(time(0));
	
	if (number1 > number2) {
		end = number1;
		start = number2;
	} else if (number2 > number1) {
		end = number2;
		start = number1;
	} else {
		printf("The input is invalid.\n");
		return 0;
	}
	
	// rand() generates a number between 0 and RAND_MAX,
	// but this way we can use it to generate a number in range (start, end)
	// (end - start + 1) is the RAND_MAX. Then we add start to the resulted number to get a number in the right range
	randomNumber = (rand() % (end - start + 1)) + start;
	
	return randomNumber;
}

int readInput() {

	int loopChecker = 0;
	int userInput = 0;
		
	while (loopChecker == 0) {
		printf("Enter 1 for rock, 2 for paper, or 3 for scissors: ");
		scanf("%d", &userInput);
		if (userInput == 1 || userInput == 2 || userInput == 3) {	
			loopChecker = 1;
		}		
	}
	return userInput;
}

void checkWinner(int computer, int user) {
	
	int result = 0;
				// User: rock, paper, scissors
	int winnerTable[3][3] = {{0, 1, 2}, // computer: rock
				   			 {2, 0, 1}, // computer: paper
				   			 {1, 2, 0}, // computer: scissors
				   			 };
	// winnerTable: hold information of winner with different combinations
	// User win = 1
	// Computer win = 2
	// Tie = 0
	
	result = winnerTable[computer-1][user-1];
	
	if (result == 1) {
		printf("You win!\n");
	} else if (result == 2) {
		printf("You lose!\n");
	} else {
		printf("It's a tie!\n");
	}
	return;
}



















