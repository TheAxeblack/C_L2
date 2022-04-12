/*
 *Exemple d'implementation de file avec un tableau
 *
 *pour plus de g�n�ricit� et de portabilit�, la file
 *est mise dans une structure, ca permet d'avoir
 *acces a la taille et a la dimension ainsi qu'aux indices 
 *de debut,fin,
 *
 *comme pour les piles, une autre solution pourrait etre
 *de creer une file en declarant un tableau global en associant
 *toutes les variables aussi declarees en globale, mais c'est
 *moins reutilisable facilement sous forme de bibliotheque
 *
 *
 *hist A. Habrard, le 24/03/2014
 *   modification le 25/03/2015
 *   le 16/03/2016
 *   le 21/04/2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_tableau.h"


/* ------------------------------ */


/*petite fonction qui calcule l'indice suivant, de mani�re circulaire*/
/*elle revient � caculer un modulo i%dimension_file */
int calcule_suivant_file(file f, int i) {
    if (i < f->dimension_file - 1)
        return i + 1;

    return 0;
}


/* creation d'une file*/
file creer_file(int dim) {
    file f = (file) malloc(1 * sizeof(file_struct));

    if (f == NULL) {
        fprintf(stderr, "Erreur creation file\n");
        exit(EXIT_FAILURE);
    }

    f->tab = (objet *) calloc(dim, sizeof(objet));
    if (f->tab == NULL) {
        fprintf(stderr, "Erreur creation file\n");
        exit(EXIT_FAILURE);
    }

    f->dimension_file = dim;
    f->debut = 0;
    f->fin = 0;
    f->taille = 0;

    return f;
}

/* test de file vide */
int est_file_vide(file f) {
    return (f->taille == 0);
}

/* test file pleine */
int est_file_pleine(file f) {
    return (f->taille == f->dimension_file);
}

/* tete de file */
objet tete_file(file f) {
    if (!est_file_vide(f))
        return f->tab[f->debut];
    return -1; /* ou erreur */
}

/* enfiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la file) */
int enfiler(file f, objet x) {
    if (!est_file_pleine(f)) {
        f->tab[f->fin] = x;
        f->fin = calcule_suivant_file(f, f->fin);
        f->taille++;
        return (1);
    }

    fprintf(stderr, "file saturee\n");
    return (0);
}


/* defilement d'un objet */
objet defiler(file f) {
    objet x;
    if (!est_file_vide(f)) {
        x = f->tab[f->debut];
        f->debut = calcule_suivant_file(f, f->debut);
        f->taille--;
        return (x);
    }

    fprintf(stderr, "file vide\n");
    return (OBJET_VIDE);
}

