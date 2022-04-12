/*
 *Exemple d'implementation de file avec deux piles
 *
 *Note: !! Ce fichier utilise l'implementation de pile avec
 *tableau fournit dans un autre exercice !
 *
 *hist A. Habrard, le 24/03/2014
 * modif le 01/03/2016
 *       le 16/03/2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_av_2_piles_tableau.h"

/* ------ */
/* Declaration de fonction locale au fichier */

/*inversion des 2 piles*/
void inverser_piles(file f);

/* ------ */


/* creation d'une file*/
file creer_file(int dim) {
    file f = (file) malloc(1 * sizeof(file_struct));

    if (f == NULL) {
        fprintf(stderr, "Erreur creation file\n");
        exit(EXIT_FAILURE);
    }

    f->pile_entree = creer_pile(dim);
    f->pile_sortie = creer_pile(dim);

    return f;
}

/* test de file vide */
int est_file_vide(file f) {
    return (est_pile_vide(f->pile_entree) && est_pile_vide(f->pile_sortie));
}


/*inversion des 2 piles*/
void inverser_piles(file f) {
    objet o;
    int ok = 1;

    while (ok && !est_pile_vide(f->pile_entree)) {
        o = depiler(f->pile_entree);
        ok = empiler(f->pile_sortie, o);
    }

    /*cas où il n'y a plus de place dans la pile sortie - on remet dans la pile d'entree*/
    /*ce cas ne doit normalement pas arriver si la gestion est bien faite*/
    if (ok == 0) {
        empiler(f->pile_entree, o);
    }

}


/* enfiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la file), 0 sinon */
int enfiler(file f, objet x) {
    int ok;

    ok = empiler(f->pile_entree, x);

    if (ok == 0 && est_pile_vide(f->pile_sortie)) /* si la pile de sortie n'est pas vide, on peut pas inverser !! */
    {
        inverser_piles(f);
        ok = empiler(f->pile_entree, x);
    }

    return (ok);
}


/* defilement d'un objet */
objet defiler(file f) {
    objet x;
    if (est_pile_vide(f->pile_sortie)) {
        inverser_piles(f);
    }
    x = depiler(f->pile_sortie);


    return (x);
}



