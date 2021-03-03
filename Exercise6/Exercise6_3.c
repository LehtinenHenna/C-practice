/*
Title: Exercise 6, Task 3
Author: Henna Lehtinen
Description: Fills an array with random numbers and prints them.
			 Arranges the elements of the array from largest to smallest and prints them.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>

#define SIZE 10

void arrayPrinter(int *arrayPointer, int arraySize);
int *fillArrayRandomly(int *arrayPointer, int arraySize);
int generateRandom(int number1, int number2);
int *arrangeArray(int array[], int arraySize);



int main() {
	

	int zeroArray[SIZE] = {0};
	int *arrayPointer = NULL;
	
	arrayPointer = &zeroArray[0];
	
	// Fill the array with random numbers and print it
	arrayPointer = fillArrayRandomly(arrayPointer, SIZE);
	printf("The array filled with random numbers:\n");
	arrayPrinter(arrayPointer, SIZE);
	
	printf("\n");
	
	// Arrange the array and print it
	arrayPointer = arrangeArray(zeroArray, SIZE);
	printf("The array arranged from largest to smallest:\n");
	arrayPrinter(arrayPointer, SIZE);
	
	return 0;
}


// Prints out the elements of an array
void arrayPrinter(int *arrayPointer, int arraySize) {
	
	for(int i = 0; i < arraySize; i++) {
		
		printf("Item %d of the array: %d\n", i+1, *arrayPointer);
		arrayPointer++;
	}
	printf("\n");

	return;
}


// Fills an empty array with random numbers
int *fillArrayRandomly(int *arrayPointer, int arraySize) {
	
	int randomNumber = 0;
	
	for(int i = 0; i < arraySize; i++) {
		randomNumber = generateRandom(0, 1000000);
		sleep(1);
		*arrayPointer = randomNumber;
		arrayPointer++;
	
	}
	arrayPointer = arrayPointer - arraySize;
	return arrayPointer;
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


// Arranges elements in an array from largest to smallest
int *arrangeArray(int array[], int arraySize) {

	int temp = 0;
	
	for(int i = 0; i < arraySize - 1; i++) {
		
		for(int j = i+1; j < arraySize; j++) {
		
			if(array[i] < array[j]) {
			
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;	
			}	
		}
	}		
	return array;
}








