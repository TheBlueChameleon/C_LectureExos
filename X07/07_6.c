#include <stdio.h>

int main (void) {
  FILE * hFile = fopen("urandom.bin", "r");
  
  if (!hFile) {
    printf("Error: Could not open \"/dev/urandom\"\n");
    return 1;
  }
  
  unsigned int trueRandom, i, N=20;
  
  for (i = 0; i<N; i++) {
    fread(&trueRandom, 1, sizeof(trueRandom), hFile);
    printf("%u\n", trueRandom);
  }
  
  fclose (hFile);
}
