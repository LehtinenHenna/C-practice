/* 
 * File:   		Calculation.c
 * Author: 		Henna Lehtinen
 * Description: Finds the biggest sum of five adjacent numbers in an array
 */

#include <stdio.h>
#include "Calculation.h"

// code implementation here
void findBiggestSum(int *arrayPointer, int arraySize) {
	
	int biggestSum = 0;
	int sumOfFive = 0;
	int loopEnd = 0;
	
	
	if (arraySize % 2 == 0) {
		
		loopEnd = arraySize / 2;
	
	// for the loop to check the last element of the array as well
	// when arraySize is an odd number, loop ender must be arraySize / 2 + 1	
	} else {
	
		loopEnd = (arraySize / 2) + 1;
	}
	
	for (int i = 0; i < loopEnd; i++) {
		
		sumOfFive = 0;
		
		for (int j = 0; j < 5; j++) {
			sumOfFive += *arrayPointer;
			arrayPointer++;
		}
		
		if (sumOfFive > biggestSum) {
		biggestSum = sumOfFive;
		}

		arrayPointer = arrayPointer - 4;
	}
	
	printf("Biggest sum of five adjacent numbers: %d\n", sumOfFive);
	
	return;
}














