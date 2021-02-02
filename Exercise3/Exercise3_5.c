/*
File:			Exercise3_4.c
Author:			Henna Lehtinen
Description:	Exercise 3, Task 4: 
				Generates a random number.
				Generates the Collatz sequence for that number.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int generateRandom(int end);
void generateCollatz(int number);


int main() {
	
	int randomNumber = generateRandom(100);
	generateCollatz(randomNumber);
	
	return 0;
}



// Generates a random number ranging between 0 and end
int generateRandom(int end) {

	int randomNumber = 0;
	time_t timeGenerator = 0;
	
	// Initialize random number generator
	srand((unsigned) time(&timeGenerator));
	
	// Create random number
	randomNumber = rand() % end;
	
	printf("The generated number is %d.\n", randomNumber);
		
	return randomNumber;
}

// Generates the Collatz sequence of the given number
void generateCollatz(int number) {

	int counter = 1;
	
	if (number == 0) {
	
		printf("The number is 0 so the Collatz sequence cannot be generated\n");
		return;
	}
	
	while (number > 0) {
	
		printf("%d, ", number);
		
		if (number == 1){
		
			break;
			
		} else if (number % 2 == 0) {
		
			number = number / 2;
			
		} else {
		
			number = (3 * number) + 1;
		}
		
		counter = counter + 1;
	}
	
	printf("\nThe length of the sequence is %d\n", counter);
	return;

}






