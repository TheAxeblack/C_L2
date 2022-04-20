#include "../inc/liste.h"

liste liste_vide() {
    return NULL;
}

int est_liste_vide(liste l) {
    if (l == liste_vide())
        return 1;
    return 0;
}

liste inserer_element_liste(liste l, element elem) {
    liste nliste;
    nliste = (liste) malloc(1 * sizeof(struct_cellule));
    if (nliste == NULL) {
        fprintf(stderr, "Probleme survenu lors de l'allocation memoire a la Liste.\n");
        exit(EXIT_FAILURE);
    }
    nliste->objet = elem;
    nliste->suivant = l;
    return nliste;
}

element renvoie_premier_liste(liste l) {
    if (est_liste_vide(l)) {
        fprintf(stderr, "Erreur la liste est vide dans la fonction renvoie_premier_liste\n");
        exit(EXIT_FAILURE);
    }
    return l->objet;
}

liste supprimer_premier_liste(liste l) {
    liste lsuivant = l->suivant;
    libere_mem(&l);
    return lsuivant;
}

liste trouver_element(liste l, element elem) {
    liste p = l;
    while (p->objet != elem && !est_liste_vide(p))
        p = p->suivant;
    return p;
}


void affiche_liste(liste l) {
    printf("<");
    while (!est_liste_vide(l)) {
        printf(" %d ", l->objet);
        l = l->suivant;
    }
    printf(">\n");
}