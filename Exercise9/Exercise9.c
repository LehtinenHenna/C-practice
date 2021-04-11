/* 
 * File:   		Exercise9.c
 * Author:		Henna Lehtinen
 * Description: Task 2: 
 *				Creating an array of Orchard type structs and printing out the elements
 *				Task 3:
 *				~Project Euler problem 36~
 *				Creating an array of numbers that are palindromic in both decimal and binary base.
 *				Saving the array to file Numbers.txt.
 *				Reading the numbers from the file and summing them up.
 *				(I checked the sum result 872187 in Project Euler website and it was correct.)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "Palindrome.h"


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
	
	palindromePointer = palindrome(1000000, palindromePointer, palindromeArraySizePointer);
	
	if (palindromePointer != NULL) {
		printf("Palindrome array: \n");
		arrayPrinter(palindromePointer, palindromeArraySize);
		
		for (int i = 0; i < palindromeArraySize; i++) {
		
			sum += *palindromePointer;
			palindromePointer++;	
		}
		
		palindromePointer -= palindromeArraySize;
		printf("Sum of all elements in Palindrome array: %d\n", sum);
		
		//free dynamically allocated memory
		free(palindromePointer);
	}	
	
	return 0;
}




