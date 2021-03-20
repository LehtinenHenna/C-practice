/* 
 * File:   		Array.c
 * Author: 		Henna Lehtinen
 * Description: Includes functions: 
 				printArray that prints elements of array,
 				fillArrayFromFile that fills an array from a file, 
 				generateRandom that generates a random number
 */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "Array.h"

// Takes an array pointer and array size and prints the elements of the array
void printArray(int *arrayPointer, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
	
		printf("Item %d in array: %d.\n", i+1, *(arrayPointer + i));
	}
	return;
}

int *fillArrayFromFile(int *arrayPointer, char *filePath, int *arraySize) {

	FILE *filePointer = NULL;
	struct stat statistics = {};
	int fileSize = 0;
	int realArraySize = 0;
	
	// stat() returns 0 on successful operation,
	// otherwise returns -1 if unable to get file properties
	if (stat(filePath, &statistics) == 0) {
		
		fileSize = statistics.st_size;
		printf("File size: %d bytes\n", fileSize);
		
	} else {
		
		printf("Unable to get file properties.\n");
	}
			
		
	// now that we know the size of the file in bytes, we can use it to dynamically allocate memory for the array
	arrayPointer = ((int*) calloc(fileSize, sizeof(int)));
	filePointer = fopen(filePath, "r");
	
	while ((fscanf(filePointer, "%d", arrayPointer)) != EOF) {
	
		realArraySize += 1;
		arrayPointer++;
		
	}
	
	fclose(filePointer);
	
	if (realArraySize < 5) {
		
		printf("The size of the file is too small.\n");
		arrayPointer = NULL;
		return arrayPointer;
		
	} else {
	
		*arraySize = realArraySize;
	
		arrayPointer = arrayPointer - realArraySize;
	
		return arrayPointer;
	}			
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
