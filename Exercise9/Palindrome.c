/* 
 * File:   		Palindrome.c
 * Author:		Henna Lehtinen
 * Description: The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
 *				The function palindrome checks all numbers from 0 to n (n <= 1 000 000) and saves those 
 *				numbers which are palindromic in both binary and decimal base to an array. 	
 *				(The palindromic number, in either base, may not include leading zeros.)			
 */
 
#include "Palindrome.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *palindrome(int n, int *pointer, int *palindromeArraySize) {
	
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
	
	pointer = (int*) malloc(n * sizeof(int));
	
	if (pointer == NULL) {
		
		printf("Dynamic memory allocation in palindrome() was not successful\n");
		return pointer;
	}
	else {
		
		// check that n is in the correct range
		if (n > 0 && n < 1000001) {
		
			for (int i = 0; i < n; i++) {
			

				
				//printf("i: %d\n", i);
				
				//check if i is palindromic:		
				
				// turn i into a char array
				numberArrayPointer = turnNumberToArray(i, numberArrayPointer, arraySizePointer);
				
				if (numberArrayPointer != NULL) {
					//printf("numberArray: \n");
					//arrayPrinter(numberArrayPointer, arraySize);
				
					// check if i is palindromic
					isiPalindromic = checkIfArrayIsPalindromic(numberArrayPointer, arraySize);
				
					//if i is palindromic turn i to binary and check if the binary is palindromic
					if (isiPalindromic) {
						binaryArrayPointer = convertToBinary(i, binaryArrayPointer, binaryArraySizePointer);
						//printf("binaryArray: \n");
						//arrayPrinter(binaryArrayPointer, binaryArraySize);
						isBinPalindromic = checkIfArrayIsPalindromic(binaryArrayPointer, binaryArraySize);
						
						if (isBinPalindromic) {
				
						//if i is palindromic and binary version of i is palindromic, save it in the array
						*pointer = i;
						printf("palindromic i: %d\n", i);
					
						// increment counter
						counter++;
						pointer++;
						}
					}			
				}
			}
			*palindromeArraySize = counter;
			
			// free the allocated space of numberArray
			//printf("free(numberArrayPointer)\n");
			free(numberArrayPointer);
			pointer = pointer - counter;
			return pointer;		
		}
		else {
			// if n is not in the correct range
			printf("n must be in range 0...1000 000.\n");
			pointer = NULL;
			return pointer;
		}
	}
}


int *turnNumberToArray(int number, int *pointer, int *arraySizePointer) {
	
	int digits = 0;
	int tempNumber = number;
	
	if (tempNumber == 0) {
		digits = 1;
	}
	while (tempNumber) {
	
		digits++;
		tempNumber = tempNumber/10;
	}
	// now that we have the number of digits, let's allocate memory for the array
	pointer = (int*) malloc(digits * sizeof(int));
	
	if (pointer != NULL) {
		
		*arraySizePointer = digits;
		
		//move pointer to end of array
		pointer = pointer + (digits-1);
		
		if (number == 0) {
			*pointer = number;
		}
		
		while (number) {
			
			if (number < 10) {
				*pointer = number;
				//printf("*pointer in turnNumberToArray: %d\n", *pointer);
			}
			else {
				//save last digit of the number in the array, e.g if number is 258, save 8 in the array
				*pointer = number % 10;
				//printf("*pointer in turnNumberToArray:: %d\n", *pointer);
				pointer--;	
			}
			
			//truncate the last digit from number, e.g 258 becomes 25
			number = number/10;
			
			
		}
		return pointer;
	} 
	else {
		printf("Dynamic memory allocation inside turnNumberToArray() was not successful.\n");
		return pointer;
	}
}


int *convertToBinary(int number, int *pointer, int *arraySizePointer) {
	
	int i = 0;
	
	for (i = 0; number > 0; i++) {
	
		*pointer = number % 2;
		number = number/2;
		pointer++;	
	}
	*arraySizePointer = i;
	pointer = pointer - i;
	
	return pointer;	
}





int checkIfArrayIsPalindromic(int *arrayPointer, int arraySize) {
	
	int isPalindromic = 1;
	int arrayBackwards[] = {};
	int *arrayBackwardsPointer = NULL;
	arrayBackwardsPointer = &arrayBackwards;
	
	//printf("*arrayPointer in checkIfArrayIsPalindromic: %d\n", *arrayPointer);
	//printf("arraySize in checkIfArrayIsPalindromic: %d\n", arraySize);
	
	
	//allocate space dynamically for arrayBackwards
	arrayBackwardsPointer = (int*) malloc(arraySize * sizeof(int));
	
	if (arrayBackwardsPointer != NULL) {
			
		
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
			
		
		//printf("*arrayPointer after creating backwards array: %d\n", *arrayPointer);
		
		printf("array: \n");
		arrayPrinter(arrayPointer, arraySize);
		
		printf("arrayBackwards: \n");	
		arrayPrinter(arrayBackwardsPointer, arraySize);
		
		

		
		// check if array == arrayBackwards
		for (int i = 0; i < arraySize; i++) {
		
			if (*arrayPointer != *arrayBackwardsPointer) {
				isPalindromic = 0;	
			}
			arrayPointer++;
			arrayBackwardsPointer++;
		}	
		
		arrayBackwardsPointer -= arraySize;
		arrayPointer -= arraySize;		
		//free allocated space
		//printf("free(arrayBackwardsPointer)\n");
		free(arrayBackwardsPointer);
	}
	else {
		printf("Dynamic memory allocation inside checkIfArrayIsPalindromic() was not successfull.\n");
		return 0;
	}	
		
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




















