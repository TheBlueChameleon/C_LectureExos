#include <stdio.h>
#include <string.h>

// ========================================================================= //

void rectifyText (char * sourceText) {
  int N = strlen(sourceText);
  int offset             = 0;
  int trimActive         = 1;
  
  for (int i=0; i<N; i++) {
    sourceText[offset] = sourceText[i];
    
    if (sourceText[i] != ' ') {
      trimActive = 0;
      offset++;
      
    } else {
      if (!trimActive) {trimActive = 1; offset++;}
    }
  }
  
  if (sourceText[offset - 1] == ' ') {offset--;}
  sourceText[offset] = 0;
}

// ========================================================================= //

int main () {
  char text[] = "    Ein   Text       mit  vielen   Leerzeichen   ";
  
  printf("before:\n\"%s\"\n\n", text);
  rectifyText(text);
  printf("after:\n\"%s\"\n", text);
}
