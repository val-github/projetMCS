/**
 *  \file       poker.c
 * 
 *  \brief      Ce programme inclus les fonctions utilisées par 
 *              l'application de poker
 *
 *  \author     Gwendoline Quettier & Valentin Blet
 *
 *  \date       26 Janvier 2020
 *
 *  \version    1.0
*/
#include "poker.h"
#include "pile.c"

/* ******************** VARIABLES GLOBALES ******************** */
int nombreJoueur=3;
int paquetMelange[32][2];
Pile pile;
int tailleDist=0,tailleTapis=0;
int distribution[32][3];
int tapis[5][2];
int nbPoints[100][3];


/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main()
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main()
{
    /* IL RESTE A FINIR 
      - faire le tableau de victoire
      - dire qui a gagner     */

    printf("Bonjour dans cette partie de poker\n");
    creationPaquetMelange();
    creationListeCartes();

    return 0;
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int random_6_13()
 *
 *  \brief      La fonction renvoie un chiffre aleatoire entre 6 et 13
 */
/* ------------------------------------------------------------------------ */
int random_6_13()
{
    // Permet de chager a quel moment commence l'aleatoire 
    // donc d'avoir un tableau aleatoire qui change
    static int first = 0;
    if (first == 0)
    {
        srand (time(NULL));
        first = 1;
    }
    return rand()%(14-6)+6;// donne un chiffre aleatoire entre 6 et 13
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int random_0_3()
 *
 *  \brief      La fonction renvoie un chiffre aléatoire entre 0 et 3
 */
/* ------------------------------------------------------------------------ */
int random_0_3()
{
    return rand()%4;// donne un chiffre aleatoire entre 0 et 3
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void creationListeCartes()
 *
 *  \brief      La fonction crée unepile a partir du tableau paquetMelange. 
 *              L'élément de la pile est un tableau. 
 *              La première colonne est la carte et la deuxième est la couleur
 */
/* ------------------------------------------------------------------------ */
void creationListeCartes()
{
    //on vide la pile si elle contient des elements 
    if(pile_is_empty(pile) == 0) //faux
    {
        pile=viderPile(pile);
    }

    for(int i=0;i<32;i++)
    {
        pile=empiler(pile,paquetMelange[i][0],paquetMelange[i][1]);
    }

    afficher(pile);
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void creationPaquetMelange()
 *
 *  \brief      La fonction crée un tableau de carte rangée aleatoirement. 
 *              La premiere colonne est la carte et la deuxieme est la couleur
 */
/* ------------------------------------------------------------------------ */
void creationPaquetMelange()
{
    int ligne=0,carte,couleur;

    while(ligne!=32)
    {
        carte=random_6_13();
        couleur=random_0_3();

        if(verifierCarte(paquetMelange, ligne, carte, couleur)==0) //carte n'existe pas
        {
            paquetMelange[ligne][0]=carte;
            paquetMelange[ligne][1]=couleur;
            ligne++;
        }
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void distribuer2Cartes()
 *
 *  \brief      La fonction enleve les deux premieres carte de la pile et les donne
 *              au premier joueur puis fais la meme chose pour les autres joueurs.
 *              Les cartes distribuées sont enregistrée par le serveur dans un tableau distribution.
 *              En premiere colonne le numero de la carte, en deuxieme colonne sa couleur et en troisieme 
 *              colonne le numéro du joueur à qui elle a etait donnée.
 */
/* ------------------------------------------------------------------------ */
void distribuer2Cartes()
{
    int tab[2];

    for(int j=0;j<nombreJoueur;j++)
    {
        //distribuer au joueur 2 cartes
        for (int i=0; i<2; i++)
        {
            pile=depiler(pile,tab);
            if(tab[0] == -1)
            {
                printf("Pile vide");
            }
            else
            {
                //printf("%d, %d\n",tab[0],tab[1]);
                distribution[tailleDist][0] = tab[0];
                distribution[tailleDist][1] = tab[1];
                distribution[tailleDist][2] = j+1; //numero du joueur qui a les cartes
                tailleDist++;
            }
        }
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int verifierCarte(int tab[32][2],int , int , int )
 *
 *  \brief      La fonction vérifie si la combinaison carte couleur existe deja dans le  tableau.
 *              Elle renvoie 1 si la carte exite et 0 si elle n'existe pas
 */
/* ------------------------------------------------------------------------ */
int verifierCarte(int tab[32][2],int ligne, int carte, int couleur)
{
    for (int i=0;i<ligne;i++)
    {
        if(tab[i][1] == couleur)
        {
            if(tab[i][0] == carte)
            {
                return 1; //la carte existe
            }
        }
    }
    return 0; //la carte n'existe pas
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void affichageDistribution()
 *
 *  \brief      La fonction affiche le tableau distribution[32][3]
 */
/* ------------------------------------------------------------------------ */
void affichageDistribution()
{
    for(int i=0;i<32;i++)
    {
        printf(" Joueur %d : ligne %d : [%d,%s]\n",distribution[i][2],i,distribution[i][0],cartesCouleur(distribution[i][1]));
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         char *cartesCouleur(int)
 *
 *  \brief      La fonction transforme un int en char (0 -> coeur)
 */
/* ------------------------------------------------------------------------ */
char *cartesCouleur(int couleur)
{
    switch(couleur)
    {
        case 0 :
            return "coeur";
        break;
        
        case 1 :
            return "carreau";
        break;
    
        case 2 :
            return "trefle";
        break;

        case 3 :
            return "pique";
        break;
    }
    return "ko";
}