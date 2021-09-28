#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int main(void) {
  int i, j, N;
  
  printf("Prime numbers by Sieve of Eratosthenes\n\n");
  
  printf("Find prime numbers up to which number?\n");
  scanf("%d", &N);
  printf("\n");

  // prepare the number strip
  int * numbers = malloc((N + 1) * sizeof(*numbers));
  for (i=0; i<=N; i++) {numbers[i] = i;}
  
  // one is no prime -- eliminate right away
  numbers[1] = 0;
  
  // eliminate all the multiples
  for     (i=  2; i<N; i++ ) {
    if (numbers[i]) {                     // do not sieve for numbers already eliminated
      for (j=i+i; j<N; j+=i) {
        numbers[j] = 0;
      }
      
    }
  }
  
  // output on screen
  printf("The prime numbers between 2 and %d are:\n", N);
  j = 0;
  for (int i = 0; i < N+1; ++i) {
    if (numbers[i]) {
      j++;
      printf("#%d:\t%d\n", j, numbers[i]);
    }
  }
  printf("\n");

  // ........................................................................ //
  // Optional part: make it more memory efficient:
  // get rid of all the zeros in memory

  j = 0;
  for (i = 0; i < N+1; ++i) {
    if (!numbers[i]) {continue;}         // skip all zeros

    numbers[j] = numbers[i];
    ++j;
  }

  // shrink the array
  N = j;
  int * dummy = realloc(numbers, (N+1) * sizeof(*dummy));
  if (!dummy) {
    printf("Error when shrinking the array -- aborting");
    exit(1);      // never forget this!
    /* When you detect a problem, you'll need to take some action OTHER THAN
     * printing an error message. You wouldn't believe how many students fail
     * to do so...
     */
  }

  printf("After memory consolidation:\n");
  for (int i = 0; i < N; ++i) {
    printf("#%d:\t%d\n", i+1, numbers[i]);
  }


  free(numbers);
}
