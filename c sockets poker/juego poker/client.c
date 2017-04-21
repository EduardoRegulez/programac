/*
    proyecto poker
*/
#include <sys/socket.h>   
#include <stdio.h> 
#include <string.h>     
#include <arpa/inet.h> 
#include <stdbool.h>
#define MAX_usuarios 5
 
/* #pragma pack(1)*/
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
//after "start"
struct Usuarios user/*[n]*/;
// #pragma pack(0)

// #pragma pack(1)
struct Juego_Estructura{
    int turno_usuario;
    //bool groupo_dinero[numjugadores];
    //int cartas_otros[];
    //"IN" action Raise call fold
    int dinero_alto;
    int cards[5];
    int dinero_total;
    int ganador_ronda;
    bool findeRonda;
    int fase;
};
//after "start"
struct Juego_Estructura juego_estructura;
// #pragma pack(0)



void call (struct Usuarios user, struct Juego_Estructura juego_estructura){


            int dinero_movim;
            dinero_movim = juego_estructura.dinero_alto - user.pone_ronda;
            user.pone_ronda += dinero_movim;
            user.moneyOnHand -= dinero_movim;
            juego_estructura.dinero_total += user.pone_ronda;
            user.check = true;

            //***********     IF VALUE IS HIGHER THAN WHAT I HAVE PERMITED, ALL IN?         ***********
}


void raise (struct Usuarios user, struct Juego_Estructura juego_estructura, int valor_raise){
            call(user, juego_estructura);
            user.pone_ronda += valor_raise;
            juego_estructura.dinero_alto = user.pone_ronda;
            user.moneyOnHand -= valor_raise;
            juego_estructura.dinero_total += user.pone_ronda;
            user.check = true;
}

void fold (){
    user.fold = true;
    char str[5];
    puts("what is the result");
    sprintf(str, "%d", user.fold);
    puts(str);
        
    puts("you chose fold");
}

void check (){
    user.check = true;
    puts("you chose check");
}

    void recibir_datos(int socket_servidor){
        recv(socket_servidor, &user, sizeof(struct Usuarios), 0);
        recv(socket_servidor, &juego_estructura, sizeof(struct Juego_Estructura), 0); 
    }

    void enviar_datos(int socket_servidor){
        write(socket_servidor, &user, sizeof(struct Usuarios));
        write(socket_servidor, &juego_estructura, sizeof(struct Juego_Estructura));
     }





int main(int argc , char *argv[])
{
    int socket_servidor, valor_raise;
    struct sockaddr_in servidor;
    char message[10];
     
    socket_servidor = socket(AF_INET , SOCK_STREAM , 0);
    puts("Socket creado");

    
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = inet_addr("127.0.0.1");
    servidor.sin_port = htons( 7777 );
    connect(socket_servidor , (struct sockaddr *)&servidor , sizeof(servidor));

    puts("Conectado\n");
     

while(1){
    recibir_datos(socket_servidor);
        char str[5];
        sprintf(str, "%d", user.id);
        puts(str);
        sprintf(str, "%d", user.moneyOnHand);
        puts(str);
        sprintf(str, "%d", user.cards[0]);
        puts(str);
        sprintf(str, "%d", user.cards[1]);
        puts(str);
        sprintf(str, "%d", user.smallBlind);
        puts(str);
        sprintf(str, "%d", user.bigBlind);
        puts(str);
        sprintf(str, "%d", user.check);
        puts(str);
        sprintf(str, "%d", user.raised);
        puts(str);
        sprintf(str, "%d", user.pone_ronda);
        puts(str);
        sprintf(str, "%d", user.fold);
        puts(str);

while(juego_estructura.findeRonda==false){
    recv(socket_servidor, &juego_estructura, sizeof(struct Juego_Estructura), 0);
    puts("the problem is here");
   
    


    puts("it is in here");
        char str[5];
        sprintf(str, "%d", user.id);
        puts(str);
        sprintf(str, "%d", user.moneyOnHand);
        puts(str);
        sprintf(str, "%d", user.cards[0]);
        puts(str);
        sprintf(str, "%d", user.cards[1]);
        puts(str);
        sprintf(str, "%d", user.smallBlind);
        puts(str);
        sprintf(str, "%d", user.bigBlind);
        puts(str);
        sprintf(str, "%d", user.check);
        puts(str);
        sprintf(str, "%d", user.raised);
        puts(str);
        sprintf(str, "%d", user.pone_ronda);
        puts(str);
        sprintf(str, "%d", user.fold);
        puts(str);



            puts("How much is fase");
        sprintf(str, "%d", juego_estructura.fase);
        puts(str);


        if (juego_estructura.fase==0)
    {
        /*nothing really, empty*/
    }
    if (juego_estructura.fase==1)
    {
        puts("cards on deck ron 2");
        for (int i = 0; i < 3; ++i)
        {
        sprintf(str, "%d", juego_estructura.cards[i]);
        puts(str);
        }

    }
        if (juego_estructura.fase==2)
    {
         for (int i = 0; i < 4; ++i)
        {
        sprintf(str, "%d", juego_estructura.cards[i]);
        puts(str);
        }

    }
            if (juego_estructura.fase==3)
    {
         for (int i = 0; i < 5; ++i)
        {
        sprintf(str, "%d", juego_estructura.cards[i]);
        puts(str);
        }

    }



        if(juego_estructura.ganador_ronda == user.id)
            puts("he ganado Ronda!!"); 
        else if(juego_estructura.ganador_ronda != user.id && juego_estructura.ganador_ronda >= 0){
            char str[5];
            sprintf(str, "%d", juego_estructura.ganador_ronda );
            puts("esta ronda la ha ganado :");
            puts(str);
        }
        if (user.fold == true)puts("espera proxima ronda");
        if (user.fold != true || juego_estructura.ganador_ronda == user.id){
        printf("'Call'  or  ('Raise' ENTER 'value')  or  'Fold'  or  'Check'\n");
        scanf("%s" , message);

        
          if (juego_estructura.turno_usuario == user.id)
    {  

        if (strcmp(message,"Call") == 0)
        {
            call(user, juego_estructura);
        }


        if(strcmp(message,"Raise") == 0)
         {
            raise(user, juego_estructura, valor_raise);

        }

        if (strcmp(message,"Fold") == 0)
        {
            puts("you chose fold");

            fold();
        }

        if (strcmp(message,"Check") == 0)
        {

         //   if (juego_estructura.dinero_alto == user.pone_ronda)
           // {
                   puts("you chose meeeee");
                   check();
            //}
            
        }
    }
        }
        puts("man..");
        enviar_datos(socket_servidor);
       //  recv(socket_servidor, &juego_estructura, sizeof(struct Juego_Estructura), 0);
 //   if(juego_estructura.fase == 2){}


}

if (juego_estructura.findeRonda == true){
//juego_estructura.ganador_ronda
//(see others cards and who won)
} 

///others money


    }
     
    close(socket_servidor);
    return 0;
}