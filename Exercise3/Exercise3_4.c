/*
File:			Exercise3_4.c
Author:			Henna Lehtinen
Description:	Exercise 3, Task 4: 
				Generates a random number.
				Checks if the number belongs in the Fibonacci sequence.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int generateRandom(int end);
void checkFibonacci(int number);

int main() {

	int randomNumber = generateRandom(100000);
	checkFibonacci(randomNumber);
	
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

// Checks if a given number is in the Fibonacci sequence
void checkFibonacci(int number) {
	
	int fibonacci = 0;
	int fibo1 = 0;
	int fibo2 = 1;
	int check = 0; // used to check if the number is in the Fibonacci sequence
	
	while (number >= fibonacci) {
		
		if (number == fibonacci) {
			printf("The number is in the Fibonacci sequence\n");
			check = 1;
		}
		
		fibonacci = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = fibonacci;
	}
	
	if (check == 0) {
		printf("The number is not in the Fibonacci sequence\n");
	}
	return;

}
















