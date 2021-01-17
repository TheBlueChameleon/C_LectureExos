#include <stdio.h>

int main (void) {
  int row, column;
  int height = 7;
  
  for (row = 0; row < height; row++) {
    for (column = 0; column < (height - row); column++) {printf(" ");}
    for (column = 0; column < 2 * row + 1   ; column++) {printf("*");}
    
    printf("\n");
  }
}
