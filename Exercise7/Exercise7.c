/* 
 * File:   		Exercise7.c
 * Author:		Henna Lehtinen
 * Description: Finds Armstrong numbers between 0 and 100 000 and then finds prime factors for those numbers.
 */

#include <stdio.h>

#include "Armstrong.h"
#include "PrimeFactor.h"

#define SIZE 20

int main() {
	
	int armstrongArray[SIZE] = {0};
	int *arrayPointer = NULL;
	arrayPointer = &armstrongArray[0];
	
    testArmstrong(arrayPointer);
    
    for (int i = 0; i < SIZE; i++) {
    	
    	printf("Armstrong number %d: %d\n", i+1, *arrayPointer);
    	arrayPointer++;
    }
    
    arrayPointer = arrayPointer - 20;
	testPrime(arrayPointer, SIZE);
	
	int testArray[5] = {-2, -1, 0, 1, 2};
	int *testPointer = NULL;
	testPointer = &testArray[0];
	testPrime(testPointer, 5);
       
    return 0;
}


