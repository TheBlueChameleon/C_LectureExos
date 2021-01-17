#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
  int N = 10;
  int randLower = 1, randUpper = 100;
  
  int numbers[N];
  int i, dummy;
  
  int flagSwap = 0;
  int countSwaps = 0;
  
  
  srand(time(NULL));
  
  printf("Numbers, unsorted:\n");
  for (i=0; i<N; i++) {
    numbers[i] = randLower + rand() % (randUpper - randLower + 1);
    printf("%d\n", numbers[i]);
  }
  
  
  do {
    flagSwap = 0;
    for (i = 0; i < N-1; i++) {
      if (numbers[i] > numbers[i+1]) {
        flagSwap = 1;
        countSwaps++;
        
        dummy = numbers[i];
        numbers[i  ] = numbers[i+1];
        numbers[i+1] = dummy;
      }
    }
  } while(flagSwap);
  
  
  printf("Numbers, sorted after %d swaps:\n", countSwaps);
  for (i=0; i<N; i++) {
    printf("%d\n", numbers[i]);
  }
}
