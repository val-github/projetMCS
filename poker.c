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
int tailleDist=0, tailleTapis=0, tailleMain=0;
int distribution[6][3];
int tapis[5][2];
int nbPoints[3];
int mainFinale[15][3];

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void mainPartie()
 *
 *  \brief      Fonction main du fichier
 */
/* ------------------------------------------------------------------------ */
void mainPartie(int clt1,int clt2)
{
    /* IL RESTE A FINIR
      - dire qui a gagner    */

    printf("Bonjour dans cette partie de poker\n");
    creationPaquetMelange();
    creationListeCartes();
    
    printf("1er tour\n");
    distribuer2Cartes();
    distribuerTapis(2);
    printf("\n\n\n");
    
    /*for(int i=1;i<nombreJoueur+1;i++)
    {
        changerCartes(i);
        printf("\n\n\n\n\n\n\n\n\n\n");
    }*/
    
    
    affichageFenetre(clt1,1);
    changerCartes(clt1,1);
    affichageFenetre(clt1,1);
    printf("\n\n\n\n\n\n\n\n\n\n");

    //test affichageFenetreClt
    affichageFenetre(clt1,2);
    changerCartes(clt1,2);
    affichageFenetre(clt1,2);
    
    printf("YES!!!");
    affichageFenetre(clt2,3);
    changerCartes(clt2,3);
    affichageFenetre(clt2,0);
    /*
    
    printf("2eme tour\n");
    CHECK(write(clt1, "2eme tour\n", strlen("2eme tour\n") + 1), "Can't send");
    CHECK(write(clt2, "2eme tour\n", strlen("2eme tour\n") + 1), "Can't send");
    distribuerTapis(3);
    
    //affichageFenetre(clt1,1);
    //demanderMainFinale(clt1);

    //affichageFenetre(clt1,2);
    //demanderMainFinale(i);

    //affichageFenetre(clt2,3);
    //demanderMainFinale(i);
    */
   

    /*tailleMain=15;
    int carte=0;

    for(int i=1;i<nombreJoueur+1;i++)
    {
        creationNbPoints(i);
    }

    for(int i=1;i<nombreJoueur+1;i++)
    {
        char reponse=nbPoints[i];
        char reponse1=i;

        char rep[MAX_BUFF];
        char rep1[MAX_BUFF];
        char ack[MAX_BUFF];

        sprintf(rep,"%d",reponse);
        sprintf(rep1,"%d",reponse1);

        

        CHECK(write(clt1, "joueur ", strlen("joueur ") + 1), "Can't send");
        read(clt1,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt1,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt1, rep1, strlen(rep1) + 1), "Can't send");
        read(clt1,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt1,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt1, ": ", strlen(": ") + 1), "Can't send");
        read(clt1,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt1,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt1, rep, strlen(rep) + 1), "Can't send");
        read(clt1,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt1,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt1, "\n", strlen("\n") + 1), "Can't send");
        read(clt1,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt1,ack,sizeof(ack));
                sleep(1);
        }

        CHECK(write(clt2, "joueur ", strlen("joueur ") + 1), "Can't send");
        read(clt2,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt2,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt2, rep1, strlen(rep1) + 1), "Can't send");
        read(clt2,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt2,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt2, ":\t", strlen("\n") + 1), "Can't send");
        read(clt2,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt2,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt2, rep, strlen(rep) + 1), "Can't send");
        read(clt2,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt2,ack,sizeof(ack));
                sleep(1);
        }
        CHECK(write(clt2, "\n", strlen("\n") + 1), "Can't send");
        read(clt2,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(clt2,ack,sizeof(ack));
                sleep(1);
        }

        printf("joueur %d : %d\n",i,nbPoints[i]);
    }
    
    CHECK(write(clt1, FIN, strlen(FIN) + 1), "Can't send");
    CHECK(write(clt2, FIN, strlen(FIN) + 1), "Can't send");
    
}


/* ------------------------------------------------------------------------ */
/**
 *  \fn         void affichageDistribution()
 *
 *  \brief      La fonction affiche le tableau distribution[6][3]
 */
/* ------------------------------------------------------------------------ */
void affichageDistribution() //affiche le tableau distribution
{
    for(int i=0;i<6;i++)
    {
        printf(" Joueur %d : ligne %d : [%d,%s]\n",distribution[i][2],i,distribution[i][0],cartesCouleur(distribution[i][1]));
    }
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void affichageFenetre(int)
 *
 *  \brief       La fonction creer l'affichage cote joueur
 * 
 *  \param       joueur  : Nombre representant le numéro du joueur
 */
/* ------------------------------------------------------------------------ */

void affichageFenetre(int sd,int nb) //Creer l'affichage cote joueur
{
    //printf("\tCartes communes\n");
    //printf("\nJoueur %d\n\n\n",joueur);
    char ack[MAX_BUFF];

    if (nb==1)
    {
        printf("Cartes commune\n");
        for(int i=0;i<5;i++)
        {
            if(tapis[i][0]!=0)
            {
                printf("\t[%d,%s]\n",tapis[i][0],cartesCouleur(tapis[i][1]));
            }
        }
        printf("Mes cartes\n");
        for(int i=0;i<6;i++)
        {
        printf("[%d,%s]\t",distribution[i][0],cartesCouleur(distribution[i][1]));
        }
    }else{
        printf("\n\n\n\n");
        char rep[]="\tCartes communes\n";
        CHECK(write(sd, rep, strlen(rep) + 1), "Can't send");

        for(int i=0;i<5;i++)
        {
            if(tapis[i][0]!=0)
            {
                char reponse=tapis[i][0];
                char rep[MAX_BUFF];
                sprintf(rep,"%d",reponse);
                char reponse1[MAX_BUFF];
                strcpy(reponse1,cartesCouleur(tapis[i][1]));
                CHECK(write(sd, rep, MAX_BUFF), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                CHECK(write(sd, "\t", strlen("\t") + 1), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                CHECK(write(sd, reponse1, strlen(reponse1) + 1), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                CHECK(write(sd, "\n", strlen("\n") + 1), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                //printf("\t[%d,%s]",tapis[i][0],cartesCouleur(tapis[i][1]));
            }
        }
        printf("\n\n\n\n");

        char reponse2[]="\tMes cartes\n";
        CHECK(write(sd, reponse2, strlen(MSG) + 1), "Can't send");

        for(int i=0;i<6;i++)
        {
            if(distribution[i][2]==nb)
            {
                char reponse1[MAX_BUFF];
                char reponse=distribution[i][0];
                char rep[MAX_BUFF];
                sprintf(rep,"%d",reponse);
                strcpy(reponse1,cartesCouleur(distribution[i][1]));
                CHECK(write(sd, rep, MAX_BUFF), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                CHECK(write(sd, reponse1, strlen(reponse1) + 1), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                CHECK(write(sd, "\n", strlen("\n") + 1), "Can't send");
                read(sd,ack,sizeof(ack));
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
                //printf("[%d,%s]\t",distribution[i][0],cartesCouleur(distribution[i][1]));
            }
        } 
    }
    
    
    printf("\n");
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void affichageTapis()
 *
 *  \brief      La fonction affiche le tableau tapis[5][2]
 */
/* ------------------------------------------------------------------------ */
void affichageTapis() //affiche le tableau distribution
{
    for(int i=0;i<5;i++)
    {
        printf("[%d,%s]\n",tapis[i][0],cartesCouleur(tapis[i][1]));
    }
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int brelan(int)
 *
 * \brief       La fonction regarde si le joueur a un brelan dans la main qu'il a 
 *              choisi
 * 
 * \param       joueur  : Nombre representant le numéro du joueur
 * 
 * \return      int : Renvoie 0 si il n'y a pas de brelan ou le numero du brelan 
 *              si il existe
 */
/* ------------------------------------------------------------------------ */
int brelan(int joueur)// dit si il y a un brelan dans le tableau final 0:non
{
    int i=0;
    for(i=i+(joueur-1)*5;i<4+(joueur-1)*5;i++)
    {
        for(int j=i+1;j<5+(joueur-1)*5;j++)
        {
            if(mainFinale[i][0]==mainFinale[j][0])
            {
                for(int w=j+1;w<5+(joueur-1)*5;w++)
                {
                    if(mainFinale[j][0]==mainFinale[w][0])
                    {
                        //printf("i: %d, j: %d, w: %d, brelan : %d,%d,%d\n",i,j,w,mainFinale[i][0],mainFinale[j][0],mainFinale[w][0]);
                        return mainFinale[i][0]; //il y a un brelan
                    }
                }
            }
        }
    }
    //printf("pas brelan\n");
    return 0; //faux
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int carre(int)
 *
 * \brief       La fonction regarde si le joueur a un carre dans la main qu'il a 
 *              choisi
 * 
 * \param       joueur  : Nombre representant le numéro du joueur
 * 
 * \return      int : Renvoie 0 si il n'y a pas de carre ou le numero du carre 
 *              si il existe
 */
/* ------------------------------------------------------------------------ */
int carre(int joueur)
{
    for(int i=0+(joueur-1)*5;i<4+(joueur-1)*5;i++)
    {
        for(int j=i+1;j<5+(joueur-1)*5;j++)
        {
            if(mainFinale[i][0]==mainFinale[j][0])
            {
                for(int w=j+1;w<5+(joueur-1)*5;w++)
                {
                    if(mainFinale[j][0]==mainFinale[w][0])
                    {
                        for(int x=w+1;x<5+(joueur-1)*5;x++)
                        {
                            if(mainFinale[w][0]==mainFinale[x][0])
                            {
                                //printf("i: %d, j: %d, w: %d, x: %d carre : %d,%d,%d,%d\n",i,j,w,x,mainFinale[i][0],mainFinale[j][0],mainFinale[w][0],mainFinale[x][0]);
                                return mainFinale[i][0]; //il y a un carre
                            }
                        }
                    }
                }
            }
        }
    }
    //printf("pas carre\n");
    return 0; //faux
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         char *cartesCouleur(int)
 *
 *  \brief      La fonction transforme un int en char (0 -> coeur)
 * 
 *  \param      couleur  : Nombre representant la couleur
 * 
 *  \return     char * : Renvoie coeur si couleur=0, carreau si couleur=1,
 *              trefle si couleur=2, pique si couleur=3 et si couleur n'est 
 *              aucun de tout ces chiffres on renvoie "ko"
 */
/* ------------------------------------------------------------------------ */
char *cartesCouleur(int couleur)//transforme un int en char
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

void changerCartes(int joueur) //chaque joueur a la possibilite de changer ses cartes au premier tour
{
    int numero=-1,coul=-1,nombre=-1,ligne=-1,fini=0;
    char cCouleur[10];
    int tab[2];
    if (nb==1)//joueur 1
    {
        do
        {
            printf("Combien de cartes veux tu changer ? ");
            scanf("%d",&nombre);
            if(nombre>2 || nombre<0)
            {
                printf("Tu peux changer 2 cartes maximum.\n");
            }
        } while (nombre>2 || nombre<0);

        if(nombre==1) //Le joueur veux changer une carte
        {
            do
            {
                printf("Quelle carte veux tu changer ?\n");
                do
                {
                    printf("Veuillez taper le numero de votre carte (entre 6 et 13) : ");
                    scanf("%d",&numero);
                    if(numero<6 || numero>13)
                    {
                        printf("Tu n'as pas repondu correctement ! Ce chiffre n'est pas compris entre 6 et 13 !\n\n");
                    }
                } while (6>numero || numero>14);
                
                do
                {
                    printf("Veuillez taper la couleur de votre carte (coeur, carreau, trefle et pique) : ");
                    scanf("%s",cCouleur);
                    
                    coul=couleurCartes(cCouleur);
                    if(coul<0 || coul>3)
                    {
                        printf("Tu n'as pas repondu correctement ! Cette couleur n'existe pas !\n\n");
                    }
                } while (coul==-1);
                
                if(emplacementCarte(distribution,&ligne,numero,coul,nb)==0) // la carte n'existe pas
                {
                    printf("Cette carte n'est pas en votre possession. Donc vous ne pouvez pas echanger cette carte.\n\n");
                    fini=0;
                }
                else
                {
                    pile=depiler(pile,tab);
                    if(tab[0] == -1)
                    {
                        printf("Pile vide");
                    }
                    else
                    {
                        distribution[ligne][0] = tab[0];
                        distribution[ligne][1] = tab[1];
                        fini=1;
                    }
                }
            } while (fini!=1);
        }
        else if(nombre==2)//Le joueur veux echanger ses deux cartes 
        {
            for (int i=0; i<2; i++)//distribuer au joueur 2 cartes
            {
                pile=depiler(pile,tab);
                if(tab[0] == -1)
                {
                    printf("Pile vide");
                }
                else
                {
                    //printf("%d, %d\n",tab[0],tab[1]);
                    for(int j=0;j<6;j++)//on cherche les lignes du tableau qui appatiennent au joueur
                    {
                        if(distribution[j][2] == nb)
                        {
                            distribution[j+i][0] = tab[0];
                            distribution[j+i][1] = tab[1];
                            break;
                        }
                    }
                }
            }
        }
    }else//joueur 2 ou joueur 3
    {
        char ack[MAX_BUFF];
        CHECK(write(sd,DEM,strlen(DEM)),"can't send");
        read(sd,ack,sizeof(ack));
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
        read(sd,ack,sizeof(ack));
        sleep(1);
        }
        do
        {
            int nbre[MAX_BUFF];
            read(sd,nbre, sizeof(nbre));
            if (nbre!=NULL);
            {
                CHECK(write(sd,ACK,sizeof(ACK)),"can't send");
            }
            read(sd,ack,sizeof(ack));
            while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
            read(sd,ack,sizeof(ack));
            sleep(1);
            }

            int nombre=*nbre;
            
            if(nombre>2 || nombre<0)
            {
                char *rep="Tu peux changer 2 cartes maximum.\n";
                CHECK(write(sd,rep,strlen(rep)+1),"can't send");
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }
            }
        } while (nombre>2 || nombre<0);
        CHECK(write(sd,DEM,strlen(DEM)),"can't send");
        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
        read(sd,ack,sizeof(ack));
        sleep(1);
        }

        if(nombre==1) //Le joueur veut changer une carte
        {
            do
            {
                CHECK(write(sd,DEM,strlen(DEM)),"can't send");
                do
                {
                    int val[MAX_BUFF];
                    read(sd, val, sizeof(val));
                    int numero=*val;

                    if(numero<6 || numero>13)
                    {
                        char mes1[]="Tu n'as pas repondu correctement ! Ce chiffre n'est pas compris entre 6 et 13 !\n\n";
                        CHECK(write(sd,mes1,strlen(mes1)),"can't send");
                        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                        read(sd,ack,sizeof(ack));
                        sleep(1);
                        }
                    }
                } while (6>numero || numero>14);

                CHECK(write(sd,DEM,strlen(DEM)),"can't send");
                
                do
                {
                    read(sd, cCouleur, sizeof(cCouleur));
                    coul=couleurCartes(cCouleur);

                    if(coul<0 || coul>3)
                    {
                        char mes2[]="Tu n'as pas repondu correctement ! Cette couleur n'existe pas !\n\n";
                        CHECK(write(sd,mes2,strlen(mes2)),"can't send");
                        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                        read(sd,ack,sizeof(ack));
                        sleep(1);
                        }
                    }
                } while (coul==-1);
                CHECK(write(sd,DEM,strlen(DEM)),"can't send");
                while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                read(sd,ack,sizeof(ack));
                sleep(1);
                }

                if(emplacementCarte(distribution,&ligne,numero,coul,nb)==0) // la carte n'existe pas
                {
                    char mes3[]="Cette carte n'est pas en votre possession. Donc vous ne pouvez pas echanger cette carte.\n\n";
                    CHECK(write(sd,mes3,strlen(mes3)),"can't send");
                    while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                    read(sd,ack,sizeof(ack));
                    sleep(1);
                    }
                    CHECK(write(sd,DEM,strlen(DEM)),"can't send");
                    fini=0;
                }

                else
                {
                    pile=depiler(pile,tab);
                    if(tab[0] == -1)
                    {
                        printf("Pile vide");
                        CHECK(write(sd,"Pile vide",strlen("Pile vide")),"can't send");
                        while(strcmp(ack,ACK)!=0){ //attente d'ack (ACK) du client
                        read(sd,ack,sizeof(ack));
                        sleep(1);
                        }
                    }
                    else
                    {
                        distribution[ligne][0] = tab[0];
                        distribution[ligne][1] = tab[1];
                        fini=1;
                    }
                }
            } while (fini!=1);
        }
        else if(nombre==2)//Le joueur veux echanger ses deux cartes 
        {
            for (int i=0; i<2; i++)//distribuer au joueur 2 cartes
            {
                pile=depiler(pile,tab);
                if(tab[0] == -1)
                {
                    printf("Pile vide");
                }
                else
                {
                    //printf("%d, %d\n",tab[0],tab[1]);
                    for(int j=0;j<6;j++)//on cherche les lignes du tableau qui appatiennent au joueur
                    {
                        if(distribution[j][2] == nb)
                        {
                            distribution[j+i][0] = tab[0];
                            distribution[j+i][1] = tab[1];
                            break;
                        }
                    }
                }
            }
        }
    }
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int couleur(int)
 *
 * \brief       La fonction regarde si le joueur a toutes les cartes de la meme couleur 
 *              dans la main qu'il a choisi
 * 
 * \param       joueur  : Nombre representant le numéro du joueur
 * 
 * \return      int : Renvoie 0 si les 5 cartes ne sont pas de la meme couleur 
 *              et 5 si les 5 cartes sont de la meme couleur 
 */
/* ------------------------------------------------------------------------ */
int couleur(int joueur)//si ok=0 les 5 cartes ne sont pas de la meme couleur, si ok=5 les 5 cartes sont de la meme couleur
{
    int couleur=-1,ok=0;
    for(int i=0;i<15;i++)
    {
        if(mainFinale[i][2]==joueur) 
        {
            if(couleur==-1)
            {
                couleur=mainFinale[i][1];
                ok=1;
            }
            else if(mainFinale[i][1]==couleur)
            {
                ok++;
            }
            else
            {
                ok=0;
                break;
            }
            
        }
    }
    return ok;
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int couleurCartes(char *)
 *
 * \brief       La fonction transforme un char en int (coeur -> 0)
 * 
 * \param       cCouleur  : chaine de caractere representant la couleur
 * 
 * \return      int : Renvoie 0 si cCouleur="coeur", 1 si cCouleur="carreau",
 *              2 si cCouleur="trefle", 3 si couleur="pique" et si cCouleur n'est 
 *              aucune de toutes ces chaine de caracteres on renvoie -1
 */
/* ------------------------------------------------------------------------ */
int couleurCartes(char *cCouleur)//transforme un char en int
{
    int couleur=-1;

    if(strcmp(cCouleur,"coeur")==0)
    {
        couleur=0;
    }
    else if(strcmp(cCouleur,"carreau")==0)
    {
        couleur=1;
    }
    else if(strcmp(cCouleur,"trefle")==0)
    {
        couleur=2;
    }
    else if(strcmp(cCouleur,"pique")==0)
    {
        couleur=3;
    }

    return couleur;
}
/* ------------------------------------------------------------------------ */
/**
 *  \fn         void creationListeCartes()
 *
 *  \brief      La fonction crée une pile a partir du tableau paquetMelange. 
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

    //afficher(pile);
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          void creationNbPoints(int)
 *
 * \brief       La fonction creer le tableau nbPoints[3] à partir du tableau mainFinale[15][3] 
 *              en regardant pour chaque joueur si il a une suite, une couleur, un brelan, un full, une paire, un carre,...
 *              Puis on rempli nbPoints[numero du joueur] en fonction de ce qu'il a :
 *               - paire = 1*(numero de la paire)
 *               - double paire = 2*(numero de la paire la plus grande)
 *               - brelan = 3*(numero du brelan)
 *               - suite = 37
 *               - couleur = 38
 *               - full = 7*(numero du brelan)
 *               - carre = 8*(numero du carre)     
 *               - suite couleur = 210              
 * 
 * \param       joueur  : Nombre representant le numéro du joueur
 */
/* ------------------------------------------------------------------------ */
void creationNbPoints(int joueur)
{
    //printf("joueur = %d\n",joueur);
    int carte=0, cartePaire=0, carteBrelan=0;
    
    if(couleur(joueur)==5)
    {
        //printf("joueur %d : couleur",joueur);
        nbPoints[joueur]=38;
        if(suite(joueur)==4)//c'est une suite
        {
            //printf("joueur %d : suite",joueur);
            nbPoints[joueur]=210;
        }
    }
    else
    {
        if(suite(joueur)==4)//c'est une suite
        {
            //printf("joueur %d : suite",joueur);
            nbPoints[joueur]=37;
        }
        carte=carre(joueur);
        if(carte==0)//pas de carre
        {
            carte=brelan(joueur);
            if(carte==0)//pas de brelan
            {
                carte=paire(joueur,carte);
                if(carte==0)//pas de paire
                {
                    //printf("joueur %d : pas de paire\n",joueur);
                    nbPoints[joueur]=0;
                }
                else//il y a une paire
                {
                    cartePaire=carte;
                    //printf("joueur %d : paire de %d\n",joueur,cartePaire);
                    nbPoints[joueur]=1*cartePaire;
                    carte=paire(joueur,carte);
                    if(carte==0)//pas de paire
                    {
                        //printf("joueur %d : pas de 2e paire\n",joueur);
                    }
                    else//il y a 2 paires
                    {
                        //printf("joueur %d : il y a 2 paires de %d et %d\n",joueur,cartePaire, carte);
                        if(carte>cartePaire)
                        {
                            nbPoints[joueur]=2*carte;
                        }
                        else
                        {
                            nbPoints[joueur]=2*cartePaire;
                        }
                            
                    }
                }
                
            }
            else//il y a un brelan
            {
                carteBrelan=carte;
                //printf("joueur %d : brelan de %d\n",joueur, carteBrelan);
                nbPoints[joueur]=3*carteBrelan;
                carte=paire(joueur,carte);
                if(carte==0)//pas de paire
                {
                    //printf("joueur %d : pas de paire\n",joueur);
                }
                else //il y a un full
                {
                    //printf("joueur %d : il y a un full de %d et %d\n",joueur,carteBrelan,carte);
                    nbPoints[joueur]=7*carteBrelan;
                }
            }
        }
        else//il y a un carre
        {
            //printf("joeur %d : il y a un carre de %d\n",joueur,carte);
            nbPoints[joueur]=8*carte;
        }
    }
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
 * \fn          void demanderMainFinale(int)
 *
 * \brief       La fonction cree le tableau mainFinale[15][3] en demandant au 
 *              joueur quels carte de la table il veux ajouter a sa main
 *              
 * \param       joueur  : Nombre representant le numéro du joueur
 */
/* ------------------------------------------------------------------------ */
void demanderMainFinale(int joueur)//creer la mainFinal
{
    int numero=-1,couleur=-1,ligne=-1,fini=1,ok=1;
    char cCouleur[10];
    int tab[2];

    for(int i=0;i<6;i++)
    {
        if(distribution[i][2]==nb)
        {
            mainFinale[tailleMain][0]=distribution[i][0];
            mainFinale[tailleMain][1]=distribution[i][1];
            mainFinale[tailleMain][2]=nb;
            tailleMain++;
        }
    }

    printf("Quelles sont les 3 cartes de la table que tu veux associées ta main ?\n");

    do
    {
        printf("Carte %d\n",fini);

        do
        {       
            do
            {
                char message[]="Veuillez taper le chiffre d'une des carte de la table : ";
                CHECK(read(sd,message,sizeof(message)),"can't send");
                CHECK(read(sd,numero,sizeof(numero)),"can't send");
                scanf("%d",&numero);
                if(existeTapis(numero,-1,nb,1,fini)==0)
                {
                    printf("Tu n'as pas repondu correctement ! La table n'a pas une carte de ce chiffre !\n\n");
                    ok=0;
                }
                else
                {
                    ok=1;
                }
            } while (ok!=1);
            
            ok=0;
            do
            {
                if(ok==0)
                {
                    printf("Vous avez choisi le chiffre %d. Quelle couleur est cette carte ?\n",numero);
                    do
                    {
                        printf("Veuillez taper la couleur de votre carte (coeur, carreau, trefle et pique) : ");
                        scanf("%s",cCouleur);
                        
                        couleur=couleurCartes(cCouleur);
                        if(couleur<0 || couleur>3)
                        {
                            printf("Tu n'as pas repondu correctement ! Cette couleur n'existe pas !\n\n");
                            ok=0;
                            printf("Vous avez choisi le chiffre %d. Quelle couleur est cette carte ?\n",numero);
                        }
                        else
                        {
                            ok=1;
                        }
                    } while (ok!=1);
                }

                if(existeTapis(numero,couleur,nb,2,fini)==0)
                {
                    printf("Cette carte n'existe pas sur le tapis\n\n");
                    ok=0;
                }
                else if(existeTapis(numero,couleur,nb,2,fini)==2)
                {
                    printf("Vous avez deja choisi cette carte !\n");
                    printf("Veuillez en choisir une autre.\n");
                    ok=2;
                }
                else
                {
                    mainFinale[tailleMain][0]=numero;
                    mainFinale[tailleMain][1]=couleur;
                    mainFinale[tailleMain][2]=nb;
                    tailleMain++;
                    ok=1;
                }
            } while (ok==0);

        }while (ok!=1);

        fini++;
    } while (fini!=4);
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         void distribuer2Cartes()
 *
 *  \brief      La fonction enleve les deux premieres carte de la pile et les donne
 *              au premier joueur puis fais la meme chose pour les autres joueurs.
 *              Les cartes distribuées sont enregistrée par le serveur dans un tableau distribution.
 *              En premiere colonne le numero de la carte, en deuxieme colonne sa couleur et en troisieme 
 *              colonne le numéro du joueur à qui elle a été donnée.
 */
/* ------------------------------------------------------------------------ */
void distribuer2Cartes() //on distribue 2 cartes aux joueurs
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

void distribuerTapis(int nbCartes) //on distribuer nbCartes sur la zoner centrale
{
    int tab[2];

    for(int i=0;i<nbCartes;i++)
    {
        pile=depiler(pile,tab);
        if(tab[0] == -1)
        {
            printf("Pile vide");
        }
        else
        {
            //printf("%d, %d\n",tab[0],tab[1]);
            tapis[tailleTapis][0] = tab[0];
            tapis[tailleTapis][1] = tab[1];
            tailleTapis++;
        }        
    }
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int emplacementCarte(int tab[6][3],int *, int , int , int)
 *
 * \brief       La fonction trouve l'emplacement de la carte donnée en parametre si elle existe
 * 
 * \param       tab[6][3]  : Tableau ou est mis la distribution des cartes
 * \param       ligne  : Nombre representant le numéro de la ligne ou se situe la carte
 * \param       carte  : Nombre representant le numero de la carte
 * \param       couleur  : Nombre representant la couleur de la carte
 * \param       joueur  : Nombre representant le numéro du joueur  
 * 
 * \return      int : Renvoie 0 si la carte n'existe pas ou 1 si elle existe
 */
/* ------------------------------------------------------------------------ */
int emplacementCarte(int tab[6][3],int *ligne, int carte, int couleur, int joueur) // trouve l'emplacement de la carte si elle existe
{
    for (int i=0;i<6;i++)
    {
        if(tab[i][2] == joueur)
        {
            if(tab[i][1] == couleur)
            {
                if(tab[i][0] == carte)
                {
                    *ligne=i;
                    return 1; //la carte existe
                }
            }
        }
    }
    return 0; //la carte n'existe pas
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int existeTapis(int, int, int, int, int)
 *
 * \brief       La fonction si la carte existe sur le tapis ou pas.
 *              La fonction est appellée plusieurs fois pour pouvoir verifier 
 *              d'abord si le numero exite, 
 *              puis si la couleur exite, si oui on verifie que l'association des deux existe sur le tapis.
 *              A partir de la deuxieme carte choisie il faut verifie si le joueur n'a pas deja choisi cette carte
 * 
 * \param       nombre  : Nombre representant le numero de la carte
 * \param       couleur  : Nombre representant la couleur de la carte
 * \param       joueur  : Nombre representant le numéro du joueur
 * \param       cas  : si 1 alors on verifi le nombre, si 2 alors on verifi la couleur et si la carte existe
 * \param       tour : 1 on a pas besoin de verifie si la carte a deja ete choisi, sinon on verifi dans le tableau mainFinale[15][3]
 * 
 * \return      int : Renvoie 0 si la carte n'existe pas ou 1 si la carte existe sur le tapis ou 2 si carte a deja ete choisi
 */
/* ------------------------------------------------------------------------ */
int existeTapis(int nombre, int couleur, int joueur, int cas, int tour)//verifie si la carte existe sur le tapis et si on ne l'a deja ajouter dans MainFinal
{
    if(tour==1)
    {
        if(cas==1)// le nombre existe ?
        {
            for (int i=0;i<5;i++)
            {
                if(tapis[i][0] == nombre)
                {
                    return 1; //la nombre existe existe
                }
            }
        }
        else if(cas==2)
        {
            for (int i=0;i<5;i++)
            {
                if(tapis[i][1] == couleur)
                {
                    if(tapis[i][0] == nombre)
                    {
                        return 1; //la carte existe
                    }
                }
            }
        }
    }
    else
    {
        if(cas==1)// le nombre existe ?
        {
            for (int i=0;i<5;i++)
            {
                if(tapis[i][0] == nombre)
                {
                    return 1; //la nombre existe existe
                }
            }
        }
        else if(cas==2)
        {
            for (int i=0;i<5;i++)
            {
                if(tapis[i][1] == couleur)
                {
                    if(tapis[i][0] == nombre)
                    {
                        for(int j=0;j<tailleMain+1;j++)
                        {
                            if(mainFinale[j][2]==joueur)
                            {
                                if(mainFinale[j][1] == couleur)
                                {
                                    if(mainFinale[j][0] == nombre)
                                    {
                                        return 2; //la carte a deja été selectionnée
                                    }
                                }
                            }
                        }
                        return 1; //la carte existe
                    }
                }
            }
        }    
    }
    return 0; //la carte n'existe pas
}

/* ------------------------------------------------------------------------ */
/**
 * \fn          int paire(int, int)
 *
 * \brief       La fonction regarde si le joueur a une paire dans la main qu'il a 
 *              choisi
 * 
 * \param       joueur  : Nombre representant le numéro du joueur
 * \param       carte  : Nombre a verifie pour ne pas faire une paire de ce numero
 * 
 * \return      int : Renvoie 0 si il n'y a pas de paire ou le numero de la paire 
 *              si elle existe
 */
/* ------------------------------------------------------------------------ */
int paire(int joueur, int carte)// dit si il y a une paire dans le tableau final 0:non
{
    int i=0;
    if(carte==0)
    {
        for(i=i+(joueur-1)*5;i<4+(joueur-1)*5;i++)
        {
            //printf("carte 1 => %d : %d\n",i,mainFinale[i][0]);
            for(int j=i+1;j<5+(joueur-1)*5;j++)
            {
                //printf("carte 2 => %d : %d\n",j,mainFinale[j][0]);
                if(mainFinale[i][0]==mainFinale[j][0])
                {
                    //printf("i: %d, j: %d, paire : %d,%d\n",i,j,mainFinale[i][0],mainFinale[j][0]);
                    return mainFinale[i][0]; //il y a une paire
                }
            }
        }
    }
    else
    {
        for(i=i+(joueur-1)*5;i<4+(joueur-1)*5;i++)
        {
            if(mainFinale[i][0]!=carte)
            {
                for(int j=i+1;j<5+(joueur-1)*5;j++)
                {
                    if(mainFinale[i][0]==mainFinale[j][0])
                    {
                        //printf("i: %d, j: %d, paire : %d,%d\n",i,j,mainFinale[i][0],mainFinale[j][0]);
                        return mainFinale[i][0]; //il y a une paire
                    }
                }
            }
        }
    }
    //printf("pas paire\n");
    return 0; //faux
}

/* ------------------------------------------------------------------------ */
/**
 *  \fn         int verifierCarte(int tab[32][2],int , int , int )
 *
 *  \brief      La fonction vérifie si la combinaison carte couleur existe deja dans le tableau.
 *
 * \param       tab[32][2] : Tableau de carte
 * \param       ligne : Nombre representant la derniere ligne du tableau
 * \param       carte : Nombre representant le numéro de la carte
 * \param       couleur : Nombre representant la couleur de la carte
 * 
 * \return      int : Renvoie 1 si la carte exite ou 0 si elle n'existe pas
 */
/* ------------------------------------------------------------------------ */

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
 * \fn          int suite(int)
 *
 * \brief       La fonction regarde si le joueur a une suite dans la main qu'il a 
 *              choisi
 * 
 * \param       joueur  : Nombre representant le numéro du joueur
 * 
 * \return      int : Renvoie 0 si il n'y a pas de suite ou 4 si la suite existe
 */
/* ------------------------------------------------------------------------ */
int suite(int joueur)// si ok=0 : pas de suite, si ok=4 c'est une suite
{
    int tab[5];
    int ok=0,j=0, aux=0;

    //construction du tableau
    for(int i=0;i<15;i++)
    {
        if(mainFinale[i][2]==joueur) 
        {
            tab[j]=mainFinale[i][0];
            j++;
        }
    }

    //TRI du tableau
    for(int i=0;i<4;i++)
    {
        for(int j=4;j>i;j--)
        {
            if(tab[j]<tab[j-1])
            {
                aux=tab[j];
                tab[j]=tab[j-1];
                tab[j-1]=aux;
            }
        }
    }

    //verification que c'est une suite
    for (int i=0; i<4; i++)
    {
        if(tab[i+1]==tab[i]+1)
        {
            ok++;
        }
        else
        {
            ok=0;
            break;//c'est pas une suite
        }   
    }
    return ok;
}
