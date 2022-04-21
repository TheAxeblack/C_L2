#include "../inc/tp3.h"

file file_vide() {
    return liste_vide();
}

int est_file_vide(file f) {
    return est_liste_vide(f);
}

file defiler(file f) {
    return supprimer_premier_liste(f);
}

element debut_file(file f) {
    return renvoie_premier_liste(f);
}

int taille_file(file f) {
    int nb = 0;
    liste lcourant = f;
    while (lcourant) {
        nb++;
        lcourant = lcourant->suivant;
    }
    return nb;
}

file enfiler(file f, element elem) {
    liste nliste = inserer_element_liste(liste_vide(), elem);
    liste lcourant = f;
    if (est_file_vide(f))
        return nliste;

    while (lcourant->suivant != liste_vide())
        lcourant = lcourant->suivant;

    lcourant->suivant = nliste;
    return f;
}

void afficher_file(file f) {
    if (est_file_vide(f))
        printf("File vide\n");
    while (!est_file_vide(f)) {
        printf(" %d ", f->objet);
        f = f->suivant;
    }
    printf("\n");
}