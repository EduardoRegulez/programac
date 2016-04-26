#include <stdio.h>
#include <stdlib.h>


int sumadelos(int n){

if (n == 0)
    return 0;
return n + sumadelos(n-1);

}




int main(){
    int numero;

    printf("cual es el numero para sumar");
    scanf("%i",&numero);
    printf("suma d los primeros %i es : %i \n",numero,sumadelos(numero));


    return EXIT_SUCCESS;
}
