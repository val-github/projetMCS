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
 *  \fn         void dialogueClt(int, struct sockaddr_in)
 *
 *  \brief      prend en charge les commenications entre les différents clients et le serveur
 */
/* ------------------------------------------------------------------------ */

void dialogueClt(int sd, struct sockaddr_in clt)
{
    char requete[MAX_BUFF];
    do
    {
        read(sd, buffer, sizeof(buffer));
        sscanf(buffer, "%s:%s", requete, buffer);
        switch (atoi(requete))
        {
        case 0:
            printf("fin du dialogue");
            break;
        case 100:
            write(sd, OK, strlen(OK) + 1);
            printf("OK : message recu de la part de client 1 %s\n ", buffer);
            break;
        default:
            write(sd, NOK, strlen(NOK) + 1);
            printf("NOK : message recu %s\n", buffer);
            break;
        }
    } while (atoi(requete) != 0);
}
