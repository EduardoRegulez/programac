#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
int main(){
    srand (time(NULL));
    int oponente = rand() % 3;
    char usuarios[10];
    int usuarioi;
 
    printf("Elige     Piedra, Papel o Tijeras :");
    scanf("%s", usuarios);

		    
    	if (strcmp(usuarios, "Tijeras") == 0){
    	usuarioi =0;
	printf("Elegiste Tijeras\n");
	}else 	if(strcmp(usuarios, "Piedra") == 0){
	    usuarioi =1;
	printf("Elegiste Piedra\n");
	}else 	if(strcmp(usuarios, "Papel") == 0){
	    usuarioi =2;
	    printf("Elegiste Papel\n");
	}


    if(oponente==0){
	printf("El tiene tijeras\n");
    }
    if(oponente==1){
	printf("El tiene piedra\n");
    }
    if(oponente==2){
	printf("El tiene papel\n");
    }


    if(oponente==0 && usuarioi==1){
	 printf("tu ganas Piedra>Tijeras.\n");

    }else if(oponente==1 && usuarioi==0){
     		printf("eres un loser Piedra>Tijeras\n");

    }
        if(oponente==1 && usuarioi==2){
	 printf("tu ganas Papel>Piedra.\n");

    }else if(oponente==2 && usuarioi==1){
     		printf("eres un loser Papel>Piedra.\n");
    }
        if(oponente==2 && usuarioi==0){
	 printf("tu ganas Tijeras>Papel.\n");

    }else if(oponente==0 && usuarioi==2){
     		printf("eres un loser Tijeras>Papel.\n");
    }
	if(oponente ==usuarioi){
	    printf("has empatado\n");
	}






    return EXIT_SUCCESS;

}
