/*
File:			Exercise4_4.c
Author:			Henna Lehtinen
Description:	Exercise 4, Task 4:
				Generates two random numbers between 0 and 100
				Uses those numbers to generate a grade for a student				
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>

int generateRandom(int number1, int number2);
int generateGrade(int examPoints, int exercisePoints);


int main() {
	
	int randomNumber1 = 0;
	int randomNumber2 = 0;
	int max = 100;
	int min = 50;
	int grade = 0;

	randomNumber1 = generateRandom(max, min);
	printf("Random number between %d and %d: %d\n", min, max, randomNumber1);
	
	// Wait so that the seed value has time to change
	sleep(1);
	
	randomNumber2 = generateRandom(max, min);
	printf("Random number between %d and %d: %d\n", min, max, randomNumber2);
	
	grade = generateGrade(randomNumber1, randomNumber2);
	printf("The student's grade in range from 0 to 5 is: %d\n", grade);
}


// Generate a random number in range (start, end)
int generateRandom(int number1, int number2) {

	int randomNumber = 0;
	int end = 0;
	int start = 0;
	
	// Use current time as a seed for the random number generator
	srand(time(0));
	
	if (number1 > number2) {
		end = number1;
		start = number2;
	} else if (number2 > number1) {
		end = number2;
		start = number1;
	} else {
		printf("The input is invalid.\n");
		return 0;
	}
	
	// rand() generates a number between 0 and RAND_MAX,
	// but this way we can use it to generate a number in range (start, end)
	// (end - start + 1) is the RAND_MAX. Then we add start to the resulted number to get a number in the right range
	randomNumber = (rand() % (end - start + 1)) + start;
	
	return randomNumber;
}


int generateGrade(int examPoints, int exercisePoints) {
	
	int grade = 0;
	int sumPoints = 0;
	
	sumPoints = examPoints + exercisePoints;
	
	if (examPoints >= 50 && exercisePoints >= 50){
		if (sumPoints < 100) {
			grade = 0;
		} else if (sumPoints < 120) {
			grade = 1;
		} else if (sumPoints < 140) {
			grade = 2;
		} else if (sumPoints < 160) {
			grade = 3;
		} else if (sumPoints < 180) {
			grade = 4;
		} else {
			grade = 5;
		}
		
	} else {	
		grade = 0;
	}

	return grade;
}








