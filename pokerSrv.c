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
    int se1,se2,se3,se4,sd1,sd2,sd3,sd4;
    struct sockaddr_in svc1,svc2,svc3,svc4, clt;
    socklen_t cltLen;

    se1=createSocketListenSvc(svc1,PORT_SVC,INADDR_ANY);
    se2=createSocketListenSvc(svc2,PORT_SVC,INADDR_ANY);
    se3=createSocketListenSvc(svc3,PORT_SVC,INADDR_ANY);
    se4=createSocketListenSvc(svc4,PORT_SVC,INADDR_ANY);

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
            // Dialogue avec le client
            dialogueClt (sd1 , clt);
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
            // Dialogue avec le client
            dialogueClt (sd2 , clt);
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
            // Dialogue avec le client
            dialogueClt (sd3 , clt);
            close(sd3);
        }
    }

    pid4 = fork();
    if (pid4 == 0)
    {
        while (1) 
        { 
            // Attente d’un appel
            cltLen = sizeof(clt);
            CHECK(sd4=accept(se4, (struct sockaddr *)&clt, &cltLen) , "Can't connect");
            // Dialogue avec le client
            dialogueClt (sd4 , clt);
            close(sd4);
        }
    }
    close(se1);
    close(se2);
    close(se3);
    close(se4);
    return 0;
}
