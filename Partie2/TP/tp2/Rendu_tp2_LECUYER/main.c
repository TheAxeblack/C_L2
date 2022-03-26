#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp2.h"


int main(int argc, char **argv) {
    int x;
    /*srand(time(NULL));
    fprintf(stdout,
            "Fonction pour l'exercice 3 : Affichage d'un tableau de gauche a droite puis de droite a gauche.\n");
    creer_tab(5);
    fprintf(stdout, "\nFonction pour le triangle de Pascal.\n");*/
    if (argc != 2 || (atoi(argv[1]) <= 0)) {
        fprintf(stderr,
                "Usage %s: <entier_positif_non_nul>\nAffiche le triangle de Pascal de taille <entier_positif_non_nul>\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
    x = atoi(argv[1]);
    pascal(x);
    exit(EXIT_SUCCESS);
}