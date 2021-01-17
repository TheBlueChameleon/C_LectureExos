#include <stdio.h>
#include <math.h>

double octaVolume (double a);
double octaSurface(double a);
void   octaAll    (double a, double * vol, double * sur);

// ========================================================================= //

int main (void) {
	double a, vol, sur;
	
	printf("please enter the side length of the octahedron:\n");
	scanf("%lf", &a);
	
	printf("volume      :\t%lf\n", octaVolume (a));
	printf("surface area:\t%lf\n", octaSurface(a));
	
	octaAll(a, &vol, &sur);
	
	printf("volume      :\t%lf\n", vol);
	printf("surface area:\t%lf\n", sur);
}

// ========================================================================= //

double octaVolume (double a) {
	return 8 * pow(a, 3) * sqrt(2);
}

// ......................................................................... //

double octaSurface(double a) {
	return 6 * a * a * (1 + 2 * sqrt(3));
}

// ......................................................................... //

void   octaAll    (double a, double * vol, double * sur) {
	*vol = 8 * pow(a, 3) * sqrt(2);
	*sur = 6 * a * a * (1 + 2 * sqrt(3));
}