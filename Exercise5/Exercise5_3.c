/*
Title: Exercise 5, Task 3
Author: Henna Lehtinen
Description: Validates main function argument. Checks that there's only one argument,
checks that it is in range (0..10000) and prints out the value of the integer.
If input is something other than integers the program prints out 0.
When we have our integer number the program will check whether it's a prime number.
*/

#include<stdio.h>
#include<stdlib.h>

int primeNumberCheck(int number);

int main(int argc, char *argv[]) {

	if (argc == 2) {
		// atoi function picks only the digits from the input.
		// If there's no digits or input starts with something other than digit, returns 0.
		int number = atoi(argv[1]);	
		// number must be in range 0..100000	
		if (0 <= number && number <= 100000) {
			
			printf("The value of the argument is: %d.\n", number);
			int checkPrime = primeNumberCheck(number);
			
			if (checkPrime == 1) {
				printf("Number %d is a prime number.\n", number);
				
			} else if ( checkPrime == 0) {
				printf("Number %d is not a prime number.\n", number);
			}
				
		} else {
			printf("Error: given argument is not in range 0..100000.\n");
		} 	
	} else {
		printf("Error: incorrect amount of arguments given.\n");
	}
	return 0;
}

// If the given number is a prime number, returns 1. Else returns 0.
int primeNumberCheck(int number) {
	
	// 0 and 1 are not prime numbers. Negative numbers are not prime numbers.
	if (number <= 1) {
		return 0;
	}
	// We only need to divide number with halfNumber and smaller numbers to check if it's prime.
	int halfNumber = number / 2;
	for (int i = 2; i <= halfNumber; i++) {
	
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}













