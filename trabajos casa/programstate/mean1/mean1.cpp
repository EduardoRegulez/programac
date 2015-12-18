#include <stdio.h>
#include <stdlib.h>

int main(){
    int resultado;

    int input,con=0, a;

    printf("vete poniendo numeros\n");


    while(a!=10){
    
    scanf("%i",&input);

    con  +=input;
    a++;
    }

	printf("mean es \n");
  	printf("%i \n", con/10);

    return EXIT_SUCCESS;
}
