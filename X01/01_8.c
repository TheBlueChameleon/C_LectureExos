#include <stdio.h>
#include <math.h>

int main(void) {
  double a, b, c;
  double disc;
  double x1, x2;
  
  printf("Bitte Parameter a eingeben:\n");
  scanf("%lf", &a);
  
  printf("Bitte Parameter b eingeben:\n");
  scanf("%lf", &b);
  
  printf("Bitte Parameter c eingeben:\n");
  scanf("%lf", &c);

  disc = b*b - 4*a*c;
  
  if (disc > 0) {
    x1 = (  -b + sqrt(disc)  ) / (2*a);
    x2 = (  -b - sqrt(disc)  ) / (2*a);
    
    printf("Loesung 1: %lf\n", x1);
    printf("Loesung 2: %lf\n", x2);
    
  } else {
    printf("keine reellen Loesungen\n");
  }
}
