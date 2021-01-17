#include <stdio.h>

int main (void) {
	int matrix_2D[3][3];
	int matrix_1D[9];

	int r, c;	
	
	for		(r = 0; r < 3; r++) {
		for	(c = 0; c < 3; c++) {
			matrix_2D[r][c]      = 1 + (2 - r) * 3 + c;
			matrix_1D[r * 3 + c] = 1 + (2 - r) * 3 + c;
		}
	}
	
	printf("Output matrix_2D:\n");
	for		(r = 0; r < 3; r++) {
		for	(c = 0; c < 3; c++) {
			printf(
				"%d ",
				matrix_2D[r][c]
			);
		}
		printf("\n");
	}
	
	printf("Output matrix_1D:\n");
	for		(r = 0; r < 3; r++) {
		for	(c = 0; c < 3; c++) {
			printf(
				"%d ",
				matrix_1D[r * 3 + c]
			);
		}
		printf("\n");
	}
}