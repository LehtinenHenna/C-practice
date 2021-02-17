/*
Title: Exercise 5, Task 1B
Author: Henna Lehtinen
Description: Creates an array of floats, then changes the first
element of the array to be the biggest number in the array.
Lastly prints out the first element of the array without decimals.
*/

#include<stdio.h>

int main() {

	int n = 0;
	float array[100];
	
	printf("Enter total number of elements (1 to 100): ");
	scanf("%d", &n);
	printf("\n");
	
	for(int i = 0; i < n; i++) {
	
		printf("Enter Number %d: ", i+1);
		scanf("%f", &array[i]);
	}
	// Change the first element of the array to be the biggest number in the array
	for(int i = 0; i < n; i++) {
	
		if(array[0] < array[i]) {		
			array[0] = array[i];
		}
	}
	// Printing out the first number in the array without decimals, which also is the
	// biggest number in the array 		
	printf("What am I printing out? %2.f\n", array[0]);
	
	return 0;
}
