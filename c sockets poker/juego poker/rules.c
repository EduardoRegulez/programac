/*

    Este archivo emula lo que seria la funcion "reglas()""

*/
#include <stdio.h>
#include <stdlib.h>
#define n 53
#include <time.h>
#include <string.h>
#include <stdbool.h>

struct Usuarios{
    int id;
    int moneyOnHand;
    int cards[2];
    int numjugadorx =i donno;
    int testtme[numjugadorx];
    bool smallBlind;
    bool bigBlind;
    bool fold;
    bool check;
    bool raised;
    int pone_ronda;
};
struct Usuarios user[n];
// #pragma pack(0)

// #pragma pack(1)
struct Juego_Estructura{
    int turno_usuario;
    //bool groupo_dinero[numjugadores];
    //"IN" action Raise call fold
    int dinero_alto;
    int cards[5];
    int dinero_total;
    int ganador_ronda;
};
//after "start"
struct Juego_Estructura juego_estructura;

    struct cartas{
    int numero;
    char  * palo;
};
struct cartas car[n];
int numjugadores = 5;
int numerocartastotal = 7;

void Crea_Cartas(){
      for(int i = 0; i < n; i++){
    //test the values

	 if(i<=13){
	car[i].numero = i;
    car[i].palo  = "Clubs";
}
	if(i > 13 && i <= 26){
	car[i].numero = i - 13;
    car[i].palo  = "Hearts";
}
	if(i > 26 && i <= 39){
	car[i].numero = i - 26;
    car[i].palo  = "Diamond";
}
	if(i > 39 && i <= 52){
	car[i].numero = i - 39;
    car[i].palo  = "Spades";
}




}

}
void reglas(int *array_ganador){
    bool threekind;
    int paircount;

    int cartas_jugador[numjugadores];
    for (int i = 0; i < numjugadores; ++i)
    if (array_ganador[i] == 1)
    {
        j=0;
        for (int ii = 0; ii < numerocartastotal; ++ii){
            if(i < 5)
            cartas_jugador[ii] = juego_estructura.cards[ii];
            if(i > 5)
            cartas_jugador[ii] = user[i].cards[j];
            j++;
        }
            for (int ii = 0; ii < numerocartastotal; ++ii){
            printf("%d \n",cartas_jugador[ii]);
            printf("%d \n",car[cartas_jugador[ii]].numero);
        }
        printf("test reach");
 int highcard = 0, lowcard, ranking = 0;
 bool repticion_fuera;
 int comparar[numjugadores][3];
 int temp;
 int countfila = 0;
 for (int ii = 0; ii < numerocartastotal; ++ii){
                //ranking = 0;
                //highcard = 0;
                if(ii < 4)
                if (car[cartas_jugador[ii]].numero == car[cartas_jugador[ii+1]].numero && car[cartas_jugador[i]].numero == car[cartas_jugador[i+2]].numero && car[cartas_jugador[i]].numero == car[cartas_jugador[i+3]].numero)
                {
                    printf("%s starting at position %d\n", "you have four", ii);
                    ii+=3;
                    ranking = 3;
                }

                if(ii < 5)
                if (car[cartas_jugador[ii]].numero == car[cartas_jugador[ii+1]].numero && car[cartas_jugador[ii]].numero == car[cartas_jugador[ii+2]].numero)
                {
                    printf("%s starting at position %d\n", "you have 3", ii);
                    ii+=2;
                    threekind=true;
                    highcard=car[cartas_jugador[ii]].numero;
                }

                if(ii < 6){
                if (car[cartas_jugador[ii]].numero == car[cartas_jugador[ii+1]].numero)
                {
                    printf("%s starting at position %d\n", "you have 2", ii);
                    ii+=1;
                    paircount++;
                    if(paircount == 1)
                    temp = car[cartas_jugador[ii]].numero;
                    if(paircount == 2){
                    if (temp>car[cartas_jugador[ii]].numero)
                    {
                        highcard = temp;
                        lowcard = car[cartas_jugador[ii]].numero;
                    } else{
                        highcard = car[cartas_jugador[ii]].numero;
                        lowcard = temp;
                    }}
                    if(paircount == 3){
                        if(car[cartas_jugador[ii]].numero > highcard){
                            lowcard = highcard;
                            highcard = car[cartas_jugador[ii]].numero;
                        }
                        if((car[cartas_jugador[ii]].numero < highcard) && (car[cartas_jugador[ii]].numero > lowcard))
                            lowcard = car[cartas_jugador[ii]].numero;

                    }


                    if(ii<5)
                    repticion_fuera=true;
                }

                //find same color 5
                //if(ii < 3)
             //   for(int u = 0; i< 6; i++)
                if((car[cartas_jugador[ii+1]].numero - car[cartas_jugador[ii]].numero) == 1){
                                countfila++;
                            if (countfila > 4){
                                printf("%s\n", "flush!!!");
                                ranking=6;//if these are High numbers  //take in top
                                //if these are also clored (2)

                                //if the top number is king or whatever and color(1)
                                //***--get high card***
                            }

//                            if ((car[cartas_jugador[ii+1]].numero - car[cartas_jugador[ii]].numero ) != 1 || (car[cartas_jugador[i+1]].numero - car[cartas_jugador[i]].numero ) != 0 )
//                                countfila = 0;
                    }

                    if(ranking==0)
                        ranking = 10;
                 if (car[cartas_jugador[5]].numero > car[cartas_jugador[6]].numero){}
                    if(highcard==0)
                     highcard = car[cartas_jugador[5]].numero;
                    else{
                    if(highcard==0)
                        highcard = car[cartas_jugador[6]].numero;
                 }

                if (paircount >= 1)
                {
                if (paircount >= 2)
                    ranking = 8;
                if (repticion_fuera != true)
                    ranking = 9;
                }
                if(threekind == true){
                    if(paircount >= 1)
                    ranking = 4;
                    ranking = 7;

                }
                comparar[i][0]=ranking;
                comparar[i][1]=highcard;
                comparar[i][2]=lowcard;

                }}
                int numero_grande, posicion;
                    for (i = 0; i < numjugadores; i++)
                    {
                    if (numero_grande < comparar[i][0]){
                        numero_grande = comparar[i][0];
                        posicion=i;
                    }
                    }

          int numero_grande, posicion;
                    for (i = 0; i < numjugadores; i++)
                    {
                    if (numero_grande < comparar[i][0]){
                        numero_grande = comparar[i][0];
                        posicion=i;
                    }
                    }

                    for (int i = 0; i < numjugadores - 1; i++) {
                    for (int j = i + 1; j < numjugadores; j++) {
                    if (comparar[i][0] == comparar[j][0]) {
                          if(comparar[i][1] > comparar[j][1]){
                            posicion=i;
                            juego_estructura.ganador_ronda[posicion] = 1;
                          }

                          if(comparar[i][1] < comparar[j][1]){
                            posicion=j;
                            juego_estructura.ganador_ronda[posicion] = 1;
                          }

                          if(comparar[i][1] == comparar[j][1]){
                          if(comparar[i][2] > comparar[j][2]){
                            posicion=i;
                            juego_estructura.ganador_ronda[posicion] = 1;
                          }

                          if(comparar[i][2] < comparar[j][2]){
                            posicion=j;
                            juego_estructura.ganador_ronda[posicion] = 1;
                          }

                          if(comparar[i][2] == comparar[j][2]){
                             juego_estructura.ganador_ronda[i] = 1;
                             juego_estructura.ganador_ronda[j] = 1;
                          }
                            }
                        }
                    }
}

}



int main(int argc , char *argv[])
{
    Crea_Cartas();
juego_estructura.cards[0] =1;
juego_estructura.cards[1] =2;
juego_estructura.cards[2] =3;
juego_estructura.cards[3] =4;
juego_estructura.cards[4] =5;
user[0].cards[0]= 12;
user[0].cards[1]=16;
user[1].cards[0]=32;
user[1].cards[1]=45;
user[2].cards[0]=50;
user[2].cards[1]=23;
user[3].cards[0]=38;
user[3].cards[1]=49;
user[4].cards[0]=40;
user[4].cards[1]=31;

int array_ganador[5];
array_ganador[0]=1;
array_ganador[1]=1;
array_ganador[2]=1;
array_ganador[3]=1;
array_ganador[4]=1;


reglas(array_ganador);


    return 0;
}
