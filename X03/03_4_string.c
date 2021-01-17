/* cross sum, using strings.
* 2018-06-04
* I do not recommend this, but it works.
*/

// ========================================================================= //

#include <stdio.h>

// ========================================================================= //

int crosssum(int number) {
  char snum[20] = {};
  int  reVal    = 0;
  
  sprintf(snum, "%d", number);
  
  for (int i=0; i<20; i++) {
    reVal += ((snum[i] >= '0') && (snum[i] <= '9')) ? snum[i] - '0' : 0;
  }
  
  return reVal;
}

// ========================================================================= //

int main (void) {
  int num = 0;
  
  printf("Please enter an integer number: ");
  scanf("%d", &num);
  
  printf("The cross sum of %d is %d.\n", num, crosssum(num));
}
