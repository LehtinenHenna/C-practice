/*
File:			Exercise2_3.c
Author:			Henna Lehtinen
Description:	Task 3: 
				Reads 2 integers from the user.
				Checks which of the numbers is bigger.
				Perfoms operations on the numbers.
*/


#include <stdio.h>
#include <math.h>

int numberInput();
void biggerNumber();
void numberOperations();

int main() {
	
	int firstInteger = 0;
	int secondInteger = 0;
	
	firstInteger = numberInput();
	secondInteger = numberInput();
	
	biggerNumber(firstInteger, secondInteger);
	numberOperations(firstInteger, secondInteger);

	
	return 0;
}

// takes a user input as integer and returns it
int numberInput() {

	int inputInteger = 0;
	
	printf("Enter an integer: ");
	scanf("%d", &inputInteger);
	
	
	return inputInteger;
}

// checks which one of two given numbers is bigger or if they're equal.
void biggerNumber(number1, number2) {
	
	if (number1 > number2) {
	
		printf("%d is bigger than %d.\n", number1, number2);
		
	} else if (number2 > number1) {
	
		printf("%d is bigger than %d.\n", number2, number1);
	
	} else {
		
		printf("The numbers are equal.\n");
	
	}
}

// performs the following operations on two numbers and prints the results:
// sum, subtraction, 1st number to the power of 2nd number, average, division
void numberOperations(number1, number2) {

	int sum = 0;
	int subtract = 0;
	float powerOf = 0;
	float average = 0;
	float division = 0;
	
	sum = number1 + number2;
	subtract = number1 - number2;
	powerOf = pow(number1, number2);
	average = (number1 + (float)number2) / 2;
		
	//print the results
	printf("Sum = %d\nSubtraction = %d\n", sum, subtract);
	printf("%d^%d = %.2f\n",number1, number2, powerOf);
	printf("Average = %.2f\n", average);
	
	if (number2 != 0) {	
		
		division = (number1 / (float)number2);
		printf("Division = %.2f\n", division);
		
	} else { 
	
		printf("Cannot divide by zero.\n");
		return 0;
	}
	
	return 0;		
}



















