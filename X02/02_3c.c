#include <stdio.h>

int main () {
  int height = 20;
  int width  = 2 * height + 1;
  
  for (int i = 0; i < height * width; i++) {
    int row, col;
    
    row = i / width;
    col = i % width;
    
    if ((col <= height - row) || (col >= height + row)) {printf(" ");}
    else                                                {printf("*");}
    
    if (col == width - 1) {printf("\n");}
  }
}
