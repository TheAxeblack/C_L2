/*
 *Fichier main de test pour pile_tableau.c
 *
 *
 *hist A. Habrard, le 24/03/2014
 *   modification le 25/03/2015
 *                le 01/03/2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "pile_tableau.h"

/* exemple de main, vous pouvez afficher plus de messages pour voir ce qui se passe*/

int main() {
    objet x;
    pile p = creer_pile(3);

    empiler(p, 1);
    empiler(p, 2);
    empiler(p, 3);
    empiler(p, 4);

    x = depiler(p);
    printf("%d\n", x);
    empiler(p, 5);
    x = depiler(p);
    printf("%d\n", x);
    x = depiler(p);
    printf("%d\n", x);
    x = depiler(p);
    printf("%d\n", x);
    x = depiler(p);
    printf("%d\n", x);

    return EXIT_SUCCESS;
}

