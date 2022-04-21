#include "../inc/arbre_binaire.h"

arbre creer_arbre_vide() {
    return NULL;
}

int est_vide(arbre a) {
    return (a == creer_arbre_vide());
}

arbre creer_arbre(char c, arbre filsgauche, arbre filsdroit) {
    arbre a = (arbre) malloc(1 * sizeof(noeud_binaire_struct));
    assert(a != NULL);
    a->noeud = c;
    a->gauche = filsgauche;
    a->droit = filsdroit;
    return a;
}

arbre creer_noeud(char c) {
    arbre a = creer_arbre(c, creer_arbre_vide(), creer_arbre_vide());
    return a;
}

arbre inserer_fils_gauche(arbre a, arbre filsgauche) {
    if (est_vide(a))
        return filsgauche;
    a->gauche = filsgauche;
    return a;
}

arbre inserer_fils_droit(arbre a, arbre filsdroit) {
    if (est_vide(a))
        return filsdroit;
    a->droit = filsdroit;
    return a;
}


void afficher_arbre_infixe(arbre a) {
    if (!est_vide(a)) {
        if (a->noeud != 0) {
            afficher_arbre_infixe(a->gauche);
            printf("%c", a->noeud);
            afficher_arbre_infixe(a->droit);
        }
    }
}

void afficher_arbre_postfixe(arbre a) {
    if (!est_vide(a)) {
        if (a->noeud != 0) {
            afficher_arbre_postfixe(a->gauche);
            afficher_arbre_postfixe(a->droit);
            printf("%c", a->noeud);
        }
    }
}

void afficher_arbre_prefixe(arbre a) {
    if (!est_vide(a)) {
        if (a->noeud != 0) {
            printf("%c", a->noeud);
            afficher_arbre_prefixe(a->gauche);
            afficher_arbre_prefixe(a->droit);
        }
    }
}

void afficher_arbre_graphique(arbre a) {
    if (!est_vide(a)) {
        if (a->noeud != 0) {
            MLV_draw_text(320, 40, "%c", MLV_COLOR_MAGENTA, a->noeud);
            afficher_arbre_graphique(a->gauche);
            afficher_arbre_graphique(a->droit);
        }
    }
}