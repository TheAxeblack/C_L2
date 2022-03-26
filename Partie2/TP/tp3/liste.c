#include "tp3.h"

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
    liste lsuivant;
    lsuivant = l->suivant;
    if (l != NULL) {
        free(l);
    }
    l = NULL;
    return lsuivant;
}

liste trouver_element(liste l, element elem) {
    liste p = l;
    while (p->objet != elem && !est_liste_vide(p))
        p = p->suivant;
    return p;
}

liste liste_cat(liste l1, liste l2) {
    liste p;
    p = l1;
    if (est_liste_vide(l1))
        return l2;
    while (p->suivant != NULL)
        p = p->suivant;
    p->suivant = l2;
    return l1;
}

liste insere_element_liste_ordonnee(liste l, element elem) {
    liste p = l;
    liste cell_debut = inserer_element_liste(liste_vide(), elem);
    if (est_liste_vide(l))
        return cell_debut;
    if (l->objet > elem) {
        cell_debut->suivant = l;
        return cell_debut;
    }
    while (!est_liste_vide(p->suivant) && p->suivant->objet < elem)
        p = p->suivant;
    cell_debut->suivant = p->suivant;
    p->suivant = cell_debut;
    return l;
}

liste recopie(liste l) {
    liste p = l, p2 = liste_vide(), resultat = liste_vide();
    while (!est_liste_vide(p)) {
        liste new = inserer_element_liste(liste_vide(), p->objet);
        if (est_liste_vide(resultat))
            resultat = new;
        else {
            p2->suivant = new;
            p2 = p2->suivant;
        }
        p = p->suivant;
    }
    return l;
}

liste recopie_liste_recu2(liste l) {
    liste cell_new = liste_vide();
    if (est_liste_vide(l))
        return liste_vide();
    cell_new = inserer_element_liste(liste_vide(), l->objet);
    cell_new->suivant = recopie_liste_recu2(l->suivant);
    return cell_new;
}