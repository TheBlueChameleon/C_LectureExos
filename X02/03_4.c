#include <stdio.h>

int main (void) {
  int reVal = 0;
  int vec_a[] =  { 3, 2, 1, 5, 7, 2, -1};
  int vec_b[] =  {-7, 3, 7, 5, 6, 8,  1};
  
  int N = sizeof(vec_a) / sizeof(int);
  
  printf("%d\n", N);
  
  for (int i=0; i< N; i++) {
    reVal += vec_a[i] * vec_b[i];
  }
  
  printf("%d\n", reVal);
}
