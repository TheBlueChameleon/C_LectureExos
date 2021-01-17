#include <stdio.h>

int main(void) {
    printf("rechne: ");
    double x;
    double y;
    char op;
    
    //scanf("%lf %c %lf", &x, &op, &y);
    
    /*  auch ok: */
    scanf("%lf", &x);
    scanf(" %c", &op);
    scanf("%lf", &y);

    printf("operator ist %c\n", op);

    double erg = 0.0;
    switch (op) {
        case '+': 
           erg = x + y; 
           break;
        
        case '-': 
           erg = x - y; 
           break;

        case '*': 
           erg = x * y; 
           break;

        case '/': 
           if (y == 0) {
               printf("Division durch Null\n");
               return 0;
           }
           erg = x / y; 
           break;
           
        default: 
           printf("\nNicht definiert\n");
           return 0;
    }
    printf("%lf %c %lf = %f\n", x, op, y, erg);
}
