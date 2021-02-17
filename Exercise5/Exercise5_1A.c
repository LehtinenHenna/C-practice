/*
Title: Exercise 5, Task 1A
Author: Henna Lehtinen
Description: Creates a number sequence that
works a bit like Fibonacci, but instead of summing the previous 
2 numbers together this one sums the previous 3 numbers.
*/

#include<stdio.h>

int main() {

	int num = 0;
	int x = 0;
	int y = 1;
	int z = 2;
	int sumVariable = 0;
	int count = 0;
	
	printf("Enter a number:\t");
	scanf("%d", &num);
	
	printf("%d\n%d\n%d\n", x, y, z);
	
	count = 3;
	while(count < num) {
		
		sumVariable = x + y + z;
		printf("%d\n", sumVariable);
		x = y;
		y = z;
		z = sumVariable;
		count += count;
	}
	return 0;
}
