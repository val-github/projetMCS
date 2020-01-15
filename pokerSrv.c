/**
 *  \file       poker.h
 * 
 *  \brief      Ce programme inclus les #define et les #include ainsi que 
 *              les prototypes des fonctions et les variables globales
 *
 *  \author     Gwendoline Quettier & Valentin Blet
 *
 *  \date       26 Janvier 2020
 *
 *  \version    1.0
*/
#include "poker.h"
#include "fonctions.c"

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main()
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main()
{ 
    /*printf("nombre de joueurs?:");
    int nj = getchar();

    for (int i=0; i<nj; i++)
    {
        int se,sd,port;
        struct sockaddr_in svc,clt;
        socklen_t cltLen;
        port=6000+i;
        se=createSocketListenSvc(svc,port,INADDR_ANY);

        // Boucle permanente de service 

        pid_t pid;
        pid = fork();
        if (pid == 0)
        {
            while (1) 
            { 
                // Attente d’un appel
                cltLen = sizeof(clt);
                CHECK(sd=accept(se, (struct sockaddr *)&clt, &cltLen) , "Can't connect");
                // Dialogue avec le client
                dialogueClt (sd , clt);
                close(sd);
                
            }
        }
        waitpid(pid,NULL,0);
        close(se);
    }*/


    int se1,se2,se3,se4,sd1,sd2,sd3,sd4;
    struct sockaddr_in svc1,svc2,svc3,svc4, clt;
    socklen_t cltLen;

    se1=createSocketListenSvc(svc1,6000,INADDR_ANY);
    se2=createSocketListenSvc(svc2,6001,INADDR_ANY);
    se3=createSocketListenSvc(svc3,6002,INADDR_ANY);

    // Boucle permanente de service 

    pid_t pid1, pid2, pid3, pid4;
    pid1 = fork();
    if (pid1 == 0)
    {
        while (1) 
        { 
            // Attente d’un appel
            cltLen = sizeof(clt);
            CHECK(sd1=accept(se1, (struct sockaddr *)&clt, &cltLen) , "Can't connect");
            // attribution du role d'hébergeur de la partie
            // Envoi du message à l'hébergeur
            char rq;
            rq="joueur 1; rôle d'hébergeur transmis";
            CHECK(write(sd1, &rq, sizeof(rq)+1), "Can't send");
            close(sd1);
        }
    }
    
    pid2 = fork();
    if (pid2 == 0)
    {
        while (1) 
        { 
            // Attente d’un appel
            cltLen = sizeof(clt);
            CHECK(sd2=accept(se2, (struct sockaddr *)&clt, &cltLen) , "Can't connect");
            // envois du message au client pour qu'il se connecte a l'hébergeur
            char rq;
            rq="joueur 2";
            CHECK(write(sd2, &rq, sizeof(rq)+1), "Can't send");
            close(sd2);
        }
    }

    pid3 = fork();
    if (pid3 == 0)
    {
        while (1) 
        { 
            // Attente d’un appel
            cltLen = sizeof(clt);
            CHECK(sd3=accept(se3, (struct sockaddr *)&clt, &cltLen) , "Can't connect");
            // envois du message au client pour qu'il se connecte a l'hébergeur
            char rq;
            rq="joueur 3";
            CHECK(write(sd3, &rq, sizeof(rq)+1), "Can't send");
            close(sd3);
        }
    }

    
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);
    waitpid(pid3,NULL,0);
    close(se1);
    close(se2);
    close(se3);
    return 0;
}
