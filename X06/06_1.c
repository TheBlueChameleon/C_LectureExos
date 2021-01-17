#include <stdio.h>
#include <math.h>

const double M_PI = 4.0 * atan(1);

// ========================================================================= //

double integrate(
  double (*func)(double), 
  double from, 
  double to, 
  int    N
) {
  double reVal = 0;
  double width = (to - from) / N;
  
  for (double x = from; x < to; x += width) {
    reVal += width * func(x);
  }
  
  return reVal;
}

// ========================================================================= //

int main (void) {
  printf("the integral of exp(x) from 0 to  1 is: %lf\n", integrate(exp, 0,    1, 10000));
  printf("the integral of sin(x) from 0 to pi is: %lf\n", integrate(sin, 0, M_PI, 10000));
  printf("the integral of cos(x) from 0 to pi is: %lf\n", integrate(cos, 0, M_PI, 10000));
}
