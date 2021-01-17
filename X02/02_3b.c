#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int row, column;
  int height = 7;
  int starFlag;
  
  for   (row    = 0; row    <     height    ;    row++) {
    for (column = 0; column < 2 * height + 1; column++) {
      starFlag = abs(column - height) < (row + 1);
      
      printf("%s", starFlag ? "*" : " ");
    }
    printf("\n");
  }
}
