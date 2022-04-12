/**
 *fichier d'en tete du module TAD liste
 *Impementation utilisée pour les matrices creuses
 * 
 *Il faut définir les fonctions est_avant et est_egal en fonction des valeurs possible du type element
 *
 *hist A. Habrard
 * creation le 20/03/2019
 * 
 */

#ifndef _LISTE_H_
#define _LISTE_H_

#include <stdio.h>
#include "allocation.h"
#include "mon_erreur.h"

typedef int value;

typedef struct mat_elem{
  int ligne;
  int colonne;
  value valeur;
} element;

typedef struct cellule{
 element objet;
 struct cellule * suivant;
}struct_cellule;

typedef struct_cellule * liste;

/* renvoie la liste vide */
liste liste_vide();
/* teste si une liste est vide */
int est_liste_vide(liste l);
/*ajoute un element elem a la liste l */
liste insere_element_liste(liste l, element elem);
/* renvoie le premier element de la liste l */
element renvoie_premier_liste(liste l);
/*renvoie la suite de la liste*/
liste renvoie_suivant_liste(liste l);
/* supprime la premiere cellule de la liste l */
liste supprimer_premier_liste(liste l);
/*affichage d'une liste*/
void affiche_liste(liste l);
/*fonction d'ordre sur les elements*/
int est_avant(element e1,element e2);
/*fonction d'egalite sur les elements*/
int est_egal(element e1,element e2);

/* Recher d'une element dans une liste et renvoi la cellule le contenu ou NULL sinon, utilise la fonction est_egal */
liste recherche_element(liste l, element elem);
/* fonction qui concatene deux listes*/
liste concatene_listes(liste l1,liste l2);
/* fonction qui insere dans une liste ordonnee, utilise la fonction est_avant*/
liste insere_liste_ordonnee(liste l,element e);
#endif
