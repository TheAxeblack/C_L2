/**
 *fichier main pour tester le TAD matrice
 *
 * hist A. Habrard
 *  creation le 20/03/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrice_creuse.h"

int main()
{
 
  matrice res1,res2,res3;
  matrice m1=cree_matrice(6,7);
  matrice m2=cree_matrice(6,7);
  matrice m3=cree_matrice(7,6);

  ajoute_valeur(m1,0,1,2);
  ajoute_valeur(m1,4,6,5);
  ajoute_valeur(m2,2,1,4);
  ajoute_valeur(m2,4,6,8);
  ajoute_valeur(m3,0,5,1);
  ajoute_valeur(m3,1,1,10);
  ajoute_valeur(m3,5,5,10);
  
  printf("Affichage matrice 1\n");
  affiche_matrice(m1);
  printf("\nAffichage matrice 2\n");
  affiche_matrice(m2);
   printf("\nAffichage matrice 3\n");
  affiche_matrice(m3);

  printf("\nAffichage matrice 1, apres multiplication par le scalaire 2\n");
  res3=produit_par_scalaire(m1,2);
  affiche_matrice(res3);

  res1=somme_matrices(m1,m2);
  printf("\nAffichage somme matrice 1 et 2\n");
  affiche_matrice(res1);
  
  res2=produit_matrices(m2,m3);
  printf("\nAffichage multiplication matrice 2 et 3\n");
  affiche_matrice(res2);

  printf("Affichage matrice 1 - version creuse\n");
  affiche_matrice_creuse(m1);
  printf("\nAffichage matrice 2 - version creuse\n");
  affiche_matrice_creuse(m2);
   printf("\nAffichage matrice 3 - version creuse\n");
  affiche_matrice_creuse(m3);

  return EXIT_SUCCESS;
}
