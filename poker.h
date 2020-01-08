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
#define MSG "100 : demande partie prise en compte"
#define BYE "000 : fin de partie"
#define ERR "200 : Requête ou réponse non reconnue !"
#define OK "OK"
#define NOK "Not OK"
#define MAX_BUFF 1024

/* ******************** TYPEDEF ******************** */
/*typedef struct morceauPile
{
    int valeur[2];
    struct morceauPile *next;
}morceauPile, *Pile;*/

/* ******************** VARIABLES GLOBALES ******************** */
char buffer[MAX_BUFF];
//Pile pile;

/* ******************* PROTOTYPES ******************** */
int createSocketListenClt(struct sockaddr_in ,int , int);
int createSocketListenSvc(struct sockaddr_in ,int , int);
void dialogueClt (int , struct sockaddr_in);
void dialogueSrv (int , struct sockaddr_in , char *);

/* ******************* PROTOTYPES ******************** */
/*Pile pileVide();
int pile_is_empty(Pile p);
Pile empiler(Pile p, int chiffre, int couleur);
Pile depiler(Pile p);
void sommet(Pile p, int sommet[2], int affichage);
int taille(Pile p);
Pile viderPile(Pile p);
void afficher(Pile p);*/

/* ******************* PROTOTYPES ******************** */
int random_7_14();
int random_0_3();
void creationPaquetMelange();
int verifierCarte(int paquetMelange[32][2], int, int , int );