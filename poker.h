/* ------------------------------------------------------------------------ */
/**
 *  \file       poker.h
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
/* ------------------------------------------------------------------------ */

/* ************************* INCLUDE ************************* */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* ************************* DEFINE ************************* */
#define CHECK(sts,msg)              \
        if ((sts) == -1)            \
        {                           \
            perror(msg);exit(-1);   \
        }
#define PORT_SVC 6000
#define INADDR_SVC "127.0.0.1"
#define MSG "100 : [Gwen] Moi je fais des bulles et toi ?"
#define BYE "000 : [Gwen] Au revoir et à bientôt ..."
#define ERR "200 : [Gwen] Requête ou réponse non reconnue !"
#define OK "OK"
#define NOK "Not OK"
#define MAX_BUFF 1024

/* ******************** VARIABLES GLOBALES ******************** */
char buffer[MAX_BUFF];

/* ******************** PROTOTYPES ******************** */