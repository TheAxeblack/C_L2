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


/* afficher_arbre est le parcours prefixe */
void afficher_arbre(arbre a) {
    if (!est_vide(a)) {
        if (a->noeud != 0) {
            printf("%c", a->noeud);
            afficher_arbre(a->gauche);
            afficher_arbre(a->droit);
        }
    }
}