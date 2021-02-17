/*
Title: Exercise 5, Task 4
Author: Henna Lehtinen
Description: 
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>

#define SIZE 10


void printElements(int array[], int arraySize);
int *fillArray(int emptyArray[], int arraySize);
int generateRandom(int number1, int number2);


int main() {
	int array[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *arrayPointer = NULL;

	arrayPointer = fillArray(array, SIZE);
	printElements(arrayPointer, SIZE);

	return 0;	
}


// Prints elements of a given array
void printElements(int array[], int arraySize) {
	
	for (int i = 0; i < arraySize; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return;
}


// Fills an empty array with random integers in range (0, 1000000)
int *fillArray(int emptyArray[], int arraySize) {

	for (int i = 0; i < arraySize; i++) {
			
		emptyArray[i] = generateRandom(0, 1000000);
		sleep(1);
	}
	return emptyArray;		
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









