/* 
 * File:   		FileIO.c
 * Author:		Henna Lehtinen
 * Description: Writing numbers to a text file.
 *				Reading the numbers from the text file into an array.
 *				Calculating the sum of numbers in an array. 		
 */
#include "FileIO.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
 
void writeNumbersToFile(int *arrayPointer, int arraySize, char fileName[]) {
	
	FILE *filePointer = NULL;	
	filePointer = fopen(fileName, "w");
	
	// writing the elements of the array into the file, each number on its own line
	for (int i = 0; i < arraySize; i++) {
		fprintf(filePointer, "%d\n", *arrayPointer);
		arrayPointer++;	
	}
	fclose(filePointer);
	return;
}

int *readNumbersFromFile(int *arrayPointer, char fileName[], int *arraySize) {
	
	FILE *filePointer = NULL;
	int fileSize = 0;
	struct stat fileStatistics = {};
	int elementCounter = 0;
	
	
	// stat() retrieves file properties. It returns 0 on a successful operation,
	// and -1 if it is unable to fetch the file properties
	if (stat(fileName, &fileStatistics) != 0) {
		printf("Unable to fetch file properties.\n");
	}
	else {
		fileSize = fileStatistics.st_size;
	}
	
	// allocate space dynamically according to file size
	arrayPointer = ((int*) malloc(fileSize * sizeof(int)));
	if (arrayPointer == NULL) {		
		printf("Dynamic memory allocation was not successful.\n");
		return arrayPointer;
	}
	
	filePointer = fopen(fileName, "r");
	
	while ((fscanf(filePointer, "%d", arrayPointer)) != EOF) {
		
		elementCounter += 1;
		arrayPointer++;	
	}
	
	fclose(filePointer);	
	// move the pointer to the beginning of the array
	arrayPointer -= elementCounter;
	
	*arraySize = elementCounter;
	return arrayPointer;
}

int sumNumbersInArray(int *arrayPointer, int arraySize) {
	
	int sum = 0;
	
	for (int i = 0; i < arraySize; i++) {
	
		sum += *arrayPointer;
		arrayPointer++;
	}
	arrayPointer -= arraySize;
	return sum;
}























