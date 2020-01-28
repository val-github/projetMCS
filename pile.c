/**
 *  \file       pile.c
 * 
 *  \brief      Ce programme inclus les fonctions d'utilistation d'une pile
 *
 *  \date       26 Janvier 2020
 *
 *  \version    1.0
*/
#include "poker.h"

/* ******************** TYPEDEF ******************** */
typedef struct morceauPile
{
    int valeur[2];
    struct morceauPile *next;
}   morceauPile, *Pile;


/**
* Retourne une Pile vide
* @return Une Pile vide
*/
Pile pileVide()
{
    return NULL;
}

/**
* Vérifie si une Pile est vide
* @param p La pile à tester
* @return 1 si la Pile est vide, 0 sinon
*/
int pile_is_empty(Pile p)
{
	if(p == NULL)
	{
        return 1; //vrai
    }
	return 0; //faux
}

/**
* Empile un element dans la Pile
* @param p La Pile
* @param chiffre L'entier à ajouter (numero de la carte)
* @param couleur L'entier à ajouter (couleur de la carte)
* @return La nouvelle Pile
*/
Pile empiler(Pile p, int chiffre, int couleur)
{
	morceauPile *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->valeur[0] = chiffre;
    element->valeur[1] = couleur;
	element->next = p;

	return element;
}

/**
* Dépile un element de la Pile
* @param p La Pile
* @param La pile sans le premier élément
*/
Pile depiler(Pile p, int tab[2])
{
	morceauPile *element;

	if(pile_is_empty(p))
    {
        tab[0]=-1;
        tab[1]=-1;
        return pileVide();
    }
		
    tab[0]=p->valeur[0];
    tab[1]=	p->valeur[1];
	element = p->next;
	free(p);

	return element;
}

/**
* Retourne l'element au sommet de la Pile
* @param p La Pile
* @param sommet[2] Recupere la valeur du sommet
* @param affichage Si egal 0 alors on affiche le sommet
*/
void sommet(Pile p, int sommet[2], int affichage)
{
	if(pile_is_empty(p))
	{
		printf("Aucun sommet, la Pile est vide.\n");
		exit(EXIT_FAILURE);
	}

    sommet[0]=p->valeur[0];
    sommet[1]=p->valeur[1];
    
    if(affichage == 0)
    {
        if(sommet[1] == 0)
        {
            printf("[%d,coeur]\n", sommet[0]);
        }
        else if(sommet[1] == 1)
        {
            printf("[%d,carreau]\n", sommet[0]);
        }
        else if(sommet[1] == 2)
        {
            printf("[%d,trefle]\n", sommet[0]);
        }
        else if(sommet[1] == 3)
        {
            printf("[%d,pique]\n", sommet[0]);
        }
    }
}

/**
* Retourne la taille de la Pile
* @param p La Pile
* @return La taille de la Pile
*/
int taille(Pile p)
{
	int length = 0;

	while(!pile_is_empty(p))
	{
		length++;
		p = p->next;
	}

	return length;
}

/**
* Vide la Pile de ses éléments
* @param p La Pile à nettoyer
* @return Une Pile vide
*/
Pile viderPile(Pile p)
{
	while(!pile_is_empty(p))
    {
		p = depiler(p,NULL); 
    }

	return pileVide();
}

/**
* Affiche une Pile
* @param p La Pile
*/
void afficher(Pile p)
{
	if(pile_is_empty(p))
	{
		printf("Rien a afficher, la Pile est vide.\n");
		return;
	}

	while(!pile_is_empty(p))
	{
        if(p->valeur[1] == 0)
        {
            printf("[%d,coeur]\n", p->valeur[0]);
            p = p->next;
        }
        else if(p->valeur[1] == 1)
        {
            printf("[%d,carreau]\n", p->valeur[0]);
            p = p->next;
        }
        else if(p->valeur[1] == 2)
        {
            printf("[%d,trefle]\n", p->valeur[0]);
            p = p->next;
        }
        else if(p->valeur[1] == 3)
        {
            printf("[%d,pique]\n", p->valeur[0]);
            p = p->next;
        }
	}
}