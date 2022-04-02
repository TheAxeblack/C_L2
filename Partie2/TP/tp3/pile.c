#include "tp3.h"

pile pile_vide() {
    return liste_vide();
}

int est_pile_vide(pile p) {
    return est_liste_vide(p);
}

pile empiler(pile p, element elem) {
    return inserer_element_liste(p, elem);
}

element sommet_pile(pile p) {
    return renvoie_premier_liste(p);
}

pile depiler(pile p) {
    return supprimer_premier_liste(p);
}

int taille_pile(pile p) {
    int nb = 0;
    liste lcourant = p;
    while (lcourant) {
        nb++;
        lcourant = lcourant->suivant;
    }
    return nb;
}

void afficher_pile(pile p) {
    if (est_pile_vide(p))
        printf("Pile vide\n");
    while (!est_pile_vide(p)) {
        printf(" %d ", p->objet);
        p = p->suivant;
    }
    printf("\n");
}