/* 
 * File:   		Armstrong.c
 * Author:		Henna Lehtinen
 * Description: Finds Armstrong numbers between 0 and 100 000.
 */

#include <stdio.h>
#include <math.h>
#include "Armstrong.h"


// Checks numbers between 0 and 100 000 and saves Armstrong numbers in the given array. 
// e.g 153 is an Armstrong number because 153 = 1³+5³+3³. Exponent comes from the number of digits.
void testArmstrong(int *arrayPointer) {
	
	printf("\n");
	printf("Finding Armstrong numbers between 0 and 100 000...\n\n");
	
	for (int i = 0; i <= 100000; i++) {
	
		int number = i;
		int numberOfDigits = 0;	// used to store the number of digits in the current i (eg. if i == 35, numberOfDigits = 2)
		int arrayOfDigits[6] = {0,0,0,0,0,0}; // length of array is 6 because the max number 100 000 has 6 digits
		int index = 0;
		int sum = 0;
		
		
		while (number > 0) { // check how many digits i has
			numberOfDigits += 1;
			arrayOfDigits[index] = number % 10;	// store the digits of i separately in arrayOfDigits
			index += 1;
			number = number / 10;	
		}
		
		for (int j = 0; j < 6; j++) {
		
			if (arrayOfDigits[j] == 0) {
				continue;
			}
			sum += pow(arrayOfDigits[j], numberOfDigits); // if i is 153, sum will be 1³+5³+3³ 
		}
		
			
		if (sum == i) {		// if the current i is an armstrong number
		
			*arrayPointer = sum;	// add the sum to the array
			arrayPointer++;		// move the pointer one slot forward
		}		
	}
	return;
}







