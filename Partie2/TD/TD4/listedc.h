/**
 *fichier d'en tete du module TAD liste doublement chainee
 *
 *hist A. Habrard
 * creation le 09/03/2015
 */

#ifndef _LISTEDC_H_
#define _LISTEDC_H_

#include <stdio.h>
#include "allocation.h"
#include "mon_erreur.h"

typedef int element;

typedef struct cellule {
    element objet;
    struct cellule *suivant;
    struct cellule *precedent;
} struct_cellule;
typedef struct_cellule *liste;

/* renvoie la liste vide */
liste liste_vide();

/* teste si une liste est vide */
int est_liste_vide(liste l);

/*ajoute un element elem au debut de la liste l */
liste inserer_element(liste l, element elem);

/*insertion element dans une liste deja triee*/
liste inserer_element_trie(liste l, element elem);

/* renvoie le premier element de la liste l */
element renvoie_premier_liste(liste l);

/*renvoie la suite de la liste*/
liste renvoie_suite(liste l);

/*renvoie la suite de la liste*/
liste renvoie_precedent(liste l);

/* supprime l'element e de la liste l */
liste supprimer_element(liste l, element e);

/*affichage d'une liste avec indication du précédent*/
void affiche_liste(liste l);

/*affichage d'une liste classique*/
void affiche_liste_classique(liste l);

#endif
