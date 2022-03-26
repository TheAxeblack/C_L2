#include "allocation.h"
#include "tp2.h"
#include <assert.h>
#include <string.h>


void creer_tab(int taille) {
    char *tableau = NULL, *p;
    int i;
    tableau = (char *) malloc(taille * sizeof(char));
    assert(tableau != NULL);
    p = tableau;
    for (i = 0; i <= taille; i++) {
        p[i] = (rand() % ('~' - '!' + 1)) + '!';
    }

    /* Affichage du tableau de gauche à droite */
    fprintf(stdout, "Tableau de gauche à droite [");
    for (p = tableau, i = 0; i < taille; p++, i++) {
        fprintf(stdout, " %c ", *p);
    }
    fprintf(stdout, "]\n");


    /* Affichage du tableau de droite à gauche */
    fprintf(stdout, "Tableau de droite à gauche [");
    for (p = tableau + (taille - 1), i = taille; i > 0; p--, i--) {
        fprintf(stdout, " %c ", *p);
    }
    fprintf(stdout, "]\n");

    assert(tableau != NULL);
    free(tableau);
}

