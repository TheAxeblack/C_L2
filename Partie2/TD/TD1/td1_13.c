/**
 * Programme affichant un triangle isoc�le
 * 
 * Version utilisant une fonction pour l'erreur (on voit l'int�r�t de
 * la compilation separ�e ici) et une fonction l'affichage
 *
 * historique: 
 *  creation le 23/01/2014 - A. Habrard
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/*declaration des fonctions*/
void mon_erreur(char *format, ...);

void affiche_triangle_isocele(int nb_lignes);


/*definitions fonctions*/

/*----
 * fonction definissant un message d'erreur,et affiche 'format',
 * peut prendre plusieurs args pour l'affichage de format
 */

void mon_erreur(char *format, ...) {
    va_list arg;

    va_start(arg, format);

    fprintf(stderr, "Erreur - ");

    vfprintf(stderr, format, arg);/*affichage de la chaine format*/

    va_end(arg);

    exit(EXIT_FAILURE);/*on sort de l'application, on utilise exit ici*/
}


/* ---- 
 * Fonction de rendu de monaie
 */
void affiche_triangle_isocele(int nb_lignes) {
    int i; //compteur
    int milieu = nb_lignes - 1; //milieu du triangle
    int nb_etoiles = 0, nb_espaces = 0; //nb etoiles, espaces

    for (i = 0; i < nb_lignes; i++) {
        int j;//computeur

        nb_etoiles = 2 * i + 1;
        nb_espaces = milieu - i;

        //affichage des espaces
        for (j = 0; j < nb_espaces; j++)
            printf(" ");

        //affichage des etoiles
        for (j = 0; j < nb_etoiles; j++)
            printf("*");

        printf("\n");
    }
}

/*fonction main*/
int main(int argc, char *argv[]) {
    int nb_lignes;

    if (argc != 2)
        mon_erreur(
                "usage : %s nb_lignes\n\tnb_lignes: entier >=0\n\tle programme affiche un triangle isocele sur nb_lignes lignes\n",
                argv[0]);

    nb_lignes = atoi(argv[1]);

    if (nb_lignes < 0)
        mon_erreur(
                "Valeur negative\n\tusage : %s nb_lignes\n\tnb_lignes: entier >=0\n\tle programme affiche un triangle isocele sur nb_lignes lignes\n",
                argv[0]);

    affiche_triangle_isocele(nb_lignes);

    return EXIT_SUCCESS;
}
