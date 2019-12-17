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
void dialogueClt(int sd, struct sockaddr_in clt)
{
    char requete[MAX_BUFF];
    do
    {
        read(sd, buffer, sizeof(buffer));
        sscanf(buffer, "%s:%s", requete, buffer);
        switch (atoi(requete))
        {
            case 0:
                printf("fin du dialogue");
                break;
            case 100:
                write(sd, OK, strlen(OK) + 1);
                printf("OK : message recu de la part de client 1 %s\n ", buffer);
                break;
            default:
                write(sd, NOK, strlen(NOK) + 1);
                printf("NOK : message recu %s\n", buffer);
                break;
        }
    } while (atoi(requete) != 0);
}