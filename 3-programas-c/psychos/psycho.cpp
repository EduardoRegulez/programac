#include <stdio.h>
#include <stdlib.h>

int main(){
    int resultado[10], resultadofinal;

    printf("ELIGE DE 0 a 1, 0 = no lo soy, 1 = si y con orgullo \n");
    printf("1. ¿Eres encantador e inteligente superficialmente?\n");
    scanf("%d",&resultado[0]);

    printf("ELIGE DE 0 a 1, 0 = no tengo esas chorradas como el resto de los humanos, 1 = si, bueno a veces como todos los humanos ¿Quién no ha pensado irracionalmente en algún momento dado? \n");
    printf("2. ¿Tienes delirios u otros signos de pensamiento irracional?\n");
    scanf("%d",&resultado[1]);
    if(resultado[1]==0){
	resultado[1]=1;
    }else if(resultado[1]==1){
	resultado[1]=0;}



     printf("ELIGE DE 0 a 1, 0 = yo? esas chosas? claro que no es para debiles! 1 = si, es normal, todos pasmos por esto\n");
    printf("3. ¿Eres demasiado nervioso o te sientes ansioso en algún momento?\n");
    scanf("%d",&resultado[2]);
    if(resultado[2]==0){
	resultado[2]=1;
    }else if(resultado[2]==1){
	resultado[2]=0;}



     printf("ELIGE DE 0 a 1, 0 = no lo soy, 1 = si soy un dios claro que si!! \n");
    printf("4. ¿Eres una persona muy segura de tí mismo?\n");
    scanf("%d",&resultado[3]);


        printf("ELIGE DE 0 a 1, 0 = intento no mentir, es una falta de respeto. 1 = YO?? Mentir claro que no ;) ;) jajajajajaja! (SI) \n");
 	printf("5. ¿Sueles mentir para salirte con la tuya?\n\n");
    	scanf("%d",&resultado[4]);


	 printf("ELIGE DE 0 a 1, 0 = no te sirve de nada eso claro que no, 1 = si, claro que si.. \n");
    printf("6. ¿Sientes remordimientos o culpa cuando haces algo que no es lo correcto?\n");
    scanf("%d",&resultado[5]);
    if(resultado[5]==0){
	resultado[5]=1;
    }else if(resultado[5]==1){
	resultado[5]=0;}


        printf("ELIGE DE 0 a 1, 0 = diria que no. 1 = Si, no me gustan las personas pero aun asi soy el rey! \n");
 	printf("7. ¿Eres antisocial?\n");
    	scanf("%d",&resultado[6]);



	        printf("ELIGE DE 0 a 1, 0 = no. 1 = Si, tengo todo el derecho de serlo! soy la bomba!!!! \n");
 	printf("8. ¿Eres egocentrico?\n");
    	scanf("%d",&resultado[7]);


		        printf("ELIGE DE 0 a 1, 0 = no. yo amo con toda la gente normal. 1 = claro que no, humanos son mis objetos jajajajaja  \n");
 	printf("9. ¿Eres incapaz de amar?\n");
    	scanf("%d",&resultado[8]);


	printf("ELIGE DE 0 a 1, 0 = no preferio calucular antes de matar, 1 = si, tengo muchas emociones \n");
   	 printf("10. ?Sueles reaccionar emocionalmente? \n");
    	scanf("%d",&resultado[9]);
   	 if(resultado[9]==0){
	resultado[9]=1;
    	}else if(resultado[9]==1){
	resultado[9]=0;}




	 for(int i = 0; i <= 9; i++)
       {
	   printf("\n resultado numero %d = %d", i, resultado[i]);
	    resultadofinal += resultado[i];
       }
	 printf(" la suma es de %d \n", resultadofinal);


	 if(resultadofinal>=4){
	     printf("eres un psycho :(\n");
	 } else {
	     printf("eres normal :)\n");
	 }





































    return EXIT_SUCCESS;
} 
