#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ========================================================================= //

int palin (char * c) {
  int length = strlen(c);
  
  for (int i = 0; i < length / 2; i++) {
    if (tolower(c[i]) != tolower(c[length - 1 - i])) {return 0;}
  }
  
  return 1;
}

// ========================================================================= //

int main () {
  char phrase[1024];
  printf("Please enter a phrase to be checked:\n");
  scanf("%[^\n]", phrase);
  
  printf("\"%s\" is %sa palindrome.\n",
    phrase,
    palin(phrase)  ?  ""  :  "not "
  );
}
