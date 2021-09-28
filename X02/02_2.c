#include <stdio.h>

int main (void) {
  double seed = 0, interest = 0, goal = 0;
  int years = 0;
  
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
