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
    CHECK(read(sd, reponse, sizeof(reponse)), "Can't send");//reponse du write du client
    if (reponse=="joueur 1; rôle d'hébergeur transmis")
    {
        gerant();
    }
    if (reponse=="joueur 1")
    {
        int sock;
	    struct sockaddr_in svc;
	    char message[MAX_BUFF];

        sock=createSocketListenClt(svc,6011,inet_addr(INADDR_SVC));

        while(1)
        {
            scanf("%[^'\n']",message);
            getchar();
            cltPartie (sock);
        }
        close(sock);
    }

    if (reponse=="joueur 2")
    {
        int sock;
	    struct sockaddr_in svc;
	    char message[MAX_BUFF];

        sock=createSocketListenClt(svc,6012,inet_addr(INADDR_SVC));

        while(1)
        {
            scanf("%[^'\n']",message);
            getchar();
            cltPartie (sock);
        }
        close(sock);
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void gerant ()
 * 
 *  \brief      La fonction contient les instruction permettant
 *              de connecter les différents clients à l'hébergeur
 */
/* ------------------------------------------------------------------------ */
void gerant ()
{
        int se1,se2,se3,sd1,sd2,sd3;
        struct sockaddr_in svc1,svc2,svc3,clt;

        se1=createSocketListenSvc(svc1,6010,atoi(INADDR_SVC));
        se2=createSocketListenSvc(svc2,6011,atoi(INADDR_SVC));
        se3=createSocketListenSvc(svc3,6012,atoi(INADDR_SVC));

        pid_t pid1, pid2, pid3;
        socklen_t cltlen;
        pid1 = fork();
        if (pid1 == 0)
        {
            while (1) 
            { 
                // Attente d’un appel
                cltlen = sizeof(clt);
                CHECK(sd1=accept(se1, (struct sockaddr *)&clt, &cltlen) , "Can't connect");
                
                close(sd1);
            }
        }
    
        pid2 = fork();
        if (pid2 == 0)
        {
            while (1) 
            { 
                // Attente d’un appel
                cltlen = sizeof(clt);
                CHECK(sd2=accept(se2, (struct sockaddr *)&clt, &cltlen) , "Can't connect");
                
                close(sd2);
            }
        }

        pid3 = fork();
        if (pid3 == 0)
        {
            while (1) 
            { 
                // Attente d’un appel
                cltlen = sizeof(clt);
                CHECK(sd3=accept(se3, (struct sockaddr *)&clt, &cltlen) , "Can't connect");
                
                close(sd3);
            }
        }
        int sock;
	    struct sockaddr_in svc;
	    char message[MAX_BUFF];

        sock=createSocketListenClt(svc,6010,inet_addr(INADDR_SVC));

        while(1)
        {
            cltPartie (sock);
        }
        
        close(sock);
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void cltPartie ()
 * 
 *  \brief      La fonction contient les instructions qui serviront 
 *              à gérer la partie coté joureurs
 */
/* ------------------------------------------------------------------------ */
void cltPartie(int sock)
{
    mainPartie();
}