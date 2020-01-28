/**
 *  \file       pokerClt.c
 * 
 *  \brief      Ce programme inclus les #define et les #include ainsi que 
 *              les portotypes des fonctions et les variables globales
 *
 *  \author     Gwendoline Quettier & Valentin Blet
 *
 *  \date       26 Janvier 2020
 *
 *  \version    1.0
*/
#include "poker.h"
#include "fonctions.c"
#include "poker.c"

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main(int ,char)
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main(int argc,char **argv)
{
    printf("client lancé");
    int sock;
	struct sockaddr_in svc;
    sock=createSocketListenClt(svc,atoi(argv[2]),inet_addr(argv[1]));
    dialogueSrv(sock);
    close(sock);
}
