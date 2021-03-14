/* 
 * File:   		PrimeFactor.c
 * Author: 		Henna Lehtinen
 * Description: Finds the prime factors for each element in an array.
 */

#include <stdio.h>
#include "PrimeFactor.h"



// Finds the prime factors for each element in an array
void testPrime(int *arrayPointer, int arraySize) {
	
	int isPrime = 0; // Used to check prime status of a divider
	
	printf("\n");
	printf("Finding prime factors for elements in given array...\n\n");
	
	for (int i = 0; i < arraySize; i++) {
		
		int baseIsPrime = 1; // Used to check if base number is a prime itself
		
		int baseNumber = *arrayPointer;
		arrayPointer++;
		printf("Base number: %d. Base number's prime factors: ", baseNumber);
		
		// There are no prime factors for numbers smaller than 2	
		if (baseNumber < 2) {
			printf("No prime factors for numbers smaller than 2.\n");
			continue;
		}
		
		
		// Find all prime factors
		for (int divider = 2; divider <= baseNumber; divider++) {
		
			// When the divider is baseNumber, break the loop so baseIsPrime check works correctly
			if (baseNumber == divider) { 
					break;
				}
			
			// Check if divider is a factor for baseNumber
			if (baseNumber % divider == 0) {
				
				baseIsPrime = 0;
				
				// Check if divider is a prime number
				isPrime = 1;
				for (int primeChecker = 2; primeChecker <= divider/2; primeChecker++) {
					
					if (divider % primeChecker == 0) {
						
						isPrime = 0;
						break;
					}
				}
				if (isPrime == 1) {
					
					printf("%d, ", divider);
				}
			}	
		}
		if (baseIsPrime == 1) {
		
			printf("The base number is a prime number itself.");
		}
		printf("\n");
	}	
	return;
}



