#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void mon_erreur(char *format, ...) {
    va_list arg;
    va_start(arg, format);
    fprintf(stderr, "Erreur - ");
    vfprintf(stderr, format, arg);
    va_end(arg);
    exit(EXIT_FAILURE);
}

void affiche_triangle_isocele(int nb_lignes) {
    int i;
    int milieu = nb_lignes - 1;
    int nb_etoiles = 0, nb_espaces = 0;

    for (i = 0; i < nb_lignes; i++) {
        int j;
        nb_etoiles = 2 * i + 1;
        nb_espaces = milieu - i;
        for (j = 0; j < nb_espaces; j++)
            printf(" ");
        for (j = 0; j < nb_etoiles; j++)
            printf("*");
        printf("\n");
    }
}

void rec_affiche_espaces(int j, int nb_espaces) {
    if (j < nb_espaces) {
        printf(" ");
        rec_affiche_espaces(j + 1, nb_espaces);
    }
}

void rec_affiche_etoiles(int j, int nb_etoiles) {
    if (j < nb_etoiles) {
        printf("*");
        rec_affiche_etoiles(j + 1, nb_etoiles);
    }
}

void rec_affiche_triangle_isocele_aux(int nb_lignes, int i) {
    if (i < nb_lignes) {
        int j = 0, k = 0;
        int nb_etoiles = 2 * i + 1;
        int nb_espaces = (nb_lignes - 1) - i;
        rec_affiche_espaces(j, nb_espaces);
        rec_affiche_etoiles(k, nb_etoiles);
        printf("\n");
        rec_affiche_triangle_isocele_aux(nb_lignes, i + 1);
    }
}


void rec_affiche_triangle_isocele(int nb_lignes) {
    int i = 0;
    rec_affiche_triangle_isocele_aux(nb_lignes, i);
}

int main(int argc, char *argv[]) {
    int nb_lignes;
    if (argc != 2) {
        mon_erreur("usage : %s nb_lignes\n\tnb_lignes: entier >=0\n\tle programme affiche un triangle isocele "
                   "sur nb_lignes lignes\n", argv[0]);
    }

    nb_lignes = atoi(argv[1]);

    if (nb_lignes < 0) {
        mon_erreur("Valeur negative\n\tusage : %s nb_lignes\n\tnb_lignes: entier >=0\n\tle programme affiche "
                   "un triangle isocele sur nb_lignes lignes\n", argv[0]);
    }

    affiche_triangle_isocele(nb_lignes);
    printf("\n\n\n");
    rec_affiche_triangle_isocele(nb_lignes);

    return EXIT_SUCCESS;
}
