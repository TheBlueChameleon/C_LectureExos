#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int getBit(int num, int bit) {
  return (num & (1 << bit)) != 0;
}

// ========================================================================= //

int main () {
  int num = 23;
  int bits = sizeof(num) * 8;
  
  printf("%d(dec) = ", num);
  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", getBit(num, i));
  }
  printf("(bin)\n");
}
