#include <stdio.h>
#include <stdlib.h>
#define S 9

int main(){

    int numeros[9]={3, 7, 1, 9, 2, 1, 4, 2, 5};



    int t;
    for (int i = 0; i < S; i++){ 
	for (int j = 0; j < S - 1; j++) {
	    if (numeros[j]>numeros[j + 1]) {
		t = numeros[j];
		numeros[j] = numeros[j + 1];
		numeros[j + 1] = t;
	    }}}



    printf("orden es : ");
    for (int i = 0; i < S; i++)
	printf("%i \t",numeros[i]);



    return EXIT_SUCCESS;
}
