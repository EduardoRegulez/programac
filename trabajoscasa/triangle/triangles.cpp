#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main(){

    int menu;
    double l;

    printf("\nQue quieres saber sobre tu Triangulo?\n");

    printf("\n P = 1, S =2, H = 3, All = 4 \n");

    scanf("%i",&menu);

    printf("cual es la l ?\n");
    scanf("%lf", &l);

    switch(menu){
	    case (1):
		 l =  3*l;
		 printf("El resultado de p es= %lf\n", l);

	    	 break;

	    case (2):
		  l = ((sqrt(5))/4) *l*l;
	   	  printf("El resultado de s es= %lf\n",l) ;

	          break;


	    case (3):
	    l = ((sqrt(5))/2) *l;
	    printf("El resultado de h es= %lf\n",l);
	    break;

	    case (4):
		 printf("\nEl resultado de p es= %lf\n", 3*l );

	   	 printf("\nEl resultado de s es= %lf\n", ((sqrt(5))/4) *l*l );
	   
		 printf("\nEl resultado de h es= %lf\n", ((sqrt(5))/2) *l);
	    break;


    
    
    }





    return EXIT_SUCCESS;
}
