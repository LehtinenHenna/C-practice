/*
File:			Exercise4_3.c
Author:			Henna Lehtinen
Description:	Exercise 4, Task 3:
				Counts the amount of negative numbers input
				Sums all the numbes input
				Sums all the positive numbers divisible by 3 input 
*/

#include <stdio.h>

int countNegatives();
int sumNumbers();
int countPositivesDivisibleBy3();


int main() {
	
	int negatives = 0;
	int summed = 0;
	int summedPositives = 0;
	
	negatives = countNegatives();
	printf("Amount of negative numbers input: %d\n", negatives);
	
	summed = sumNumbers();
	printf("Sum of all numbers input: %d\n", summed);
	
	summedPositives = countPositivesDivisibleBy3();
	printf("Sum of all positive numbers divisible by 3 input: %d\n", summedPositives);
}


// 3 A
int countNegatives() {
	
	int number = 1;
	int counter = 0;
	
	while (number != 0) {
		printf("Enter a number. Amount of negative numbers will be counted. To exit enter 0: \n");
		scanf("%d", &number);
		
		if (number < 0) {
			counter += 1;
		}
				
	}
	return counter;
}

// 3 B
int sumNumbers() {

	int number = 1;
	int sum = 0;
	
	while (number != 0) {
		printf("Enter a number to add to the sum. To exit enter 0: \n");
		scanf("%d", &number);
		
		sum += number;				
	}
	
	return sum;
}

// 3 C
int countPositivesDivisibleBy3() {
	
	int number = 1;
	int sum = 0;
	
	while (number != 0) {
		printf("Enter a number. All positive numbers divisible by 3 will be summed. To exit enter 0: \n");
		scanf("%d", &number);
		
		if (number > 0 && number % 3 == 0) {
			sum += number;
		}
				
	}
	return sum;
}













