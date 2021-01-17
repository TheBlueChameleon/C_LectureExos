#include <stdio.h>

int main () {
  int jahr;
  
  printf("Bitte geben Sie das zu testende Jahr ein:\n");
  scanf("%d", jahr);
  printf("Jahr %d ist ", jahr);

  /* Variante 1, mit Verschachtelung */
  if (jahr % 4 == 0) {
    if (jahr % 100 == 0) {
      if (jahr % 400 == 0) {
        printf("ein Schaltjahr.\n");
      } else {
        printf("kein Schaltjahr.\n");
      }
    } else {
      printf("ein Schaltjahr.\n");
    }
  } else {
    printf("kein Schaltjahr.\n");
  }

  /* Variante 2, mit && und || */
  if (jahr % 400 == 0 || (jahr % 4 == 0  && jahr % 100 != 0)) {
    printf("ist Schaltjahr\n");
  } else {
    printf("ist kein Schaltjahr\n");
  }
}
