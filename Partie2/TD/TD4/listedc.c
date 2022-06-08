/**
 *fichier d'implementation du module TAD liste
 *on a rajoute une fonction renvoie_suivant_liste(l) qui peut
 *remplacer tous les appels du type l->suivant, ce qui permet
 *de cacher completement l'implementation
 *et une fonction d'afichage de liste
 *
 *hist A. Habrard
 * creation le 09/03/2015
 * modif le 19/03/2015
 */

#include <stdio.h>
#include "listedc.h"

/*retour liste vide*/
liste liste_vide() {
    return NULL;
}

/*test liste vide*/
int est_liste_vide(liste l) {
    if (l == liste_vide())
        return 1;
    return 0;
}

/*insertion element au debut de la liste*/
liste inserer_element(liste l, element elem) {
    liste lnew = (liste) allocation_mem(1, sizeof(struct_cellule));
    lnew->objet = elem;
    lnew->precedent = liste_vide();
    lnew->suivant = l;
    if (!est_liste_vide(l))
        l->precedent = lnew;

    return lnew;
}


/*insertion element dans une liste deja triee */
liste inserer_element_trie(liste l, element elem) {
    liste p = l;
    liste lnew = (liste) allocation_mem(1, sizeof(struct_cellule));/*creation cellule*/
    lnew->objet = elem;
    lnew->precedent = liste_vide();
    lnew->suivant = liste_vide();

    /*cas où l est vide, lnew est le nouveau debut de liste*/
    if (est_liste_vide(l))
        return lnew;

    /*cas où on doit ajouter au debut, lnew est le nouveau debut de liste*/
    if (elem < l->objet) {
        lnew->suivant = l;
        l->precedent = lnew;
        return lnew;
    }

    /*on cherche la position de l'element dans la liste*/
    while (!est_liste_vide(p->suivant) && p->suivant->objet < elem) {
        p = p->suivant;
    }
    /*on a trouve la bonne position, on met a jour le chainage */
    lnew->precedent = p;
    lnew->suivant = p->suivant;
    if (!est_liste_vide(p->suivant)) /*cas uniquement si on n'est pas à la derniere position*/
        p->suivant->precedent = lnew;
    p->suivant = lnew;

    /*si on a insere au milieu, le debut de liste ne change pas*/
    return l;
}

/*renvoie le premier element de la liste, erreur sinon*/
element renvoie_premier_liste(liste l) {
    if (est_liste_vide(l))
        mon_erreur("Erreur la liste est vide dans la fonction renvoie_premier\n");
    return l->objet;
}

/*renvoie la suite de la liste, liste_vide sinon*/
liste renvoie_suite(liste l) {
    if (est_liste_vide(l))
        return l;
    return l->suivant;
}

/*renvoie la suite de la liste, liste_vide sinon*/
liste renvoie_precedent(liste l) {
    if (est_liste_vide(l))
        return l;
    return l->precedent;
}

/*supprimer l'element e de la liste*/
liste supprimer_element(liste l, element e) {
    liste p = l;
    /*on cherche l'objet */
    while (!est_liste_vide(p) && p->objet != e) {
        p = p->suivant;
    }
    /*si on ne l'a pas trouvé, on n'a rien a faire*/
    if (!est_liste_vide(p)) {
        if (p == l) {
            /* cas où on est en debut de liste */
            liste psuivant = l->suivant;
            libere_mem((void **) &l);
            if (!est_liste_vide(psuivant))
                psuivant->precedent = liste_vide();
            /*il faut renvoyer la cellule suivante comme nouveau debut de liste*/
            return psuivant;
        } else {
            /*cas où on est en milieu de liste */
            if (!est_liste_vide(p->suivant)) /*cas uniquement si on n'est pas à la derniere position*/
                p->suivant->precedent = p->precedent;
            p->precedent->suivant = p->suivant;
            libere_mem((void **) &p);
        }
    }
    /* si on a supprimer au milieu ou si on n'a pas trouve l'element, le debut de liste n'a pas change*/
    return l;
}

/*affichage d'une liste avec indication du precedent*/
void affiche_liste(liste l) {
    liste p = l;

    if (est_liste_vide(p))
        printf("[vide]");

    while (!est_liste_vide(p)) {
        if (!est_liste_vide(p->precedent))
            printf("%d [precedent: %d] -- ", p->objet, p->precedent->objet);
        else printf("%d [debut] -- ", p->objet);
        p = p->suivant;
    }
    printf("\n");
}

/*affichage d'une liste classique*/
void affiche_liste_classique(liste l) {
    liste p = l;

    while (!est_liste_vide(p)) {
        printf("%d ", p->objet);
        p = p->suivant;
    }
    printf("\n");

}
