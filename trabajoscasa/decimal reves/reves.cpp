#include <stdio.h>
#include <stdlib.h>
#define BASE 10
int main(){

    int entrada,revesvalor=0;
    printf("Elige un numero del 0 al 999 :");
    scanf(" %i", &entrada);

   // printf("%i", entrada % BASE);
    revesvalor = ((entrada%BASE) * BASE * BASE) + revesvalor;
    entrada/= BASE;
    //printf("%i", entrada % BASE);
    revesvalor = ((entrada%BASE) * BASE) + revesvalor;
    entrada/= BASE;
   // printf("%i", entrada % BASE);
    revesvalor = entrada%BASE + revesvalor;
    printf("\nvalor de variable es : %i \n", revesvalor);
    printf("\n");

    return EXIT_SUCCESS;
}
