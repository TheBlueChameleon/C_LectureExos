#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int * primeFactors(int number) {
  int * reVal = calloc(1, sizeof(*reVal));
  int * dummy;
  
  int div = 2;
  int factors = 0;
  while (div <= number) {
    
    if (number % div == 0) {
      factors++;
      
      dummy = realloc(reVal, (1+factors) * sizeof(*reVal));
      if (dummy) {reVal    = dummy;}
      else       {reVal[0] = factors - 1; return reVal;}
      
      reVal[factors] = div;
      number /= div;
      continue;
    }
    
    div++;
  }
  
  reVal[0] = factors;
  return reVal;
}

// ========================================================================= //

int main(void) {
  int num = 100;
  int * factors = primeFactors(num);
  
  printf("%d = 1", num);
  for (int i = 1; i <= factors[0]; i++) {
    printf(" * %d", factors[i]);
  }
  printf("\n");
  
  free(factors);
}
