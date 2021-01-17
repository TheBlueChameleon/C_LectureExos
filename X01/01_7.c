#include <stdio.h>

int main (void) {
  int A = 65;

  printf("dec  hex  asc\n");
  printf("%3d  %3x  %c\n", A, A, A);
  
  A++;
  printf("%3d  %3x  %c\n", A, A, A);
  
  A++;
  printf("%3d  %3x  %c\n", A, A, A);
}
