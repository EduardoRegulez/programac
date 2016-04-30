#include <stdio.h>
#include <stdlib.h>

int main(){

    int sinorojo, sinoazul;

    printf("Ves el rojo?? Si es 1, No es 0\t");

    scanf("%i", &sinorojo);
    
    printf("Ves el azul?? Si es 1, No es 0 \t");

    scanf("%i", &sinoazul);

    if(sinorojo ==0 && sinoazul==0){
    printf("\nves negro\n");
    }

    else if(sinorojo ==1 && sinoazul==0){
    printf("\nves rojo\n");
    }

    else if(sinorojo ==0 && sinoazul==1){
    printf("\nves azul\n");
    }
    else if(sinorojo ==1 && sinoazul==1){
    printf("\nves morado\n");
    }




    

    return EXIT_SUCCESS;
}
