#include <stdio.h>

// ========================================================================= //

void swap(double * a, double * b) {
  double dummy = *a;
  *a = *b;
  *b = dummy;
}

// ========================================================================= //

int main (void) {
  double a = 1.3;
  double b = 7.7;

  printf("a = %f\tb = %f\n", a, b);
  swap(&a, &b);
  printf("a = %f\tb = %f\n", a, b);
}
