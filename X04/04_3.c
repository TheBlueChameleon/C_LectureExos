#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int getBit(int num, int bit) {
  return (num & (1 << bit)) != 0;
  /* 1 << bit is equivalent to 2^bit, i.e. we get a number where the [bit]th bit
   * is set.
   *
   * Now if we perform the bitwise and (&) between num and that object, we only
   * get a result that differs from zero (i.e. false), if the [bit]th bit
   * was set.
   */

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
