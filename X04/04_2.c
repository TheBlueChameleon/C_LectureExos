#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int * primeFactors(int number) {
  /* This function creates an array of a size unknown to the caller. To be able
   * to work witht that array we need to know its size.
   * Here I present one work-around: I use the first element of the array as
   * size-information: we'll put here how many prime factors were known.
   * So if the array goes by the name reVal, then we will find the prime factors
   * at indices 1...reVal[0], and the array itself has reVal[0]+1 elements.
   */

  int * reVal = calloc(1, sizeof(*reVal));
  int * dummy;
  
  int div = 2;
  int factors = 0;
  while (div <= number) {
    
    if (number % div == 0) {
      factors++;
      
      dummy = realloc(reVal, (1+factors) * sizeof(*reVal));
      if (dummy) {
        reVal = dummy;

      } else {
        printf("error at memory allocation -- aborting");
        exit(1);
      }
      
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
