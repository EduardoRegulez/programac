/*
    proyecto poker
*/
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>   
#include <stdlib.h>   
#include <arpa/inet.h>
#include <unistd.h>   
#include <pthread.h>
#include <time.h>
#include <stdlib.h> 
#include <stdbool.h>
#define n 5
#define numeroCartas 52
#define numerosocket 4


bool next_round = false;
int numjugadores;
int i = 0;
int inc = 0, inc2;
int arrCards[numeroCartas];
int roundcounter = 0;


struct cartas{
    int numero;
    char  * palo;
};
struct cartas car[numeroCartas];
 

struct Usuarios{
    int id;
    int moneyOnHand;
    int cards[2];
    bool smallBlind;
    bool bigBlind;
    bool fold;
    bool check;
    bool raised;
    int pone_ronda;
};

struct Usuarios user[n];

struct Juego_Estructura{
    int turno_usuario;
    //bool groupo_dinero[numjugadores];
    //"IN" action Raise call fold
    int dinero_alto;
    int cards[5];
    int dinero_total;
    int ganador_ronda;
    bool findeRonda;
    int fase;
};

struct Juego_Estructura juego_estructura;

void empiezacartas (/*int arrCards[]*/){
        for (int i = 0; i < numeroCartas; ++i)
    {
        arrCards[i] = i+1;
    }
}

void shuffle ( /*int arrCards[]*/){

    srand ( time(NULL) );
    for (int i = numeroCartas-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        int temp = arrCards[i];
        arrCards[i] = arrCards[j];
        arrCards[j] = temp;
    }
}

void mandar_datos(){
    for (int i = 0; i < numjugadores; ++i)
    { 
        write(i+numerosocket, &user[i], sizeof(struct Usuarios));
        write(i+numerosocket, &juego_estructura, sizeof(struct Juego_Estructura));
    }
   

}


void cartas_partida(){
    shuffle (/*arrCards*/);
    for (int i = 0; i < 5; ++i)
    {
        juego_estructura.cards[i] = arrCards[i];
    }
    int nuevacarta = 5;
    for (int i = 0; i < numjugadores; ++i)
    {
    user[i].cards[0] = arrCards[nuevacarta];
    nuevacarta++;
    user[i].cards[1] = arrCards[nuevacarta];
    nuevacarta++;
    }
  //  write(ii+4, &user[ii], sizeof(struct Usuarios));
    //write everything
}



void inicio(int ii)
{
    //Get the socket descriptor

    user[ii].id = ii;
    user[ii].moneyOnHand = 1000;
    user[ii].fold = false;
    user[ii].check = false;
   // cartas_partida();
  ///  write(ii+4, &user[ii], sizeof(struct Usuarios));


}



void big_small_blind(){
     inc2 = 1 + inc;
     if(inc>=numjugadores)
        inc=0;
     if(inc2>=numjugadores)
        inc2=0;

     if(inc == 0)
        user[numjugadores-1].bigBlind = false;
    else{
        user[inc-1].bigBlind = false;
    }
     if (inc2 == 0)
        user[numjugadores-1].smallBlind = false;
    else{
        user[inc2-1].smallBlind = false;
    }

     user[inc].bigBlind = true;
     user[inc2].smallBlind = true;

            if (user[inc2].moneyOnHand <= 5)
            {
                user[inc2].pone_ronda = user[inc2].moneyOnHand;
                juego_estructura.dinero_alto = user[inc2].pone_ronda;
                juego_estructura.dinero_total += user[inc2].pone_ronda;
                user[inc2].moneyOnHand = 0;


            }
            else{
                user[inc2].pone_ronda = 5;
                juego_estructura.dinero_alto = user[inc2].pone_ronda;
                juego_estructura.dinero_total += user[inc2].pone_ronda;
                user[inc2].moneyOnHand -=  user[inc2].pone_ronda;
            }
        


            if (user[inc].moneyOnHand <= 10)
            {
                user[inc].pone_ronda = user[inc].moneyOnHand;
                juego_estructura.dinero_alto = user[inc].pone_ronda;
                juego_estructura.dinero_total += user[inc2].pone_ronda;
                user[inc].moneyOnHand = 0;

            }
            else{
                user[inc].pone_ronda = 10;
                juego_estructura.dinero_alto = user[inc].pone_ronda;
                juego_estructura.dinero_total += user[inc2].pone_ronda;
                user[inc].moneyOnHand -=  user[inc].pone_ronda;

            }

        
     inc++;

     
}


void limpiar(){
            for (int i = 0; i < numjugadores; ++i)
        {
            user[i].fold = false;
            user[i].check = false;

            user[i].raised = false;
            user[i].pone_ronda = 0;
            juego_estructura.ganador_ronda = 5;
            juego_estructura.dinero_total = 0;
            juego_estructura.dinero_alto = 0;

        }

}

// void juego(int, bool [][2]);



bool juego(int ii, /*doineedthisbool findeRonda,*/ int foldcount, bool players[][2]){
       char str[5];
        int array_ganadores[numjugadores][2];
        int next_round_counter = 0;
        next_round = false;
      //  puts("-1-");
                    // char str[5];
                    // puts("iithis is jugador actual");
                    //  sprintf(str, "%d", ii);
                    // puts(str);


        bool ganador = false;
        juego_estructura.turno_usuario = ii;
   // for (int i = 0; i < numjugadores ; ++i)
      //  puts("gone thru 2");
        write(ii+numerosocket, &juego_estructura, sizeof(struct Juego_Estructura));
        recv(ii+numerosocket, &user[ii], sizeof(struct Usuarios), 0);
        recv(ii+numerosocket, &juego_estructura, sizeof(struct Juego_Estructura), 0);
      //  puts("gone thru 2");


        for (int i = 0; i < numjugadores; ++i)
        {
         if (user[i].fold == true)
        {
            foldcount++;
            players[i][0] = false;
            players[i][1] = true;
            return false;
        }
        if (user[i].fold == false)
        {
            players[i][1] = false;
        }
        if(user[i].check == true)
           players[i][0] = true;

        if(user[i].check == false)
           players[i][0] = false;
        }



        if((foldcount + 1) ==  numjugadores){
            juego_estructura.ganador_ronda = juego_estructura.turno_usuario;
          //  return true;
        }

            for (int i = 0; i < numjugadores ; ++i){
            if(players[i][1] == false && players[i][0] == false)
                next_round_counter++;}
            puts("next_round_counter va por");
            sprintf(str, "%d", next_round_counter);
            puts(str);

            if (next_round_counter==0)
                next_round = true;
            
            if (next_round == true)
                {
                roundcounter++;
                puts("roundcounter");
                sprintf(str, "%d", roundcounter);
                puts(str);
                puts("usuario");
                sprintf(str, "%d", ii);
                puts(str);
                for (int i = 0; i < numjugadores ; ++i){
                user[i].check = false;
                players[i][0] = false;
                puts("check");
                sprintf(str, "%d", user[i].check);
                puts(str);
                puts("check n 2");
                sprintf(str, "%d", players[i][0]);
                puts(str);
            }
                next_round_counter = 0;
                next_round = false;
                }
                
        switch(roundcounter) {
        case 0 :
       // juego_estructura.fase = 0;
        break;
        case 1 :
        juego_estructura.fase = 1;
        break;
        case 2 :
        juego_estructura.fase = 2;
        break;
        case 3 :
        juego_estructura.fase = 3;
        ganador = true;
        break;
    }


    //     puts("-2-");
    //     if (players[ii][1]==true)
    //     {
    //         return false;
    //     }
    //     for (int i = 0; i < numjugadores ; ++i)
    //     if(players[i][1] == false && players[i][0] == false){
    //         togocounter++;
    //     }
    //     if (togocounter == 0)
    //     {
    //         roundcounter++;
    //         for (int i = 0; i < numjugadores ; ++i)
    //              players[i][0] = false;
    //     }

    //     puts("-3-");
    //     switch(roundcounter) {
    //     case 0 :
    //     juego_estructura.fase = 0;
    //     break;
    //     case 1 :
    //     juego_estructura.fase = 1;
    //     break;
    //     case 2 :
    //     juego_estructura.fase = 2;
    //     ganador = true;
    //     break;
    // }
    //     if((players[ii][1]!=true) && (foldcount == (numjugadores-1))){
    //         juego_estructura.ganador_ronda = ii;
    //         //????has ganado
    //         return true;
    //     }
    //     char str[5];
    //     puts("what is the result");
    //     sprintf(str, "%d", user[ii].fold);
    //         puts(str);
        
    //     if(/*players[ii][1]!=true && */user[ii].fold == true)
    // {
    //     puts("fold");
    //     players[ii][1]=true;
    //     players[ii][0] = false;
    //     foldcount++;
    // }
    
    //     if(user[ii].check == true)
    //         players[ii][0] = true;


    //     if(user[ii].raised == true){
    //     for (int i = 0; i < numjugadores; ++i)
    //     {
    //         user[i].check = false;
    //         players[i][0] = false;
    //     }
    //         user[ii].check = true;
    //         user[ii].raised = false;
    // }

    //     if (ganador==true)
    //     {
    //         int **array_ganador;
    //         int j = 0;
    //         for (int i = 0; i < numjugadores; ++i)
    //         {
    //             //  if(user[i].check == true){
    //             // array_ganador[0][j] = (int) malloc (j+1);
    //             // array_ganador[1][j] = (int) malloc (j+1);
    //             // array_ganador[0][j] = user[i]cards[0];
    //             // array_ganador[1][j] = user[i]cards[1];
    //             // //alternate make a full array and determine if its all good from all
    //             // }free(array_ganador);
    //             if(user[i].check == true){
    //                 array_ganadores[i][0] = user[i].cards[0];
    //                 array_ganadores[i][1] = user[i].cards[1];
                                
    //             players[0][i] = false;
    //             players[1][i] = false;
    //             }
    //         }
           // reglas(array_ganadores);
     //       return true;
           
       // }
        puts("end of juego loop");


    return false;
}



void reglas(int array_ganadores[][2]){
/*    



***exterior file***


Rulezz
    winning money etc
    */
}






 
int main(int argc , char *argv[])
{


    int socket_desc , socket_cliente , c ;
    struct sockaddr_in servidor , cliente;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    puts("Socket creado");
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons( 7777 );
    bind(socket_desc,(struct sockaddr *)&servidor , sizeof(servidor));
    puts("bind");
    printf("Esperar a cuantos jugadores?  (5 Maximo)\n");
    scanf("%d" , &numjugadores);
    listen(socket_desc , 5);
    puts("Esperando jugadores...");
    bool empieza = false;
    empiezacartas(/*arrCards*/);
   // shuffle (/*arrCards*/);
    int counter=0;
    bool players[numjugadores][2];


    //togocounter = 1;
   while(socket_cliente = (accept(socket_desc, (struct sockaddr *)&cliente, (socklen_t*)&c)) && (i < numjugadores)){
        counter += socket_cliente;
        if(counter==numjugadores){
        if(empieza == false){
            //big_small_blind();
            for (int i = 0; i < numjugadores ; ++i)
            {


                inicio(i);
                 if((numjugadores-1)==i)
                    empieza=true;
            }


        }
        while(1){
        if(empieza == true){
            puts("here I am again");
            juego_estructura.ganador_ronda = -1;
           // limpiar();
            big_small_blind();
            cartas_partida();
            for (int i = 0; i < numjugadores; ++i)
            {
                            char str[5];
        sprintf(str, "%d", user[i].id);
            puts(str);
        sprintf(str, "%d", user[i].moneyOnHand);
        puts(str);
        sprintf(str, "%d", user[i].cards[0]);
        puts(str);
        sprintf(str, "%d", user[i].cards[1]);
        puts(str);
        sprintf(str, "%d", user[i].smallBlind);
        puts(str);
        sprintf(str, "%d", user[i].bigBlind);
        puts(str);
        sprintf(str, "%d", user[i].check);
        puts(str);
        sprintf(str, "%d", user[i].raised);
        puts(str);
        sprintf(str, "%d", user[i].pone_ronda);
        puts(str);
            }
            mandar_datos();//check
            juego_estructura.findeRonda = false;
            int foldcount = 0;
            
            int jugadorActual = inc;
            while (juego_estructura.findeRonda == false)
            {
             //  players[jugadorActual][1]=false;
               //players[jugadorActual][0] =false;

                 juego_estructura.findeRonda = juego(jugadorActual, foldcount, players);

                 jugadorActual++;
                 if (numjugadores==jugadorActual ){
                    jugadorActual = 0;
                }
             }


}

 }}}
return 0;
}
