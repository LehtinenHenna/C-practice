
#include <stdio.h>

// x and y are parameters
void changeValues(int x, int y) {
	
	x += 10;
	y += 10;
	
	return;
}


int main() {

	int a = 1;
	int b = 2;
	
// a and b are arguments	
	changeValues(a, b);


	
}
