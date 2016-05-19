#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero1;
    int numero2;
    int suma =0;



        printf("elige el numero 1 ");
    scanf("%i",&numero1);

	printf("elige el numero 2 ");
    scanf("%i",&numero2);

    while(numero2 >= 1){
        
	if(numero2%2 == 1){
	
	    suma=suma + numero1;

	}
	numero1*=2;
	numero2/=2;
    }
    printf("multiplicación = %i \n ",suma);


	return EXIT_SUCCESS;
}
