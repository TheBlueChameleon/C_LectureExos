#include <stdio.h>

int main () {
  char line[] = "                                         ";
  
  int width  = sizeof(line) / sizeof(*line);
  int height = width / 2;
  
  if (!(width % 2)) {height--;}
  
  printf("width:\t%d\n", width);
  printf("height:\t%d\n", height);
  
  for (int i=0; i < height; i++) {
    line[height + i] = '*';
    line[height - i] = '*';
    
    printf("%s\n", line);
  }
  
}
