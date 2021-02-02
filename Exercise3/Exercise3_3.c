/*
File:			Exercise3_3.c
Author:			Henna Lehtinen
Description:	Exercise 3, Task 3: 
				Sums all numbers between 1 and 100.
				Sums all even numbers between 1 and 1000.
				Generates a random number.
				Takes the random number and multiplies it by itself. Stops before overflow.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void sumNumbers(int range);
void sumEvenNumbers(int range);
int generateRandom(int end);
void multiplyUntilOverflow(int number);


int main () {

	sumNumbers(10);
	sumEvenNumbers(10);

	printf("Size of Integer data type: %lu\n", sizeof(int));
	
	int randomNumber = 0;
	while (randomNumber < 2) {
	
		randomNumber = generateRandom(20);
		sleep(1);
	}

	multiplyUntilOverflow(randomNumber);
	
	
	return 0;
}

// 3 A
// Sums numbers all between 1 and range (range included), prints the result
void sumNumbers(int range) {
	
	int sum = 0;
	
	for (int i = 1; i <= range; i++) {
		sum = sum + i;
	}
	
	printf("Sum of numbers between 1 and %d: %d\n", range, sum);
	return;
}

//3 B
// Sums all even numbers between 1 and range (range included), prints the result
void sumEvenNumbers(int range) {
	
	int sum = 0;
	
	for (int i = 1; i <= range; i++) {
		
		if (i % 2 == 0) {
		
			sum = sum + i;
		}
	}
	
	printf("Sum of even numbers between 1 and %d: %d\n", range, sum);
	
	return;
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

// 3 C
// Takes a number and multiplies it by itself. Stops before overflow.
void multiplyUntilOverflow(int number){
	
	int maxNumber = 32767;
	printf("The largest integer before overflow: %d\n", maxNumber);
	
	while (number * number < maxNumber) {
	
		printf("Number to multiply with itself: %d\n", number);
		printf("%d * %d = %d\n", number, number, (number*number));
		number = number * number;
		
		sleep(1);
	
	}
	
	printf("Number at which the multiplication stopped: %d\n", number);
	return;
}
















