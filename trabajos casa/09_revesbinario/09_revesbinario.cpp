#include <stdio.h>
#include <stdlib.h>
#define BASE 2

int main(){

    int entrada, test=0;
    printf("Elige un numero del 0 al 999 :");
    scanf(" %i", &entrada);

    while(entrada!=0){
    printf("%i", entrada % BASE);
   
    entrada/= BASE;

    }
   
   
    printf("\n");

    return EXIT_SUCCESS;
}
