#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ========================================================================= //

double rand01 () {return (double)rand() / (double)RAND_MAX;}

// ------------------------------------------------------------------------- //

double pi_MC(int dots) {
  double x, y;
  int counter = 0;
  
  for (int i=0; i<dots; i++) {
    x = rand01();
    y = rand01();
    
    counter += x * x   +   y * y <= 1 ? 1 : 0;
  }
  
  return 4 * ((double) counter / dots);
}

// ========================================================================= //

int main(void) {
  srand(time(NULL));
  
  for (int i = 1000; i < 50001; i+=1000) {
    printf("%5d\t%lf\n", i, pi_MC(i));
  }
}
