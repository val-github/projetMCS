/**
 *  \file       fonctions.c
 * 
 *  \brief      Ce programme inclus les fonctions utilisées par 
 *              les client et les serveurs
 *
 *  \author     Gwendoline Quettier & Valentin Blet
 *
 *  \date       26 Janvier 2020
 *
 *  \version    1.0
*/
#include "poker.h"


/* ------------------------------------------------------------------------ */
/**
 *  \fn         int createSocketListenClt(struct sockaddr_in, int, int)
 *
 *  \brief      La fonction crée l'ouverture de l'écoute de la socket du client
 */
/* ------------------------------------------------------------------------ */
int createSocketListenClt(struct sockaddr_in svc,int port, int adresse)
{
    int sock=0;

    // Création de la socket d’appel et de dialogue
    CHECK(sock=socket(PF_INET, SOCK_STREAM, 0), "Can't create");
    
    // Préparation de l’adressage du service à contacter
    svc.sin_family = PF_INET;
    svc.sin_port = htons (port);
    svc.sin_addr.s_addr = adresse;
    memset(&svc.sin_zero, 0, 8);
    
    // Demande d’une connexion au service
    CHECK(connect(sock, (struct sockaddr *)&svc, sizeof svc) , "Can't connect");
    
    return sock;
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int createSocketListenSvc(struct sockaddr_in, int, int)
 *
 *  \brief      La fonction crée l'ouverture de l'écoute de la socket du serveur
 */
/* ------------------------------------------------------------------------ */
int createSocketListenSvc(struct sockaddr_in svc,int port, int adresse)
{
    int se=0;

    // Création de la socket de réception d’écoute des appels
    CHECK(se=socket(PF_INET, SOCK_STREAM, 0), "Can't create");

    // Préparation de l’adressage du service (d’appel)
    svc.sin_family = PF_INET;
    svc.sin_port = htons (port);
    svc.sin_addr.s_addr = adresse;
    memset(&svc.sin_zero, 0, 8);

    // Association de l’adressage préparé avec la socket d’écoute
    CHECK(bind(se, (struct sockaddr *) &svc, sizeof svc) , "Can't bind");
    
    // Mise en écoute de la socket
    CHECK(listen(se, 5) , "Can't calibrate");

    return se;
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void dialogueClt(int, struct sockaddr_in)
 *
 *  \brief      La fonction prend en charge les communications entre les 
 *              différents clients et le serveur; doit donner au premier client
 *              l'instrcuction d'utiliser la fonction gerant et doit donner aux
 *              autres clients l'adresse du premier client
 */
/* ------------------------------------------------------------------------ */
void dialogueClt (int sd, struct sockaddr_in clt) 
{
    char message[MAX_BUFF];
    while(1)
    {
        read(sd, buffer,sizeof(buffer));//reponse du write du serveur
        printf(" recu => %s\n", buffer);
        
        scanf("%[^'\n']",message);
        getchar();
        write(sd, message,strlen(message)+1);//envoie au read du client
        
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void dialogueSrv (int, struct sockaddr_in, char *)
 *
 *  \brief      La fonction prend en charge les communications entre les 
 *              différents clients et le serveur
 */
/* ------------------------------------------------------------------------ */
void dialogueSrv (int sd, struct sockaddr_in srv, char *message)
{
    char reponse[MAX_BUFF];
    // Envoi du message au serveur
    CHECK(write(sd, message, sizeof(message)+1), "Can't send");//envoie au read du serveur
    CHECK(read(sd, reponse, sizeof(reponse)), "Can't send");//reponse du write du client
    printf(" recu => %s\n",reponse);
}
/* ------------------------------------------------------------------------ */
/**
 *  \fn         void gerant (int clt1,int clt2,int clt3,int clt4)
 * 
 *  \brief      La fonction contient les instruction permettant
 *              à un des joueurs de gérer une partie 
 */
/* ------------------------------------------------------------------------ */
void gerant (int clt1,int clt2,int clt3,int clt4)
{

}