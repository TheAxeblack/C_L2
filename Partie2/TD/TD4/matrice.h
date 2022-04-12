/**
 *fichier d'en tete du module TAD matrice
 *
 *on suppose ici des matrices avec des doubles
 *
 *une première solution est de creer une matrice sous la forme
 *d'un tableau de doubles comme suit
 * typedef double ** matrice;
 *C'est tout à fait acceptable mais oblige de passer les dimensions de 
 *la matrice en argument des fonctions d'addition et de multiplication par exemple
 *
 *Nous proposons une autre solution visant à encapsuler la matrice dans une structure
 *
 *Pour rendre l'acces à la matrice indépendant de l'implémetation, il faut utiliser les fonctions
 *set_element_matrice et get_element_matrice (cf main)
 *
 *hist A. Habrard
 * creation le 10/03/2015
 * modif 01/03/2016
 */

#ifndef _MATRICE_H_
#define _MATRICE_H_

#include <stdio.h>
#include "allocation.h"
#include "mon_erreur.h"

typedef struct matrice_cellule {
    int l; /*//nb de lignes*/
    int c; /*//nb de colonnes*/
    double **tab; /*//tableau*/
} cell_matrice;
typedef cell_matrice *matrice; /*//une matrice est un pointeur sur une cellule cell_matrice*/

/*fonction de creation de matrice générale avec l lignes et c colonnes*/
matrice creer_matrice(int l, int c);

/*récupération de l'element a la position [i,j] dans m*/
double get_element_matrice(matrice m, int i, int j);

/*on fixe l'element a la position [i,j] dans m à la valeur val*/
void set_element_matrice(matrice m, int i, int j, double val);

/*mutiplie les entrées de la matrice par le scalaire val*/
void multiplie_scalaire(matrice m, double val);

/*somme de 2 matrices*/
matrice somme_matrices(matrice mat1, matrice mat2);

/*multiplication de 2 matrices*/
matrice multiplication_matrices(matrice mat1, matrice mat2);

/*affichage d'une matrice*/
void affiche_matrice(matrice m);

#endif
