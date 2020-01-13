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

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main(int ,char)
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main(char **argv)
{
    int sock;
	struct sockaddr_in svc;
	char message[MAX_BUFF];


	sock=createSocketListenClt(svc,atoi(argv[2]),inet_addr(127.0.0.1));

    while(1)
    {
        scanf("%[^'\n']",message);
        getchar();
        dialogueSrv (sock, svc, message);
    }
    close(sock);
    return 0;
}
