/*
File:			Exercise2_45.c
Author:			Henna Lehtinen
Description:	Task 4 and 5:
				Generates a random number.
				Checks whether the number is odd or even.
				Checks whether the number is divisible by 3 and 8.
				Generates and array, prints it from start to end and backwards.
				Checks whether the random number generated earlier is in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom();
void oddOrEven();
void divisibleBy();
int generateArray();



int main() {
	
	int randomNumber = 0;
	
	randomNumber = generateRandom(100);
	oddOrEven(randomNumber);
	divisibleBy(randomNumber, 3, 8);
	generateArray(10, randomNumber);

		
	return 0;
}

// Generates a random number ranging between 0 and end
int generateRandom(end) {

	int randomNumber = 0;
	time_t timeGenerator = 0;
	
	// Initialize random number generator
	srand((unsigned) time(&timeGenerator));
	
	// Create random number
	randomNumber = rand() % end;
	
	printf("The generated number is %d.\n", randomNumber);
		
	return randomNumber;
}

// Checks if a number is odd or equal
void oddOrEven(number) {
	
	if (number == 0) {
	
		printf("%d is 0, so it is neither odd or even.\n", number);
		
	} else if (number % 2 == 0) {
	
		printf("%d is an even number.\n", number);
	
	} else {
		
		printf("%d is an odd number.\n", number);	
	}
	
	return;
}


// Checks if a number is divisible by 2 other numbers (both of them)
void divisibleBy(number, divider1, divider2) {
	
	if ((number % divider1 == 0) && (number % divider2 == 0)) {
	
		printf("%d is divisible by both %d and %d.\n", number, divider1, divider2);
		
	} else {
	
		printf("%d is not divisible by both %d and %d.\n", number, divider1, divider2);		
	}
	
	return;		
}

// Task 5

// Generates an array with numbers from 0 to numberOfItems - 1 and prints the elements
// Also checks whether a number is in the array or not
int generateArray(numberOfItems, number) {
	
	int arrayOfNumbers[numberOfItems];
	
	// Fill the array with numbers from 0 to numberOfItems
	for (int i = 0; i < numberOfItems; i++) {
	
		arrayOfNumbers[i] = i;
		
		// Prints the elements from start to finish
		printf("%d ", arrayOfNumbers[i]);		
	}
	
	//Prints newline
	printf("\n");
	
	for (int i = numberOfItems - 1; i >= 0; i--) {
	
		// Prints the elements backwards
		printf("%d ", arrayOfNumbers[i]);	
	}
	
	//Prints newline
	printf("\n");


	// Checks if a number is in the array
	for (int i = 0; i < numberOfItems; i++) {
	
		if (number == arrayOfNumbers[i]) {
			
			printf("%d is in the array.\n", number);
			return 0;
			
		} 
	}
	
	printf("%d is not in the array.\n", number);	
		
			
	return 0;
}







