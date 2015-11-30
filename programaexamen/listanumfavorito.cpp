#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 10

int main(){



   
   //system("toilet -F border --gay -f pagga \"Numero favorito de tus estudiantes \""); 

    
    FILE * fp;
  	
	 char nomyapel1[10], nomyapel2[10];
	 char  deseo[1];
	 int numfav, numalumnos,revesorigen,revesdestino =0;   	 
	 fp = fopen ("numerofavorito.txt","w");


	 puts("Cuantos alumnos desean saber sobre sun numero favorito?");
	 scanf(" %i", &numalumnos);
	 
	 





	 for (int n =0;n<numalumnos;n++){
	  printf("nombre apellido numerofavorito\n");

	  scanf ("%s %s %i", nomyapel1, nomyapel2,  &numfav);
	  revesorigen = numfav;

	   while ( revesorigen != 0 ){  revesdestino *= 10;
		revesdestino += revesorigen % 10;
		revesorigen /= 10;

    		}

          fprintf (fp,"%s %s %i %i %i %x %X \n", nomyapel1, nomyapel2,numfav, revesdestino,revesdestino + numfav,numfav,numfav);
	   revesdestino =0;
	 }


         printf("\n deseas ver un ejemplo de la ultima linea del archivo?");
	 scanf("%s",deseo);

	 if (strcmp(deseo, "S") == 0){

	       printf ("%s %s %i %i %i %x %X \n", nomyapel1, nomyapel2,numfav, revesdestino,revesdestino + numfav,numfav,numfav);

	 }else{
	 printf("pues vale\n");
	 
	 }
	


		 


	  fclose (fp);
    

    
    return EXIT_SUCCESS;
}
