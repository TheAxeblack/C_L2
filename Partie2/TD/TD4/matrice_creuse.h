/**
 *fichier d'en tete du matrice creuse
 *
 *
 *hist A. Habrard
 * creation le 20/03/2019
 */

#ifndef _MATRICE_CREUSE_H_
#define _MATRICE_CREUSE_H_

#include <stdio.h>
#include "allocation.h"
#include "mon_erreur.h"
#include "liste_gen.h"

/*structure de données qui utilise une structure de liste du module liste_gen */
typedef struct mat{
  int nb_lignes;
  int nb_colonnes;
  liste liste_valeur;
}struct_mat;

typedef struct_mat * matrice;


/* creation de matrice */
matrice cree_matrice(int nb_lignes,int nb_colonnes);
/* Ajouter une valeur à une matrice */
void ajoute_valeur(matrice m,int i, int j,value val);
/* recupere la valeur de la matrice m à la position i,j */
value recupere_valeur(matrice m,int i, int j);
/*somme de matrice optimisée  */
matrice somme_matrices(matrice m1,matrice m2);
/* multiplication de matrices : note algo non optimisé sur les colonnes car la structure de donnée ne s'y prete pas */
matrice produit_matrices(matrice m1,matrice m2);
/*produit scalaire */
matrice produit_par_scalaire(matrice m1,value scalaire);
/* affichage matrice classique */
void affiche_matrice(matrice m);
/* affichage matrice creuse : affichage de liste*/
void affiche_matrice_creuse(matrice m);
#endif
