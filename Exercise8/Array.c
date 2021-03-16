/* 
 * File:   		Array.c
 * Author: 		Henna Lehtinen
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>

#include "Array.h"

// Takes an array pointer and array size and prints the elements of the array
void printArray(int *arrayPointer, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
	
		printf("Item %d in array: %d.\n", i+1, *(arrayPointer + i));
	}
	return;
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
	
	// wait 1 second so that the seed value has time to change
	sleep(1);
	
	return randomNumber;
}
