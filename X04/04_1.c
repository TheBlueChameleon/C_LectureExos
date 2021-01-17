#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int main(void) {
  int i, j, N;
  
  printf("Prime numbers by Sieve of Eratosthenes\n\n");
  
  printf("Find prime numbers up to which number?\n");
  scanf("%d", &N);
  
  int * numbers = malloc((N + 1) * sizeof(*numbers));
  for (i=0; i<=N; i++) {numbers[i] = i;}
  
  // one is no prime -- eliminate right away
  numbers[1] = 0;
  
  for     (i=  2; i<N; i++ ) {
    if (numbers[i]) {                     // do not sieve for numbers already eliminated
      for (j=i+i; j<N; j+=i) {
        numbers[j] = 0;
      }
      
    }
  }
  
  printf("The prime numbers between 2 and %d are:\n", N);
  j = 0;
  for (int i=0; i<N; i++) {
    if (numbers[i]) {
      j++;
      printf("#%d:\t%d\n", j, numbers[i]);
    }
  }
  
  free(numbers);
}
