/* 
 * File:   		Exercise9.c
 * Author:		Henna Lehtinen
 * Description: Task 2: 
 *				Creating an array of Orchard type structs and printing out the elements
 *
 *				Task 3:
 *				~Project Euler problem 36~
 *				Creating an array of numbers that are palindromic in both decimal and binary base.
 *				Writing the array to file Numbers.txt.
 *				Reading the numbers from the file and summing them up.
 *				(I checked the sum result 872187 in Project Euler website and it was correct.)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "Palindrome.h"
#include "FileIO.h"


int main() {
	
	// Task 2
	struct Orchard *structArrayPointer = NULL;
	int arraySize = 0;
	int *arraySizePointer = NULL;
	arraySizePointer = &arraySize;
	
	structArrayPointer = createOrchards(structArrayPointer, arraySizePointer);
	
	if (structArrayPointer != NULL) {
	
		printArray(structArrayPointer, arraySize);
		
		// free dynamically allocated memory
		free(structArrayPointer);
	}

	// Task 3
	int sum = 0;
	int palindromeArraySize = 0;
	int *palindromeArraySizePointer = NULL;
	palindromeArraySizePointer = &palindromeArraySize;
	
	int *palindromePointer = NULL;
	
	int *fileArrayPointer = NULL;
	int fileArraySize = 0;
	int *fileArraySizePointer = NULL;
	fileArraySizePointer = &fileArraySize;
	
	palindromePointer = palindrome(1000001, palindromePointer, palindromeArraySizePointer);
	
	if (palindromePointer != NULL) {
	
		printf("Palindrome array: \n");
		arrayPrinter(palindromePointer, palindromeArraySize);
				
		// save array to file Numbers.txt
		writeNumbersToFile(palindromePointer, palindromeArraySize, "Numbers.txt");
		
		// read the numbers from the file Numbers.txt into fileArrayPointer
		fileArrayPointer = readNumbersFromFile(fileArrayPointer, "Numbers.txt", fileArraySizePointer);
		
		if (fileArrayPointer != NULL) {
		
			printf("File array:\n");
			arrayPrinter(fileArrayPointer, fileArraySize);
			
			// calculate the sum of all the numbers in file array
			sum = sumNumbersInArray(fileArrayPointer, fileArraySize);
			printf("Sum of all the numbers in file array: %d\n", sum);
		
			// free dynamically allocated memory
			free(palindromePointer);
			free(fileArrayPointer);
		}		
	}		
	return 0;
}




