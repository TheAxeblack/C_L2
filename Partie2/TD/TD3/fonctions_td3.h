/**
 *Fichier d'en tete de fonctions_td3.c
 *
 *contient la déclaration des principales fonctions du fichier
 *
 * hist :
 *  A. Habrard le 01/02/2015
 *
 */

#ifndef FONCTIONS_TD3_H_
#define FONCTIONS_TD3_H_

/*declaration des constantes */
#define TAILLE_TAB1 5
#define TAILLE_TAB2 3
#define TAILLE_MATRICE 3
/* ---- */


/* ------- declaration des fonctions -------- */

/*fonction qui cree et renvoie un tableau contenant les entiers de 
 *deux tableaux d'entiers passes en parametre:
 *tab1 de taille n1, tab2 de taille n2
 */
int * concat(int * tab1, int * tab2, int n1, int n2);

/*fonction qui cree et renvoie la sous-chaine de la chaine  
 * de caracteres contenue dans chauine omprise entre les deux 
 *index1 et index2 inclus
 */
char * sous_chaine(char * chaine, int index1, int index2);

/*fonction qui prend en argument deux matrices carrées de même taille, 
 *leur taille n et qui renvoie une matrice de même taille contenant la 
 *somme des 2 matrices mat1 et mat2 données en argument
 *ces matrices doivent être définies par des pointeurs de pointeurs
 */int **somme(int ** mat1,int ** mat2, int dimension_mat);

/*fonction qui prend en argument deux matrices carrées de même taille, 
 *leur taille n et qui renvoie une matrice de même taille contenant la 
 *somme des 2 matrices mat1 et mat2 données en argument
 *ces matrices sont de dimensions constantes
 */
int **somme_constante(int mat1[][TAILLE_MATRICE],int mat2[][TAILLE_MATRICE], int dimension_mat);

/* fonction itoa, la solution est rangée dans chaine_nombre 
 * n est le nombre à inverser, et chaine_nombre représente la chaine
 * ou on stocke le resultat */
char * itoa(int n);

/*fonctions auxiliaires*/

/*affichage d'un tableau d'entier */
void affiche_tableau(int * tab, int taille);

/*affichage d'un tableau d'entier constant de taille TAILLE_MATRICE*/
void affiche_matrice_constante(int  mat[][TAILLE_MATRICE], int taille);

/*affichage d'un tableau d'entier defini par des pointeurs */
void affiche_matrice_pointeur(int ** mat, int taille);
/* ---- */

#endif
