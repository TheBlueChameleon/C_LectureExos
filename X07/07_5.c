#include <stdio.h>
#include <string.h>

#define WordToFind "processor"

int main (void) {
  FILE * hFile = fopen("/proc/cpuinfo", "r");
  
  if (!hFile) {
    printf("Error: Could not open \"/proc/cpuinfo\"\n");
    return 1;
  }
  
  char cur[1024];
  int count = 0;
  
  while (!feof(hFile)) {
    fgets(cur, 1024, hFile);
    if (strncmp(cur, WordToFind, strlen(WordToFind)) == 0) {count ++;}
  }
  
  printf("found the word \"%s\" %d times.\n", WordToFind, count);
  
  fclose(hFile);
}
