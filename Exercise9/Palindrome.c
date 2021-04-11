/* 
 * File:   		Palindrome.c
 * Author:		Henna Lehtinen
 * Description: From Project Euler, problem 36:
 *				The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 *				The function palindrome checks all numbers from 0 to n (n <= 1 000 001) and saves those 
 *				numbers which are palindromic in both binary and decimal base to an array. 	
 *				(The palindromic number, in either base, may not include leading zeros.)			
 */
 
#include "Palindrome.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *palindrome(int n, int *palindromeArrayPointer, int *palindromeArraySize) {
	
	int counter = 0;
	
	int arraySize = 0;
	int *arraySizePointer = NULL;
	arraySizePointer = &arraySize;
	
	int numberArray[] = {};
	int *numberArrayPointer = NULL;
	numberArrayPointer = &numberArray;
	
	int binaryArraySize = 0;
	int *binaryArraySizePointer = NULL;
	binaryArraySizePointer = &binaryArraySize;
	
	int binaryArray[20] = {0};
	int *binaryArrayPointer = NULL;
	binaryArrayPointer = &binaryArray;
	
	int isiPalindromic = 0;
	int isBinPalindromic = 0;
	
	palindromeArrayPointer = (int*) malloc(n * sizeof(int));
	
	// check if dynamic memory allocation was successful
	if (palindromeArrayPointer == NULL) {
		
		printf("Dynamic memory allocation in palindrome() was not successful\n");
		return palindromeArrayPointer;
	}
		
	// check that n is in the correct range
	if (n < 1 || n > 1000001) {
		// if n is not in the correct range
		printf("n must be in range 1...1000 001.\n");
		palindromeArrayPointer = NULL;
		return palindromeArrayPointer;
	}
	
	//check if i is palindromic in decimal and binary base	
	for (int i = 0; i < n; i++) {
							
		// turn i into a char array
		numberArrayPointer = turnNumberToArray(i, numberArrayPointer, arraySizePointer);
				
		if (numberArrayPointer != NULL) {
		
			// check if i is palindromic
			isiPalindromic = checkIfArrayIsPalindromic(numberArrayPointer, arraySize);
				
			//if i is palindromic turn i to binary and check if the binary is palindromic
			if (isiPalindromic) {
					
				binaryArrayPointer = convertToBinary(i, binaryArrayPointer, binaryArraySizePointer);
				isBinPalindromic = checkIfArrayIsPalindromic(binaryArrayPointer, binaryArraySize);
						
				if (isBinPalindromic) {
			
				//if i is palindromic and binary version of i is palindromic, save it in the array
				*palindromeArrayPointer = i;
					
				// increment counter
				counter++;
				palindromeArrayPointer++;
				}
			}			
		}
	}				
	// free the allocated space of numberArray
	free(numberArrayPointer);
	palindromeArrayPointer -= counter;
	
	*palindromeArraySize = counter;
	return palindromeArrayPointer;					
}


int *turnNumberToArray(int number, int *arrayPointer, int *arraySizePointer) {
	
	int digits = 0;
	int tempNumber = number;
	
	// calculate the digits in number
	do {
		digits++;
		tempNumber /= 10;
	} while (tempNumber != 0);
		
	// now that we have the number of digits, let's allocate memory for the array
	arrayPointer = (int*) malloc(digits * sizeof(int));
	
	if (arrayPointer == NULL) {	
		printf("Dynamic memory allocation inside turnNumberToArray() was not successful.\n");
		return arrayPointer;
	}	
			
	//move pointer to end of array
	arrayPointer = arrayPointer + (digits-1);
	
	// save digits of number into the array
	do {
		if (number < 10) {
			*arrayPointer = number;
		}
		else {
			//save last digit of the number in the array, e.g if number is 258, save 8 in the array
			*arrayPointer = number % 10;
			arrayPointer--;	
		}	
		//truncate the last digit from number, e.g 258 becomes 25
		number /= 10;	
	} while (number);
	
	*arraySizePointer = digits;
	return arrayPointer;			
}


int *convertToBinary(int number, int *pointer, int *arraySizePointer) {	

	int i = 0;	
	
	for (i = 0; number > 0; i++) {	
		*pointer = number % 2;
		number = number/2;
		pointer++;	
	}
	// move the pointer back to the beginning
	pointer = pointer - i;
	
	*arraySizePointer = i;		
	return pointer;	
}


int checkIfArrayIsPalindromic(int *arrayPointer, int arraySize) {
	
	int isPalindromic = 1;
	int arrayBackwards[] = {};
	int *arrayBackwardsPointer = NULL;
	arrayBackwardsPointer = &arrayBackwards;
			
	//allocate space dynamically for arrayBackwards
	arrayBackwardsPointer = (int*) malloc(arraySize * sizeof(int));
	
	if (arrayBackwardsPointer == NULL) {
		printf("Dynamic memory allocation inside checkIfArrayIsPalindromic() was not successfull.\n");
		return 0;
	}	
					
	// create backwards array
	if (arraySize > 1) {
		// move arrayPointer to last slot
		arrayPointer += (arraySize-1);	
		*arrayBackwardsPointer = *arrayPointer;
			
		for (int i = arraySize-1; i > 0; i--) {
			arrayBackwardsPointer++;
			arrayPointer--;
			*arrayBackwardsPointer = *arrayPointer;
		}
			
		// move arrayBackwardsPointer back to beginning
		arrayBackwardsPointer -= (arraySize-1);
	}
	else if (arraySize == 1) {	
		*arrayBackwardsPointer = *arrayPointer;
	}
				
	// check if array == arrayBackwards
	for (int i = 0; i < arraySize; i++) {
		if (*arrayPointer != *arrayBackwardsPointer) {
			isPalindromic = 0;	
		}
		arrayPointer++;
		arrayBackwardsPointer++;
	}
	
	// move the pointers back to the beginning of the arrays				
	arrayBackwardsPointer -= arraySize;
	arrayPointer -= arraySize;		
		
	//free allocated space
	free(arrayBackwardsPointer);
					
	// return 1 if array is palindromic, return 0 if array is not palindromic	
	return isPalindromic;		
}


void arrayPrinter(int *arrayPointer, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
		printf("Element %d in the array: %d\n", i, *arrayPointer);
		arrayPointer++;
	}
	return;
}




















