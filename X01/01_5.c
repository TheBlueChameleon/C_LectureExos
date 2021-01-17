#include <stdio.h>

int main(void) {
  float inVar;
  
  printf("Bitte geben Sie einen Wert ein.\n");
  scanf("%f", &inVar);
  
  if ( (inVar + 1) > 1 ) {
    printf("groesser!");
  } else {
    printf("Fliesskommagenauigkeit unterschritten!");
  }
}
