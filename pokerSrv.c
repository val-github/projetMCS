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
int main()
{ 
    int sock,cltlen; 
    struct sockaddr_in svc; 
    struct sockaddr_in clt;

    // Création de la socket de réception des requêtes 
    CHECK(sock=socket(PF_INET, SOCK_DGRAM, 0), "Can't create"); 

    // Préparation de l’adressage du service 
    svc.sin_family = PF_INET; 
    svc.sin_addr.s_addr = INADDR_ANY;
    svc.sin_port = htons(PORT_SVC);
    memset(&svc.sin_zero, 0, 8);
     

    // Association de l’adressage préparé avec la socket créée 
    CHECK(bind(sock, (struct sockaddr *) &svc, sizeof svc) , "Can't bind");

    // Boucle permanente de service 
    while (1) 
    { 
        cltlen = sizeof(clt);
        //  Réception de la demande de partie 
        CHECK(recvfrom(sock, buffer, sizeof(buffer), 0,  (struct sockaddr *)&clt, &cltlen) , "Can't receive"); 
        //  Affichage du message reçu 
        printf("Message reçu [%s] de [%s]\n",  buffer, inet_ntoa(clt.sin_addr));
    }
    close(sock);
    return 0;
}
