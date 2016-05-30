#include <stdio.h>    
#include <stdlib.h>   
int main (){

    double* array = NULL; 
    double numero = 1;
    int inc = 0;

    while (numero!=0) {
	printf ("numero: ");
	scanf ("%lf", &numero);
	array= (double*) realloc (array,  sizeof(double));
	array[inc]=numero;
	inc++;

    }

    double t;
    for(int i = sizeof(array)-1 ;i>0;i--){
	t= 1/array[i];
	t+= array[i-1];  
    }

    printf("Resultado = %lf \n",t);
    free (array);

    return EXIT_SUCCESS;
}



