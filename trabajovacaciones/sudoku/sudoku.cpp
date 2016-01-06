#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lados 9 
int tabla[lados][lados];

//generate random numbers to input
//
void generador(){

    
    for(int r=0;r<11;r++){

    srand (time(NULL));
    int random = rand() % 10;
    int random2 = rand() % 10;
    int randominput = rand() % 9;
    randominput=randominput +1;

    tabla[random][random2]=randominput;
    for(int l =0;l<9;l++)
    while(tabla[random][random2]== tabla[random][l]||tabla[random][random2]==tabla[l][random2])
	int randominput = rand() % 9;
    	tabla[random][random2]=randominput;
	
    }
}
void entrada( int col,int fila,int input){

    printf("columna? ");
    scanf("%i",&col);
    printf("fila? ");
    scanf("%i",&fila);
    printf("numero para introducir :");
    scanf("%i",&input);
    if(input>9||input<1)
    printf("numero no acceptado introduce numero entre 1 y 9 :");
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
