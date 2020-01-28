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
        cltPartie (sock,svc);
        close(sock);
    }

    if (test3==0)
    {
        printf("role: joueur 3\n");
        int sock;
	    struct sockaddr_in svc;

        sock=createSocketListenClt(svc,6002,inet_addr(INADDR_SVC));
        cltPartie (sock,svc);
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
void cltPartie(int sd, struct sockaddr_in svc)
{
    char test[]=FIN;
    printf("Partie lancée\n");
    char reponse[MAX_BUFF];
    do
    {
        read(sd, reponse, sizeof(reponse));
        printf("%s",reponse);
        write(sd,ACK,sizeof(ACK));

        if (strcmp(reponse,DEM)==0)
        {
            char ack[MAX_BUFF];
            int* num;
            printf("combien de cartes veux-tu changer?");
            do
            {
                scanf("%d",num);
                CHECK(write(sd,num,MAX_BUFF),"can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                CHECK(write(sd,ACK,sizeof(ACK)),"can't send");
            } while (strcmp(reponse,DEM)!=0);

            printf("Quelle carte veux tu changer ?\n");
            do
            {
                printf("Veuillez taper le numero de votre carte (entre 6 et 13) : ");
                scanf("%d",num);
                CHECK(write(sd,num,strlen(DEM)+1),"can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                read(sd, reponse, sizeof(reponse));
                write(sd,ACK,sizeof(ACK));
            } while (strcmp(reponse,DEM)!=0);
            
            do
            {
                printf("Veuillez taper la couleur de votre carte (coeur, carreau, trefle et pique) : ");
                char couleur[10];
                scanf("%s",couleur);
                CHECK(write(sd,couleur,strlen(couleur)),"can't send");
                read(sd, reponse, sizeof(reponse));
                write(sd,ACK,sizeof(ACK));
            } while (strcmp(reponse,DEM)!=0);
            
            (sd, reponse, sizeof(reponse));
            printf("%s",reponse);
            printf("fin échange de cartes");
        }


    } while (strcmp(reponse,test)!=0);
}


