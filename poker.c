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
#include "fonctions.c"
//#include "pile.c"

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
    creationPaquetMelangee();
    
    return 0;
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
    int paquetMelange[32][2];
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
    for(int i=0;i<32;i++)
    {
        printf("ligne %d : [%d,%d]\n",i,paquetMelange[i][0],paquetMelange[i][1]);
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
int verifierCarte(int paquetMelange[32][2],int ligne, int carte, int couleur)
{
    for (int i=0;i<ligne;i++)
    {
        if(paquetMelange[i][1] == couleur)
        {
            if(paquetMelange[i][0] == carte)
            {
                return 1; //la carte existe
            }
        }
    }
    return 0; //la carte n'existe pas
}