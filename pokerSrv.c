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

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main()
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
#define CHECK(sts,msg) if ((sts) == -1) {perror(msg);exit(-1);}
int main()
{ 
    int se, sd;
    struct sockaddr_in svc, clt;
    socklen_t cltLen;

    se=createSocketListenSvc(svc,PORT_SVC,INADDR_ANY);

    // Boucle permanente de service 
    while (1) 
    { 

    }
    close(se);
    return 0;
}
