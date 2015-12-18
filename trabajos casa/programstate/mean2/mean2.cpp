
  #include <stdio.h>
#include <stdlib.h>

int main(){ 

    int input,con=0, a, stop, count=0;//stop es el numero que sea
    printf("vete poniendo numeros\n");
    while(a!=stop){    
    scanf("%i",&input);
    if(input<0){
	input =0;
	a=stop;}
	con +=input;
	count++;
        }
	printf("mean es \n");
  	printf("%i \n", con/(count-1));

    return EXIT_SUCCESS;
}
