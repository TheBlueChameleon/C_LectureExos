#include <stdio.h>

int crosssum(int);

// ========================================================================= //

int main (void) {
	int a;
	
	printf("please enter a number:\n");
	scanf("%d", &a);
	
	printf(
		"The cross sum of %d is %d.\n",
		a, crosssum(a)
	);
}

// ========================================================================= //

int crosssum(int a) {
	int reVal = 0;
	
	do {
		reVal += a % 10;
		a /= 10;
	} while(a);
	
	return reVal;
}