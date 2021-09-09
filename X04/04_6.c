#include <stdio.h>
#include <stdlib.h>

// ========================================================================== //

void printInts(int * array) {
  if (!array) {
    printf("invalid pointer");
    exit(-1);
  }

  int len = array[0];
  if (len < 0) {
    printf("invalid state");
    exit(-1);
  }

  if (len == 0) {
    printf("<empty>\n");
    return;
  }

  for (int i = 1; i < len; ++i) {
    printf("%d, ", array[i]);
  }
  printf("%d\n", array[len]);
}

// .......................................................................... //

int * appendInt(int * array, int n) {
  if (!array) {
    printf("invalid pointer");
    exit(-1);
  }

  int len = array[0];
  if (len < 0) {
    printf("invalid state");
    exit(-1);
  }

  int * newArray = realloc(array, (len + 1 + 1) * sizeof(*array));              // one for the new element, one for the counter

  if (!newArray) {
    printf("failed to allocate memory!");
    free(array);
    exit(-1);
  }

  newArray[len+1] = n;
  newArray[0] = len + 1;

  return newArray;
}

// -------------------------------------------------------------------------- //

int getNextCollatz(int n) {
  if (n % 2) {return 3 * n + 1;}
  else       {return    n >> 1;}                                                // this is a slightly faster way of dividing an integer by two
}

// .......................................................................... //

int * getCollatzSequence(int n) {
  if (n < 1) {
    printf("invalid input: non-positive integer\n");
    exit(-1);
  }

  int * data = calloc(1, sizeof(*data));

  while (n != 1) {
    data = appendInt(data, n);
    n = getNextCollatz(n);
  }
  data = appendInt(data, n);

  return data;
}

// ========================================================================== //

int main (void) {
  printf("// ========================================================================== //\n");
  printf("// ARRAY METHODS TEST SECTION\n\n");

  int * data = calloc(1, sizeof(data));

  printf("output for empty list... ");
  printInts(data);

  printf("output for list with one element... ");
  data = appendInt(data, 1);
  printInts(data);

  printf("output for list with two elements... ");
  data = appendInt(data, 2);
  printInts(data);

  free(data);
  printf("\n");

  printf("// ========================================================================== //\n");
  printf("// COLLATZ TEST SECTION\n\n");

  for (int i=0; i < 20; ++i) {
    printf("The Collatz successor of %2d is %2d.\n", i, getNextCollatz(i));
  }
  printf("\n");

  printf("// ========================================================================== //\n");
  printf("// COLLATZ SEQUENCE SECTION\n\n");

  for (int i = 1; i <= 10; ++i) {
    printf("The Collatz sequence for %d:\n  ", i);

    data = getCollatzSequence(i);
    printInts(data);

    free(data);
  }

  int i = 27;
  printf("The Collatz sequence for %d:\n  ", i);

  data = getCollatzSequence(i);
  printInts(data);

  free(data);

  printf("\n");
  printf("DONE\n");
}
