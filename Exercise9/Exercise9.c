/* 
 * File:   		Exercise9.c
 * Author:		Henna Lehtinen
 * Description: 
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
		
		// free allocated memory here
		free(structArrayPointer);
	}

	// Task 3
	int palindromeArraySize = 0;
	int *palindromeArraySizePointer = NULL;
	palindromeArraySizePointer = &palindromeArraySize;
	
	int *palindromePointer = NULL;
	
	palindromePointer = palindrome(100, palindromePointer, palindromeArraySizePointer);
	
	if (palindromePointer != NULL) {
		printf("Palindrome array: \n");
		arrayPrinter(palindromePointer, palindromeArraySize);
		free(palindromePointer);
	}	
	
	return 0;
}
