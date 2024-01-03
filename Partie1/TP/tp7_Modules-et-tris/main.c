#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"

int main(void) {
    tab tab1;
    int nbr;
    nbr = stockage(tab1);
    afficher_tab(nbr, tab1);
    recherche_sequentielle("LherMite", nbr, tab1);
    recherche_dichotomique("Zanou", nbr, tab1);
    printf("\n");
    tri_a_bulles(nbr, tab1);
    afficher_tab(nbr, tab1);
    recherche_sequentielle("LHERMITE", nbr, tab1);
    recherche_dichotomique("Zanou", nbr, tab1);
    exit(EXIT_SUCCESS);
}