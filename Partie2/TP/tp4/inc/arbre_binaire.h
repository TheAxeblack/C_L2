#ifndef C_ARBRE_BINAIRE_H
#define C_ARBRE_BINAIRE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct noeud_binaire {
    char noeud;
    struct noeud_binaire *gauche;
    struct noeud_binaire *droit;
} noeud_binaire_struct;

typedef noeud_binaire_struct *arbre;

arbre creer_arbre_vide();

int est_vide(arbre a);

arbre creer_arbre(char c, arbre filsgauche, arbre filsdroit);

arbre creer_noeud(char c);

arbre inserer_fils_gauche(arbre a, arbre filsgauche);

arbre inserer_fils_droit(arbre a, arbre filsdroit);

void afficher_arbre_infixe(arbre a);

void affiche_racine(arbre a);

void afficher_arbre_postfixe(arbre a);

void afficher_arbre_prefixe(arbre a);

#endif