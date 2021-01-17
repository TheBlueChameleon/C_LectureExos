#include <stdio.h>

int main (void) {
  int    a = 7  , b = 5  ;
  double x = 7.0, y = 5.0;
  
  printf("int\n");
  printf("Summe    : %d\n", a+b);
  printf("Differenz: %d\n", a-b);
  printf("Produkt  : %d\n", a*b);
  printf("Quotient : %d (Achtung: falsch abgerundet!)\n",            a/b );
  printf("Quotient : %d (Korrekte Rechnung)\n",            (double)  a/b );
  printf("Quotient : %d (Achtung: zu früh abgerundet!)\n", (double) (a/b));
  
  printf("double\n");
  printf("Summe    : %lf\n", x+y);
  printf("Differenz: %lf\n", x-y);
  printf("Produkt  : %lf\n", x*y);
  printf("Quotient : %lf\n", x/y);
}
