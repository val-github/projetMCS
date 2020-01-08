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
    int se, sd;
    struct sockaddr_in svc, clt;
    socklen_t cltLen;

    se=createSocketListenSvc(svc,PORT_SVC,INADDR_ANY);

    // Boucle permanente de service 
    while (1) 
    { 
        // Attente d’un appel
        cltLen = sizeof(clt);
        CHECK(sd=accept(se, (struct sockaddr *)&clt, &cltLen) , "Can't connect");
        // Dialogue avec le client
        dialogueClt (sd , clt);
        close(sd);
    }
    close(se);
    return 0;
}
