/* 
 * File:   		Exercise8.c
 * Author:		Henna Lehtinen
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>

#include "Array.h"
#include "Calculation.h"
#include "Finder.h"

#define SIZE 10

int main () {
	
	int *arrayPointer = NULL;
	arrayPointer = ((int*) calloc(SIZE, sizeof(int)));
	
	if (arrayPointer == NULL) {
		
		printf("Dynamic memory allocation did not succeed.\n");
		return 0;

	} else {
		
		printf("Dynamic memory allocation succeeded.\n");
		for (int i = 0; i < SIZE; i++) {
		
			*arrayPointer = generateRandom(0, 100);
			arrayPointer++;
		}	
	}
	arrayPointer = arrayPointer - SIZE;
	printArray(arrayPointer, SIZE);
	
	free(arrayPointer);
	return 0;
}


