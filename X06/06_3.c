#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ========================================================================= //

int crosssum(int a) {
  int reVal = 0;
  
  do {
    reVal += a % 10;
    a /= 10;
  } while(a);
  
  return reVal;
}

// ------------------------------------------------------------------------- //

int compare_ints(const void * a, const void * b) {
  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;

  if (crosssum(arg1) < crosssum(arg2)) {return -1;}
  if (crosssum(arg1) > crosssum(arg2)) {return +1;}
  return 0;
}

// ========================================================================= //

int main (int argc, char ** argv) {
  srand(time(NULL));
  
  int N = 10;
  
  printf("%d\n", argc);
  
  if (argc > 1) {
    N = atoi(argv[1]);
    if (N < 1) {
      printf("error - can only generate arrays of size 1 or bigger.\n");
      return -1;
    }
  }
  
  int * array = malloc(N * sizeof(*array));
  
  printf("before sorting:\n");
  for (int i=0; i<N; i++) {
    array[i] = rand() % 100;
    printf("%3d: %d\n", i, array[i]);
  }
  
  
  qsort(array, N, sizeof(*array), compare_ints);
  
  
  printf("after sorting:\n");
  for (int i=0; i<N; i++) {
    printf("%3d: %d\n", i, array[i]);
  }
  
  free(array);
}
