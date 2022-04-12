/**
 *fichier de definition du module TAD matrice
 *
 *on suppose ici des matrices avec des doubles
 *
 *La matrice est encapsulée dans une structure, cf fichier en-tete
 *
 *hist A. Habrard
 * creation le 10/03/2015
 * modif 01/03/2016
 * modif 25/03/2019 : correction bug multiplication
 */

#include <stdio.h>
#include <assert.h>
#include "matrice.h"


/*fonction de création de matrices */
matrice creer_matrice(int l, int c) {
    int i;

    matrice m = (matrice) allocation_mem(1, sizeof(cell_matrice));/*//allocation de la matrice*/
    m->l = l;
    m->c = c;

    m->tab = (double **) allocation_mem(l, sizeof(double *)); /*//allocation des lignes*/
    for (i = 0; i < l; i++)
        m->tab[i] = (double *) allocation_mem(c, sizeof(double)); /*//allocation des colonnes*/

    return m;
}


/*fonction de récupération de l'element a la position [i,j] dans m*/
double get_element_matrice(matrice m, int i, int j) {
    assert(0 <= i && i < m->l && 0 <= j && j < m->c); /*//verification de la positions*/
    return m->tab[i][j];
}

/*on fixe l'element a la position [i,j] dans m à la valeur val*/
void set_element_matrice(matrice m, int i, int j, double val) {
    assert(0 <= i && i < m->l && 0 <= j && j < m->c); /*//verification de la position*/
    m->tab[i][j] = val;
}

/*mutiplie les entrées de la matrice par le scalaire val*/
void multiplie_scalaire(matrice m, double val) {
    int i, j;

    for (i = 0; i < m->l; i++)
        for (j = 0; j < m->c; j++)
            m->tab[i][j] *= val;
}

/*somme de 2 matrices*/
matrice somme_matrices(matrice mat1, matrice mat2) {
    int i, j;
    matrice res;

    assert(mat1->l == mat2->l && mat1->c == mat2->c);/*//verification des dimensions*/

    res = creer_matrice(mat1->l, mat1->c);/*//allocation matrice resultat*/

    /*//calcul de la somme*/
    for (i = 0; i < mat1->l; i++)
        for (j = 0; j < mat1->c; j++)
            res->tab[i][j] = mat1->tab[i][j] + mat2->tab[i][j];

    return res;
}

/*multiplication de 2 matrices*/
matrice multiplication_matrices(matrice mat1, matrice mat2) {
    int i, j, k;
    matrice res;

    assert(mat1->c == mat2->l);/*//verification de dimension*/

    res = creer_matrice(mat1->l, mat2->c); /*//allocation de la matrice resultat*/

    /*//calcul du produit*/
    for (i = 0; i < mat1->l; i++)
        for (j = 0; j < mat2->c; j++) {
            res->tab[i][j] = 0;
            for (k = 0; k < mat2->l; k++)
                res->tab[i][j] += mat1->tab[i][k] * mat2->tab[k][j];
        }

    return res;
}


/*affichage d'une matrice*/
void affiche_matrice(matrice m) {
    int i, j;

    for (i = 0; i < m->l; i++) {
        for (j = 0; j < m->c; j++)
            printf("%f ", m->tab[i][j]);
        printf("\n");
    }
}
