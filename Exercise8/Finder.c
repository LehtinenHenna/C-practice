/* 
 * File:   		Finder.c
 * Author: 		Henna Lehtinen
 * Description: Includes functions:
 				findNumber that checks if a given number is in a given array
 */

#include <stdio.h>
#include <stdlib.h>
#include "Finder.h"

// Checks if the given number is in the given array
int *findNumber(int *arrayPointer, int arraySize, int number) {
	
	int *resultPointer = NULL;
	resultPointer = malloc(sizeof(int));
	
	if (resultPointer != NULL) {
	
		for (int i = 0; i < arraySize; i++) {
	
			if (number == *arrayPointer) {
				resultPointer = arrayPointer;
				return resultPointer;
			}
			arrayPointer++;
		}
	
		resultPointer = NULL;
		return resultPointer;
	
	} else {
		printf("Dynamic memory allocation in Finder.c was not successful.\n");
		return resultPointer;
	}	
}
