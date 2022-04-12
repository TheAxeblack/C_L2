/**
 *fichier main pour tester le TAD matrice
 *
 * hist A. Habrard
 *  creation le 01/03/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

int main() {
    int i, j;
    matrice res1, res2;
    matrice m1 = creer_matrice(6, 7);
    matrice m2 = creer_matrice(6, 7);
    matrice m3 = creer_matrice(7, 6);

    /*on initialise les 2 matrices*/
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            set_element_matrice(m1, i, j, i * 7 + j + 1);
            set_element_matrice(m2, i, j, 6 * 7 + 1 - (i * 7 + j + 1));
        }
        for (j = 0; j < 6; j++)
            set_element_matrice(m3, i, j, 6 * 6 + 1 - (i * 6 + j + 1));
    }
    /*dernière ligne de la matrice 3*/
    for (j = 0; j < 6; j++)
        set_element_matrice(m3, 6, j, 6 * 6 + 1 - (6 * 6 + j + 1));

    printf("Affichage matrice 1\n");
    affiche_matrice(m1);
    printf("\nAffichage matrice 2\n");
    affiche_matrice(m2);
    printf("\nAffichage matrice 3\n");
    affiche_matrice(m3);

    printf("\nAffichage matrice 1, apres multiplication par scalaire 2.0\n");
    multiplie_scalaire(m1, 2.0);
    affiche_matrice(m1);

    res1 = somme_matrices(m1, m2);
    printf("\nAffichage somme matrice 1 et 2\n");
    affiche_matrice(res1);

    res2 = multiplication_matrices(m2, m3);
    printf("\nAffichage multiplication matrice 2 et 3\n");
    affiche_matrice(res2);

    return EXIT_SUCCESS;
}
