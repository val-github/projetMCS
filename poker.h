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
#include <time.h>
#include <stdint.h>

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
#define J1 "1"
#define J2 "2"
#define J3 "3"
#define P1 "10"
#define P2 "20"
#define P3 "30"
#define ACK "ack" 
#define FIN "fin de partie"
#define DEM "dem"
 
/* ******************** VARIABLES GLOBALES ******************** */
char buffer[MAX_BUFF];

/* ******************* PROTOTYPES ******************** */
int connection(int,int,struct sockaddr_in,int,struct sockaddr_in);
int createSocketListenClt(struct sockaddr_in ,int , int);
int createSocketListenSvc(struct sockaddr_in ,int , int);
void dialogueClt (int , struct sockaddr_in,int , struct sockaddr_in);
void dialogueSrv (int );
int gerant();
void cltPartie();

/* ******************* PROTOTYPES ******************** */
void mainPartie(int,int);
int random_6_13();
int random_0_3();
void creationPaquetMelange();
int verifierCarte(int tab[32][2], int, int , int);
void creationListeCartes();
void distribuer2Cartes();
int emplacementCarte(int tab[6][3],int *, int, int, int);
void changerCartes(int,int[6][3],int[5][2]);
int couleurCartes(char *);
char *cartesCouleur(int);
void affichageDistribution();
void affichageTapis();
void distribuerTapis(int);
void affichageFenetre(int,int[6][3],int[5][2]);
void creationNbPoints(int joueur);
void demanderMainFinale(int);
int existeTapis(int, int, int, int, int);
int couleur(int);
int paire(int, int);
int brelan(int);
int carre(int);
int suite(int);
