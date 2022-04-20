#ifndef TP_LISTE_H
#define TP_LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int element;

typedef struct cellule {
    element objet;
    struct cellule *suivant;
} struct_cellule;

typedef struct_cellule *liste;

/* Renvoie la liste vide */
liste liste_vide();

/* Teste si une liste est vide */
int est_liste_vide(liste l);

/* Ajoute un element elem dans la Liste l */
liste inserer_element_liste(liste l, element elem);

/* Renvoie le premier element de la liste l */
element renvoie_premier_liste(liste l);

/* Supprime la première cellule de la liste l */
liste supprimer_premier_liste(liste l);

liste trouver_element(liste l, element elem);

void affiche_liste(liste l);

#endif
