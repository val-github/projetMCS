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
 *  \fn         int createSocketListen(struct sockaddr_in,int, char *)
 *
 *  \brief      La fonction crée l'ouverture de lecoute de la socket
 */
/* ------------------------------------------------------------------------ */
int createSocketListen(struct sockaddr_in svc,int port, int adresse)
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
 *  \fn         void dialogueClt(int, struct sockaddr_in)
 *
 *  \brief      La fonction prend en charge les communications entre les 
 *              différents clients et le serveur
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