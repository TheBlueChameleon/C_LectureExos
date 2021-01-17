#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ========================================================================= //

void bubblesort (int * numbers, int N) {
  int dummy;
  int flagSwap = 0;
  
  do {
    flagSwap = 0;
    for (int i = 0; i < N-1; i++) {
      if (numbers[i] > numbers[i+1]) {
        flagSwap = 1;
        
        dummy = numbers[i];
        numbers[i  ] = numbers[i+1];
        numbers[i+1] = dummy;
      }
    }
  } while(flagSwap);
}

// ========================================================================= //

int main (void) {
  srand(time(NULL));
  
  int N = 10;
  int randLower = 1, randUpper = 100;
  
  int numbers[N];
  
  
  printf("Numbers, unsorted:\n");
  for (int i=0; i<N; i++) {
    numbers[i] = randLower + rand() % (randUpper - randLower + 1);
    printf("%d\n", numbers[i]);
  }
  
  bubblesort(numbers, N);
  
  
  printf("Numbers, sorted:\n");
  for (int i=0; i<N; i++) {
    printf("%d\n", numbers[i]);
  }
}
