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
    int se;

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
 *  \fn         void dialogueSrv (int, struct sockaddr_in, char *)
 *
 *  \brief      La fonction prend en charge les communications entre les 
 *              différents clients, le serveur et l'hébergeur
 */
/* ------------------------------------------------------------------------ */
void dialogueSrv (int sd)
{
    char reponse[MAX_BUFF];
    read(sd, reponse, sizeof(reponse));//reponse du write du client
    printf(" recu => %s\n",reponse);
    //int rep=atoi(reponse);
    int test1=strcmp(reponse,J1);
    int test2=strcmp(reponse,J2);
    int test3=strcmp(reponse,J3);
    close(sd);
    if (test1==0)
    {
        printf("role: joueur 1 et hébergeur\n");
        gerant();
    }
    if (test2==0)
    {
        printf("role: joueur 2\n");
        int sock;
	    struct sockaddr_in svc;
        
        sock=createSocketListenClt(svc,6002,inet_addr(INADDR_SVC));
        cltPartie (sock,svc,2);
        close(sock);
    }

    if (test3==0)
    {
        printf("role: joueur 3\n");
        int sock;
	    struct sockaddr_in svc;

        sock=createSocketListenClt(svc,6002,inet_addr(INADDR_SVC));
        cltPartie (sock,svc,3);
        close(sock);
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int gerant ()
 * 
 *  \brief      La fonction contient les instruction permettant
 *              à l'hébergeur de se connecter aux clients et de
 *              lancer la partie
 */
/* ------------------------------------------------------------------------ */
int gerant ()
{
        printf("fonction gerant lancée\n");

        int se,sd1,sd2;
        struct sockaddr_in svc,clt1,clt2;
        socklen_t clt1Len = sizeof(clt1);
        socklen_t clt2Len = sizeof(clt2);

        se=createSocketListenSvc(svc,6002,inet_addr(INADDR_SVC));
        printf("attente de joureur 2 et joueur 3\n");
        
        CHECK(listen(se, 5) , "Can't calibrate");
        CHECK(sd1=accept(se, (struct sockaddr *) &clt1, &clt1Len) , "Can't connect");
        printf("connection avec joueur 2 éffectuée\n");
        CHECK(sd2=accept(se, (struct sockaddr *) &clt2, &clt2Len) , "Can't connect");
        printf("connection avec joueur 3 éffectuée\n");

        mainPartie (sd1,sd2);

        close(se);
        return 0;
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void cltPartie ()
 * 
 *  \brief      La fonction contient les instructions qui serviront 
 *              à gérer la partie coté joureurs
 */
/* ------------------------------------------------------------------------ */
void cltPartie(int sd, struct sockaddr_in svc,int joueur)
{
    char test[]=FIN;
    printf("Partie lancée\n");
    char reponse[MAX_BUFF];
    do
    {
        read(sd, reponse, sizeof(reponse));
        write(sd,ACK,sizeof(ACK));
        int test1=strcmp(reponse,P1);
        int test2=strcmp(reponse,P2);
        int test3=strcmp(reponse,P3);
        close(sd);
        if (test1==0)
        {
            char rep[MAX_BUFF];

            read(sd,rep,strlen(rep));
            int cartes[6][3];
            sprintf(cartes,"%d",rep);
            CHECK(write(sd, ACK, strlen(ACK)+1), "Can't write");

            read(sd,rep,sltrlen(rep));
            int commun[5][2];
            sprintf(commun,"%d",rep);
            CHECK(write(sd, ACK, strlen(ACK)+1), "Can't write");

            affichageFenetre(joueur,cartes,commun);
            changerCartes(joueur,cartes,commun);
            affichageFenetre(joueur,cartes,commun);
            
        }
        if (test2==0)
        {
            char rep[MAX_BUFF];

            read(sd,rep,sltrlen(rep));
            int cartes[6][3];
            sprintf(cartes,"%d",rep);
            CHECK(write(sd, ACK, strlen(ACK)+1), "Can't write");

            read(sd,rep,sltrlen(rep));
            int commun[5][2];
            sprintf(commun,"%d",rep);
            CHECK(write(sd, ACK, strlen(ACK)+1), "Can't write");

            changerCartes(joueur,cartes,commun);
            affichageFenetre(joueur,cartes,commun);
        }

        if (test3==0)
        {
            for(int i=1;i<4;i++)
            {
                creationNbPoints(i);
            }
        }
        strcpy(reponse,"0");
    } while (strcmp(reponse,test)!=0);
}


