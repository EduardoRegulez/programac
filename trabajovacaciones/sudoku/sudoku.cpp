#include <stdio.h>
#include <stdlib.h>
#define lados 9 
int tabla[lados][lados];

//generate random numbers to input
//
void entrada( int col,int fila,int input){

    printf("columna? ");
    scanf("%i",&col);
    printf("fila? ");
    scanf("%i",&fila);
    printf("numero para introducir :");
    scanf("%i",&input);

    tabla[col][fila] = input;

}

//check at the end if numbers are equal to 10 in total in  every sense










int main(int argc, const char **argv){

      int sumador,entcol,entfila,entinput;


    
    for(int i=0;i<9;i++){
	for(int i2=0;i2<9;i2++){

	sumador += tabla[i][i2];

      while(tabla[i][i2]==0)
      entrada(entcol,entfila,entinput);
    }}
    if(sumador==405)
    
    printf("has ganado! \n");

    return EXIT_SUCCESS;
}
