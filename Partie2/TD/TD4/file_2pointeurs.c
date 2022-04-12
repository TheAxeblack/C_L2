/**
 *fichier d'implementation d'une file avec 2 pointeurs de liste, 
 *un pointeur pour le debut de liste, un pour la fin
 *
 * hist A. Habrard
 *  creation le 23/03/2015
 *  modif le 29/02/2016
 */

#include <stdio.h>
#include "file_2pointeurs.h"
#include "allocation.h"


/*creation d'une file vide*/
file file_vide() {
    file f = (file) allocation_mem(1, sizeof(cell_file));
    f->debut = liste_vide();
    f->fin = liste_vide();
    return f;
}

/*test pour savoir si une file est vide*/
int est_file_vide(file f) {
    return (est_liste_vide(f->debut) && est_liste_vide(f->fin));
}

/*renvoie le premier element en debut de file*/
element debut_file(file f) {
    return renvoie_premier_liste(f->debut);
}


/*renvoie le nombre d'elements dans la file*/
int taille_file(file f) {
    int nb = 0;
    liste lcourant = f->debut;

    while (lcourant) {
        nb++;
        lcourant = lcourant->suivant;
    }

    return nb;
}

/*supprimer l'element en tete de file et le renvoie*/
element defiler_av_element(file f) {
    element e; /*element a renvoyer */

    if (est_file_vide(f)) /*on est oblige de faire un cas particulier pour la liste vide ! */
        return ELEMENT_VIDE;

    e = f->debut->objet;

    f->debut = supprimer_premier_liste(f->debut);

    if (est_liste_vide(f->debut))
        f->fin = liste_vide();

    return e;
}

/*supprimer l'element en tete de file */
void defiler(file f) {
    if (!est_file_vide(f)) {
        f->debut = supprimer_premier_liste(f->debut);

        if (est_liste_vide(f->debut))
            f->fin = liste_vide();
    }
}


/*ajout d'une element dans la file*/
void enfiler(file f, element e) {
    liste lnew = insere_element_liste(liste_vide(), e);

    if (est_file_vide(f))
        f->debut = lnew;
    else f->fin->suivant = lnew;
    f->fin = lnew;
}

/*affichage du contenu de la file*/
void affiche_file(file f) {
    affiche_liste(f->debut);
}
