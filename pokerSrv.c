/**
 *  \file       pokerSrv.c
 * 
 *  \brief      Ce programme est le programme executé par le serveur
 *
 *  \author     Gwendoline Quettier & Valentin Blet
 *
 *  \date       26 Janvier 2020
 *
 *  \version    1.0
*/
#include "poker.h"
#include "fonctions.c"
#include "poker.c"

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main()
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main()
{ 
    int se,sd1,sd2,sd3;
    struct sockaddr_in svc, clt1, clt2, clt3;
    pid_t pid;

    se=createSocketListenSvc(svc,6000,INADDR_ANY);

    // Boucle permanente de service 

    while (1) 
    {
        //  Attente d’un appel
        socklen_t clt1Len = sizeof(clt1);
        socklen_t clt2Len = sizeof(clt2);
        socklen_t clt3Len = sizeof(clt3);
        printf("En attente du joueur 1\n");
        CHECK(sd1=accept(se, (struct sockaddr *) &clt1, &clt1Len) , "Can't connect");

        printf("En attente du joueur 2\n");
        CHECK(sd2=accept(se, (struct sockaddr *) &clt2, &clt2Len) , "Can't connect");
        
        printf("En attente du joueur 3\n");
        CHECK(sd3=accept(se, (struct sockaddr *) &clt3, &clt3Len) , "Can't connect");
        
        connection(sd1, sd2, clt2, sd3, clt3);
        
        close(sd1);
        close(sd2);
        close(sd3);
    }
    shutdown(se,3);
    return 0;
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int connection()
 *
 *  \brief      Fonction qui indique leurs rôles aux clients et leur envoi les
 *              informations pour la connection
 */
/* ------------------------------------------------------------------------ */
int connection(int sd1, int sd2, struct sockaddr_in clt2, int sd3, struct sockaddr_in clt3)
{
    char reponse[MAX_BUFF];
        
    printf("Debut des communications\n");

    CHECK(write(sd1, J1, strlen(J1)+1), "Can't write"); //notifie au joueur 1 qu'il est l'hébergeur
    CHECK(write(sd2, J2, strlen(J2)+1), "Can't write"); //notifie au joueur 2 qu'il est joueur 2
    CHECK(write(sd3, J3, strlen(J3)+1), "Can't write"); //notifie au joueur 3 qu'il est joueur 3

    /*read(sd2,reponse,sizeof(reponse));
    while(atoi(reponse)!=1){ //attente d'ack (OK) du client
    read(sd2,reponse,sizeof(reponse));
    sleep(1);
    }

    char addr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clt2.sin_addr, addr, INET_ADDRSTRLEN);
    write(sd2,addr,sizeof(addr)+1); //envoie de l'addr du serv au client
    printf("envoie addr\n");

    read(sd2,reponse,sizeof(reponse));
    while(atoi(reponse)!=1){ //attente d'ack (OK) du client
    read(sd2,reponse,sizeof(reponse));
    sleep(1);
    }

    inet_ntop(AF_INET, &clt3.sin_addr, addr, INET_ADDRSTRLEN);
    write(sd3,addr,sizeof(addr)+1); //envoie de l'addr du serv au client
    printf("envoie addr\n");

    read(sd3,reponse,sizeof(reponse));
    while(atoi(reponse)!=1){ //attente d'ack (OK) du client
    read(sd3,reponse,sizeof(reponse));
    sleep(1);
    }*/

    printf("Redirection terminée. On peut acceuillir de nouveaux joueurs.\n");
}
