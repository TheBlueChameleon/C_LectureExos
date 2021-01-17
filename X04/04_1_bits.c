#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ========================================================================= //

int getBit(char * data, int bitID) {
  int byte = bitID / 8;
  int bit  = bitID % 8;
  
  return (data[byte] & (1 << bit)) != 0;
}

// ------------------------------------------------------------------------- //

void setBit(char * data, int bitID) {
  int byte = bitID / 8;
  int bit  = bitID % 8;
  
  data[byte] = data[byte] | (1 << bit);
}

// ========================================================================= //

int main(void) {
  int i, j, N;
  
  printf("Prime numbers by Sieve of Eratosthenes\n\n");
  
  printf("Find prime numbers up to which number?\n");
  scanf("%d", &N);
  
  int bytes = ceil(N / 8.0);
  printf("%d bytes\n", bytes);
  
  char * numbers = calloc( bytes, 1 );
  
  // zero and one are no primes -- eliminate right away
  setBit(numbers, 0);
  setBit(numbers, 1); 
  
  
  // this can be used for debug
  /*
  for (int i=0; i<N; i++) {
    printf("%d: %sset\n", i, getBit(numbers, i) ? "" : "not ");
  }
  */
  
  
  for     (i =  2 ; i < N; i++ ) {
    if ( !getBit(numbers, i) ) {                     // do not sieve for numbers already eliminated
      for (j = i+i; j < N; j+=i) {
        setBit(numbers, j);
      }
      
    }
  }
  
  
  printf("The prime numbers between 2 and %d are:\n", N);
  j=0;
  for (int i=0; i<N; i++) {
    if ( !getBit(numbers, i) ) {
      j++;
      printf("#%d:\t%d\n", j, i);
    }
  }
  
  free(numbers);
}
