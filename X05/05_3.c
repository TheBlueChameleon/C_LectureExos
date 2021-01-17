#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int      rows;
  int      cols;
  double * data;
} matrix;

// ========================================================================= //

void MatPrint(matrix M) {
  if (
    (M.cols ==    0) || 
    (M.rows ==    0) || 
    (M.data == NULL)
    ) {
    printf("invalid matrix.\n"); return;
  }
  
  for         (int r = 0; r < M.rows; r++) {
    for (int c = 0; c < M.cols; c++) {
      printf("%lf\t", M.data[r * M.cols + c]);
    }
    printf("\n");
  }
}

// ========================================================================= //

matrix MatProduct(matrix A, matrix B) {
  matrix reVal;
    reVal.rows =    0;	// initialize to zero:
    reVal.cols =    0;	// return a NULL matrix, if A and B
    reVal.data = NULL;	// are incompatible.
  
  if (A.cols != B.rows) {printf("incompatible matrices.\n"); return reVal;}
  
  reVal.rows = A.rows;
  reVal.cols = B.cols;
  
  reVal.data = malloc(reVal.rows * reVal.cols * sizeof(*reVal.data));
  
  if (reVal.data == NULL) {
    reVal.rows = 0;		// reset to zero for the
    reVal.cols = 0;		// same reason as above
    printf("failed to allocate enough memory.\n");
    return reVal;
  }
  
  int i, r, c;
  double  sum;
  for                 (r = 0; r < reVal.rows; r++) {
    for         (c = 0; c < reVal.cols; c++) {
      sum = 0;
      for (i = 0; i <     A.cols; i++) {
        sum += A.data[r * A.cols + i]  *  B.data[i * B.cols + c];
      }
      
      reVal.data[r * reVal.cols + c] = sum;
    }
  }
  
  return reVal;
}

// ========================================================================= //

int main (void) {
  int r, c;
  double x = 0, d= -1;
  
  matrix A, B, C;
  
  
  // ................................................................. //
  // prepare first matrix
  
  A.rows = 4;
  A.cols = 2;
  A.data = malloc(A.rows * A.cols * sizeof(*A.data));
  
  for         (r = 0; r < A.rows; r++) {
    for (c = 0; c < A.cols; c++) {
      x++;
      A.data[r * A.cols + c] = x;
    }
  }
  
  MatPrint(A);
  printf("\ntimes\n\n");
  
  
  // ................................................................. //
  // prepare second matrix
  
  B.rows = 2;
  B.cols = 3;
  B.data = malloc(B.rows * B.cols * sizeof(*B.data));
  
  x = 3;
  for         (r = 0; r < B.rows; r++) {
    for (c = 0; c < B.cols; c++) {
      B.data[r * B.cols + c] = x;
      x+=d;
    }
    x += 5;
    d *= -1;
  }
  
  MatPrint(B);
  
  printf("\nequals\n\n");
  
  
  // ................................................................. //
  // compute product
  
  C = MatProduct(A, B);
  MatPrint(C);
  
  
  // ................................................................. //
  // tidy up!
  
  free(A.data);
  free(B.data);
  free(C.data);
}
