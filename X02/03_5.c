#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void) {
  char  inString[256];
  char outString[256];
    
  scanf("%255[ a-zA-Z0-9]", inString);
  
  for (int i=0; i<strlen(inString); i++) {
    // either
    outString[i] = tolower(inString[i]);
    
    // or
    outString[i] = (inString[i] >= 'A' && inString[i] <= 'Z') ?
                    inString[i] + 32 : inString[i];
    
    // or
    if (inString[i] >= 'A' && inString[i]) {inString[i] + 32;}
  }
  
  printf("before:\n");
  printf("%s\n", inString);
  printf("after:\n");
  printf("%s\n", outString);
}
