#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ========================================================================= //

int min_idx(int * numbers, int N) {
  int idx = 0;
  
  for (int i=1; i<N; i++) {
    if (numbers[idx] > numbers[i]) {idx = i;}
  }
  
  return idx;
}

// ------------------------------------------------------------------------- //

void swap(int * a, int * b) {
  int dummy = *a;
  *a = *b;
  *b = dummy;
}

// ------------------------------------------------------------------------- //

void selection_sort (int * numbers, int N) {
  int idx;
  
  for (int i = 0; i < N - 1; i++) {
    idx = i + min_idx(numbers + i, N - i);
    
    if (idx != i) {swap(numbers + i, numbers + idx);}
  }
}

// ========================================================================= //

int randBetween(int lo, int hi) {return lo + rand() % (hi - lo + 1);}

// ========================================================================= //

int main (void) {
  int N = 10;
  int randLower = 1, randUpper = 100;
  
  int * numbers = malloc(N * sizeof(*numbers));
  int i, dummy;
  
  int flagSwap = 0;
  int countSwaps = 0;
  
  
  srand(time(NULL));
  
  printf("Numbers, unsorted:\n");
  for (i=0; i<N; i++) {
    numbers[i] = randBetween(randLower, randUpper);
    printf("%2d: %d\n", i, numbers[i]);
  }
  
  
  selection_sort(numbers, N);
  
  
  printf("Numbers, sorted:\n");
  for (int i=0; i<N; i++) {
    printf("%2d: %d\n", i, numbers[i]);
  }
  
  
  free(numbers);
}
