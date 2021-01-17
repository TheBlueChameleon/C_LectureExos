#include <stdio.h>

// ========================================================================= //

int fib(int n) {
  if (n > 1) {return fib(n-1) + fib(n-2);} else {return 1;}
}

// ========================================================================= //

int main(void) {
  int i, N = 10;
  
  printf("The first %d Fibonacci-numbers are:\n", N);
  for (i=1; i<=N; i++) {
    printf("%2d\t%3d\n", i, fib(i));
  }
}
