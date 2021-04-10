/* 
 * File:   		Struct.c
 * Author:		Henna Lehtinen
 * Description: Creates an array of Orchard struct objects.
 *				Prints out the array.
 *				Validates user inputs: integers and floats
 */
 
#include "Struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10



// Creates an array of Orchard struct objects
struct Orchard *createOrchards(orchard *arrayPointer, int *arraySize) {
	
	
	char noOfOrchards[SIZE] = {0}; // used to save the user input that requires validation
	int *numberOfOrchardsPointer = NULL;
	int numberOfOrchards = 0; // used to save the validated integer value
	numberOfOrchardsPointer = &numberOfOrchards;
	
	char kgPerHarvest[SIZE] = {0}; // used to save the user input to be validated as integer before saving it in the array
	int kg = 0; // used to save the validated integer value
	int *kgPointer = NULL;
	kgPointer = &kg;
	
	char sizeInSquareKm[SIZE] = {0}; // used to save the user input to be validated as float before saving it in the array
	float size = 0; // used to save the validated float value
	float *sizePointer = NULL;
	sizePointer = &size;
	
	char temp = 0; // temp char to clear the buffer
	
	
	// ask user how many elements they want in the array
	printf("Enter the number of orchards: ");
	scanf("%s", &noOfOrchards);
	printf("\n");
	
	numberOfOrchardsPointer = validateInteger(noOfOrchards, numberOfOrchardsPointer);
	
	// if a valid integer was found in string noOfOrchards
	if (numberOfOrchards != 0) {
		
		*arraySize = numberOfOrchards;
		
		// dynamically allocate memory for the array here
		// check if allocation was successful
		arrayPointer = (orchard*)calloc(numberOfOrchards, sizeof(orchard));
		
		// if dynamic memory allocation was successful
		if (arrayPointer != NULL) {
		
			for (int i = 0; i < numberOfOrchards; i++) {
				
				// change these variables back to 0 for each round
				// in case user makes invalid input on any round after the first one
				kg = 0;
				size = 0;
				
				printf("Enter the name of the orchard: ");
				// "%[^\n]" as placeholder tells scanf to read characters until newline is found
				scanf("%c", &temp); // temp statement to clear buffer
				scanf("%[^\n]", &arrayPointer->name); 
				printf("Enter the produce: ");
				scanf("%c", &temp); // temp statement to clear buffer
				scanf("%[^\n]", &arrayPointer->produce);
			
				printf("Enter the amount of produce harvested yearly in kg: ");
				scanf("%s", &kgPerHarvest);
				printf("Enter the size of the orchard in square kilometers: ");
				scanf("%s", &sizeInSquareKm);
				
				
				kgPointer = validateInteger(kgPerHarvest, kgPointer);
				sizePointer = validateFloat(sizeInSquareKm, sizePointer);
			
			
				// validation functions return 0 if input is invalid
				if (kg != 0 && size != 0.0) {
			
					arrayPointer->kgPerHarvest = kg;
					arrayPointer->sizeInSquareKm = size;
				}
				else {
				
					arrayPointer = NULL;
					return arrayPointer;
				}				
				arrayPointer++;
			}
			arrayPointer = arrayPointer - numberOfOrchards;
		}				
	}

	return arrayPointer;
}




// Prints values of each element in an Orchard struct array
void printArray(orchard *arrayPointer, int arraySize) {
	
	for (int i = 0; i < arraySize; i++) {
		
		printf("Orchard's name: %s\n", arrayPointer->name);
		printf("Produce: %s\n", arrayPointer->produce);
		printf("Yearly harvest in kg: %d\n", arrayPointer->kgPerHarvest);
		printf("Size of orchard in square km: %f\n", arrayPointer->sizeInSquareKm);	
		printf("\n");	
		
		arrayPointer++;
	}
	
	return;	
}




// Validates user input that is supposed to be an integer and returns a pointer to integer value
int *validateInteger(char userInput[], int *userInputNumber) {
		
	// checking if the userInput is an integer by checking the ASCII values
	for (int i = 0; i < SIZE; i++) {
		
		// in ASCII values for characters 0...9 are 48...57.
		// for some reason when user inputs a value it reads a NULL value (0 in ASCII) in the next slot of the array
		// for instance if user inputs 9, the (int) values in the array will be {57, 0, 0, 0, 0}
		if (((int) userInput[i] < 48 || (int) userInput[i] > 57) && (int) userInput[i] != 0) {
			
			printf("Invalid input: was expecting an integer number.\n");
			return 0;
		}
		
	}
	
	// turning the userInput into an integer and saving it in userInputNumber
	//sscanf(userInput, "%d", &*userInputNumber);
	*userInputNumber = atoi(userInput);
	
	if (*userInputNumber == 0) {
	
		printf("Invalid input: input cannot be zero.\n");
	}
	return userInputNumber;
}






// Validates user input that is supposed to be a float and returns a pointer to float value
float *validateFloat(char userInput[], float *userInputFloat) {
	
	int dotCounter = 0;
	
	// checking if the userInput is a float by checking the ASCII values
	for (int i = 0; i < SIZE; i++) {
		
		// in ASCII values for characters 0...9 are 48...57.
		// ASCII value for . (dot) is 46.
		// for some reason when user inputs a value it reads a NULL value (0 in ASCII) in the next slot of the array
		// for instance if user inputs 9, the (int) values in the array will be {57, 0, 0, 0, 0}
		if (((int) userInput[i] < 48 || (int) userInput[i] > 57) && (int) userInput[i] != 0 && (int) userInput[i] != 46) {
			
			printf("Invalid input: was expecting a number.\n");
			return 0;
		}
		// if userInput[i] is . (dot) increment the dotCounter. A float should have max 1 dot.
		if ((int) userInput[i] == 46) {
		
			dotCounter += 1;
		}
	}
	if (dotCounter > 1) {
	
		printf("Invalid input: was expecting a number.\n");
		return 0;
	}
	
	// turning the userInput into a float and saving it in userInputFloat
	//sscanf(userInput, "%d", &*userInputFloat);
	*userInputFloat = atof(userInput);
	
	if (*userInputFloat == 0.0) {
	
		printf("Invalid input: input cannot be zero.\n");
	}
	return userInputFloat;
}

















