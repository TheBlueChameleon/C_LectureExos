#include <stdio.h>

int main (void) {
  double seed, interest, goal;
  int years;
  
  printf("Please enter your seed capital:\n");
  scanf("%lf", &seed);
  
  printf("Please enter your interest rate:\n");
  scanf("%lf", &interest);
  interest++;
  
  printf("Please enter your financial goal\n");
  scanf("%lf", &goal);
  
  while(seed < goal) {
    seed *= interest;
    years++;
  }
  
  printf("Reaching your goal takes %d years.\n", years);
}
