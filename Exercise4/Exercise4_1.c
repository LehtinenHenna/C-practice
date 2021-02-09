#include <stdio.h>


void changeValues(int x, int y) {
	
	x += 10;
	y += 10;
	
	return;
}

void changePointerValues(int *x, int *y) {

	*x += 10;
	*y += 10;
	
	return;
}

int main() {

	int x = 1;
	int y = 2;
	
	printf("Value of x before: %d\n", x);
	printf("Value of y before: %d\n", y);
	
	changeValues(x, y);
	
	printf("Value of x after: %d\n", x);
	printf("Value of y after: %d\n", y);
	
	changePointerValues(&x, &y);
	
	printf("Value of x after using call by reference: %d\n", x);
	printf("Value of y after using call by reference: %d\n", y);
	
}



