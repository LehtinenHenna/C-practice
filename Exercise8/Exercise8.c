/* 
 * File:   		Exercise8.c
 * Author:		Henna Lehtinen
 * Description: Main function implementation.
 				Generates an array with 10 random numbers and prints it out.
 				Gets a number from a user and checks if the number is found in the array.
 				Fills an array from a file of numbers.
 				Finds the biggest sum of five adjacent numbers in the array. 				
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Array.h"
#include "Calculation.h"
#include "Finder.h"

#define SIZE 10

int main () {
	
	int *arrayPointer = NULL;
	char userInput[4] = {0, 0, 0, 0}; // number 0 in ASCII table is NULL
	int userInputNumber = 0;
	int *findNumberPointer = NULL;
	int *fileArrayPointer = NULL;
	int fileArraySize = 0;
	int *fileArraySizePointer = NULL;
	fileArraySizePointer = &fileArraySize;

	
	// dynamically allocate memory for an array with 10 elements
	arrayPointer = ((int*) calloc(SIZE, sizeof(int)));
	
	// in case dynamic memory allocation was not successful, pointer will point to NULL
	if (arrayPointer == NULL) {
		
		printf("Dynamic memory allocation did not succeed.\n");
		return 0;

	} else {
		
		printf("Dynamic memory allocation succeeded.\n");
		
		// if the dynamic memory allocation was successful, 
		// fill the array with random numbers ranging between 0 and 100
		for (int i = 0; i < SIZE; i++) {
		
			*arrayPointer = generateRandom(0, 100);
			arrayPointer++;
		}	
	}
	// move the arrayPointer back to the beginning of the array
	arrayPointer = arrayPointer - SIZE;
	
	// print the array using a function which is implemented at Array.c
	printArray(arrayPointer, SIZE);
	
	// get user input to pass later to the findNumber function implemented in Finder.c
	printf("\nEnter an integer between 0 and 100: ");
	scanf("%s", userInput);
	printf("\n");
	
	// checking if the userInput is an integer by checking the ASCII values
	for (int i = 0; i < 4; i++) {
		
		// in ASCII values for characters 0...9 are 48...57.
		// for some reason when user inputs a value it reads a NULL value in the next slot of the array
		// for instance if user inputs 9, the (int) values in the array will be {57, 0, 48, 48, 48}
		if (((int) userInput[i] < 48 || (int) userInput[i] > 57) && (int) userInput[i] != 0) {
			
			printf("Invalid input.\n");
			return 0;
		} 
	}
	
	// turning the userInput into an integer and saving it in userInputNumber
	sscanf(userInput, "%d", &userInputNumber);
	
	// checking if the userInputNumber is within the given range 0...100
	if (userInputNumber < 0 || userInputNumber > 100) {
	
		printf("The number is not within the given range.\n");
		return 0;
	}
	
	
	findNumberPointer = findNumber(arrayPointer, SIZE, userInputNumber);
	
	// if findNumber function is not successful it returns a NULL pointer
	if (findNumberPointer != NULL) {
		
		printf("The number %d was found at memory address %p in the array.\n", *findNumberPointer, findNumberPointer);
	 	
	} else {
		
		printf("The number %d was not found in the array.\n", userInputNumber);	
	}

	fileArrayPointer = fillArrayFromFile(fileArrayPointer, "Numbers.txt", fileArraySizePointer);
	
	printArray(fileArrayPointer, fileArraySize);
	findBiggestSum(fileArrayPointer, fileArraySize);
	
	// free the dynamically allocated memory after use
	free(arrayPointer);
	free(fileArrayPointer);
		
	return 0;
}


