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
//#include "fonctions.c"
#include "pile.c"

/* ******************** VARIABLES GLOBALES ******************** */
Pile pile;
int nbJoueurs=3;

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int main()
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
int main()
{
    printf("Bonjour dans cette partie de poker\n");
    creationPaquetMelange();
    creationListeCartes();
    printf("\n\n\n");

    distribuer2Cartes();

    return 0;
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int random_7_14()
 *
 *  \brief      La fonction renvoie un chiffre aleatoire entre 7 et 14
 */
/* ------------------------------------------------------------------------ */
int random_7_14()
{
    // Permet de chager a quel moment commence l'aleatoire 
    // donc d'avoir un tableau aleatoire qui change
    static int first = 0;
    if (first == 0)
    {
        srand (time(NULL));
        first = 1;
    }
    return rand()%(15-7)+7;// donne un chiffre aleatoire entre 7 et 14
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
        carte=random_7_14();
        couleur=random_0_3();
        
        if(verifierCarte(paquetMelange, ligne, carte, couleur)==0) //carte n'existe pas
        {
            paquetMelange[ligne][0]=carte;
            paquetMelange[ligne][1]=couleur;
            ligne++;
        }
    }
    
    /*for(int i=0;i<32;i++)
    {
        printf("ligne %d : [%d,%d]\n",i,paquetMelange[i][0],paquetMelange[i][1]);
    }*/
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void distribuer2Cartes()
 *
 *  \brief      La fonction enleve les deux premieres carte de la pile et les donne
 *              au premier joueur puis fais la meme chose pour les autres joueurs.
 *              Les cartes distribuées sont enregistrée par le serveur dans un tableau distribution.
 *              En premiere colonne le numero de la carte, en deuxieme colonne sa couleur et en troisime 
 *              colonne le numero du jours a qui elle a etait donnée.
 */
/* ------------------------------------------------------------------------ */
void distribuer2Cartes()
{
    int tab[2];
    int ligne=0;
    //distribution[32][3]

    for(int j=0;j<nbJoueurs;j++)
    {
        //distribuer au joueur 2 cartes
        for (int i=0; i<2; i++)
        {
            pile=depiler(pile,tab);
            if(tab[0] == -1)
            {
                printf("Pile vide");
            }
        
            printf("%d, %d\n",tab[0],tab[1]);
            distribution[ligne][0] = tab[0];
            distribution[ligne][1] = tab[1];
            distribution[ligne][2] = j+1; //numero du jour qui a les cartes
            ligne++;
        }
    }

    for(int i=0;i<32;i++)
    {
        printf(" Joueur %d : ligne %d : [%d,%d]\n",distribution[i][2],i,distribution[i][0],distribution[i][1]);
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int verifierCarte(int paquetMelange[32][2],int , int , int )
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