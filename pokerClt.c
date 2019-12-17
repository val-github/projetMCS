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

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main(int ,char)
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main(int argc, char **argv)
{
    int sock;
	struct sockaddr_in svc;
	char message[MAX_BUFF];

    if (argc <= 2) 
	{
		printf("ERREUR: Aucun argument passé en ligne de commande !\n");
		printf("USAGE: %s <@IP> <PORT>\n", argv[0]);
		return 1;
	}

	sock=createSocketListen(svc,atoi(argv[2]),inet_addr(argv[1]));

    while(1)
    {
        scanf("%[^'\n']",message);
        getchar();
        dialogueSrv (sock, svc, message);
    }
    close(sock);
    return 0;
}
