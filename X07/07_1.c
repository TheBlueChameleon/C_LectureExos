#include <stdio.h>

int main (int argc, char ** argv) {
  if (argc == 1) {
    printf("Text file content counter (TFCC)\n\n");
    printf("This script counts characters and words in a text file.\n");
    printf("Usage:\n\n");
    printf("\t%s [filename]\n\n", argv[0]);
    printf("\tOutput: Words and characters in [filename].\n");
    
    return -1;
  }
  
  FILE * hFile = fopen(argv[1], "r");
  
  if (!hFile) {
    printf("Text file content counter (TFCC)\n\n");
    printf("Error: Could not open \"%s\"\n", argv[1]);
    return 1;
  }
  
  char current;
  int  words = 1, chars = 0;
  
  while (!feof(hFile)) {
    fread(&current, 1, 1, hFile);
    chars++;
    
    if (current == ' ' || current == '\n') {words ++;}
  }
  
  printf("Text file content counter (TFCC)\n\n");
  printf("The file %s holds %d characters in %d words.\n", argv[1], chars, words);
  
  fclose(hFile);
  return 0;
}
