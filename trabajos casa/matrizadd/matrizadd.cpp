#include <stdio.h>
#include <stdlib.h>


int main(){


    int c[4][5], a[4][3] , b[3][5];

    for(int i=0;i<4;i++){

	for(int j=0;j<5;j++){
	    c[i][j]=0;
	    for(int k = 0; k<3;k++){



		b[k][i]=1;//esto es para comprobar resultado


		a[i][k]=1;//esto es para comprobar resultado




		c[i][j]=c[i][j]+ a[i][k]*b[k][i];



	    }}}
    printf("%i",c[0][0]);//si resultado es 3 significa que la matric funciona

    return EXIT_SUCCESS;
}
