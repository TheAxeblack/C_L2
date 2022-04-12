/*
 *Exemple d'implementation de pile avec un tableau
 *
 *pour plus de g�n�ricit� et de portabilit�, la pile
 *est mise dans une structure
 *
 *une solution plus simple serait de d�clarer une pile
 *comme un tableau global, il faudrait alors d�clarer
 *un sommet global et la taille max (au moins sous forme
 *de constante), mais c'est un peu moins facile � r�utiliser
 *
 *Ce fichier peut ensuite �tre compl�t� avec un fichier
 *pile.h o� l'on pourrait trouver les d�clarations de fonction
 *ainsi que la d�finition de la pile
 *
 *
 *hist A. Habrard, le 24/03/2014
 *     modif le 16/03/2016
 *     maj   le 21/04/2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "pile_tableau.h"


/* creation d'une pile*/
pile creer_pile(int dim) {
    pile p = (pile) malloc(1 * sizeof(pile_struct));

    if (p == NULL) {
        fprintf(stderr, "Erreur creation pile\n");
        exit(EXIT_FAILURE);
    }

    p->tab = (objet *) calloc(dim, sizeof(objet));
    if (p->tab == NULL) {
        fprintf(stderr, "Erreur creation pile\n");
        exit(EXIT_FAILURE);
    }

    p->dimension_pile = dim;
    p->sommet = 0;

    return p;
}


/*test de pile vide */
int est_pile_vide(pile p) {
    if (p->sommet == 0)
        return 1;
    return 0;
}

/*test de pile vide */
int est_pile_pleine(pile p) {
    if (p->sommet == p->dimension_pile)
        return 1;
    return 0;
}


/* empiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la pile) */
int empiler(pile p, objet x) {
    if (p->sommet < p->dimension_pile) /* test pile non pleine -> on aurait pu utiliser la fonction du dessus */
    {
        p->tab[p->sommet] = x;
        p->sommet++;
        return (1);
    }

    fprintf(stderr, "Pile saturee\n");
    return (0);
}

/* depilement d'un objet */
objet depiler(pile p) {
    if (p->sommet > 0) /* test pile vide -> on aurait pu utiliser la fonction du dessus */
    {
        objet o = p->tab[p->sommet - 1];
        p->sommet--;
        return (o);
    }

    fprintf(stderr, "Pile vide\n");
    return (OBJET_VIDE);
}

