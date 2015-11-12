#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  	 FILE * fp;
  	 int edad, personnum;
  	 char nombre[10], apellido[10], profession[20],titulo[20];

   	 fp = fopen ("detalles.txt","w");


	 printf("vamos a guardar los detalles de personas\n");
	 printf("A cuantas personas deseas guardar?\n");
	 scanf("%d",&personnum);
	 printf("has eligido guardar a %d personas\n\n", personnum);




	 for (int n =0 ; n< personnum ; n++){
	  printf("nombre apellido profesion titulo y edad do los que desea guardar\n");
	  printf("like this: <nombre> <apellido> <profession> <titulo> <edad> \n");
	   
    	 scanf("%s %s %s %s %d",nombre,apellido,profession,titulo,&edad);
         fprintf (fp,"%s %s %s %s %d  \n",nombre,apellido,profession,titulo,edad);


	
 		    }
	 


	  fclose (fp);


    return EXIT_SUCCESS;
}








