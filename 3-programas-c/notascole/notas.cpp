#include <stdio.h>
#include <stdlib.h>

int main(){

    char assign1[12];
	char assign2[12];
       char assign3[12];
      char assign4[12];
     char assign5[12];
    char assign6[12];
    int media1,media2 ,media3,media4,media5,media6;
    int mediatotal=0;
    int divider = 6;
   
    printf("Como se llama tu assignatura 1 ?\n");
    scanf("%s", assign1);
    printf("cual es la Media?\n");
    scanf("%d", &media1);
    printf("Como se llama tu assignatura 2 ?\n");
    scanf("%s", assign2);
    printf("cual es la Media?\n");
    scanf("%d", &media2); 
    printf("Como se llama tu assignatura 3 ?\n");
    scanf("%s", assign3);
    printf("cual es la Media?\n");
    scanf("%d", &media3);
    printf("Como se llama tu assignatura 4 ?\n");
    scanf("%s", assign4);
    printf("cual es la Media?\n");
    scanf("%d", &media4);
    printf("Como se llama tu assignatura 5 ?\n");
    scanf("%s", assign5);
    printf("cual es la Media?\n");
    scanf("%d", &media5);
    printf("Como se llama tu assignatura 6 ?\n");
    scanf("%s", assign6);
    printf("cual es la Media?\n");
    scanf("%d", &media6);
    mediatotal = (media1+media2+media3+media4+media5+media6)/divider;
    	 printf("%s, %d de 10 \n",assign1,media1);
	 printf("%s, %d de 10 \n",assign2,media2);
	 printf("%s, %d de 10 \n",assign3,media3); 
	 printf("%s, %d de 10 \n",assign4,media4);
	 printf("%s, %d de 10 \n",assign5,media5);
	 printf("%s, %d de 10 \n",assign6,media6);
	 printf("\n \n \n Media total %d de 10 \n", mediatotal);
		 if(mediatotal<=6){
		      if(mediatotal>=5)

	     printf("Bien hecho \n");

	 }
		 	 if(mediatotal<=8){
		      if(mediatotal>=7)

	     printf("MUY Bien hecho \n");

	 }
			 	 if(mediatotal<=10){
		      if(mediatotal>=9)

			  printf("Estas como un Tanque! \n");

	 }

					 if(mediatotal<5){
	
	     printf("puff tienes que mejorar \n");

	 }






	if( media1>=media2 && media1>=media5 && media1>=media3 && media1>=media4 && media1>=media6){
	    printf("Nota mas alta es: %i \t assignatura %s \n ", media1, assign1);
	} else if(media2>=media1 &&media2>=media3 && media2>=media4 && media2>=media5 && media2>=media6){
	    printf("Nota mas alta es: %i \t assignatura %s \n ", media2, assign2);
	} else if(media3>=media1 &&media3>=media2 && media3>=media4 && media3>=media5 && media3>=media6){
	    printf("Nota mas alta es: %i \t assignatura %s \n ", media3, assign3);
	}else if(media4>=media1 &&media4>=media3 && media4>=media2 && media4>=media5 && media4>=media6){
	    printf("Nota mas alta es: %i \t assignatura %s \n ", media4, assign4);
	}else if(media5>=media1 &&media5>=media3 && media5>=media4 && media5>=media2 && media5>=media6){
	    printf("Nota mas alta es: %i \t assignatura %s \n ", media5, assign5);
	}else if(media6>=media1 &&media6>=media3 && media6>=media4 && media6>=media5 && media6>=media2){
	    printf("Nota mas alta es: %i \t assignatura %s \n ", media6, assign6);
	}

 	if(media1<=media2 &&media1<=media5 && media1<=media3 && media1<=media4 && media1<=media6){
	    printf("Nota mas baja es: %i \t assignatura %s \n ", media1, assign1);
	} else if(media2<=media1 &&media2<=media3 && media2<=media4 && media2<=media5 && media2<=media6){
	    printf("Nota mas baja es: %i \t assignatura %s \n ", media2, assign2);
	} else if(media3<=media1 &&media3<=media2 && media3<=media4 && media3<=media5 && media3<=media6){
	    printf("Nota mas baja es: %i \t assignatura %s \n ", media3, assign3);
	}else if(media4<=media1 &&media4<=media3 && media4<=media2 && media4<=media5 && media4<=media6){
	    printf("Nota mas baja es: %i \t assignatura %s \n ", media4, assign4);
	}else if(media5<=media1 &&media5<=media3 && media5<=media4 && media5<=media2 && media5<=media6){
	    printf("Nota mas baja es: %i \t assignatura %s \n ", media5, assign5);
	}else if(media6<=media1 &&media6<=media3 && media6<=media4 && media6<=media5 && media6<=media2){
	    printf("Nota mas baja es: %i \t assignatura %s \n ", media6, assign6);
	}





















    return EXIT_SUCCESS;

}
