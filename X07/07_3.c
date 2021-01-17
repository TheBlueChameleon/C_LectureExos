#include <stdio.h>

// ========================================================================= //

long long int factorial_recursive(long long int num) {
  if (num < 2) {return 1;}
  else         {return num * factorial_recursive(num - 1);}
}

// ------------------------------------------------------------------------- //

long long int factorial_iterative (long long int num) {
  long long int reVal = 1;
  
  if (num < 0) {return -1;}
  
  for (int i=1; i<num; i++) {reVal *= (i + 1);}
  
  return reVal;
}

// ========================================================================= //

int main () {
  for (int i=0; i<16; i++) {
    printf("%2d: %14lld vs. %14lld\n",
      i, factorial_recursive(i), factorial_iterative(i)
    );
  }
}
