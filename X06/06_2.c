#include <stdio.h>
#include <stdlib.h>

// ========================================================================= //

int main(int argc, char ** argv) {
  if (argc == 1) {
    printf("command line multiplication tool\n");
    printf("use this to compute the product of any count of numbers.\n");
    printf("usage:\n");
    printf("\t%s [numbers]\n", *argv);
    printf("example:\n");
    printf("\t%s 1 2 3.5\n", *argv);
    printf("output:\n");
    printf("\t7\n");

    return 1;     // tell the OS that the call was faulty
    
  } else {
    int i;
    double product = 1;

    for (i=1; i<argc; i++) {
        product *= atof( argv[i] );
    }
  
    printf("%lf\n", product);
    return 0;	// OS: everything is fine
  }
}
