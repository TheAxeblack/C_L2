#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int **creer_mat_rectangulaire(int n, int m);

int **creer_mat_carree(int n);

int **cpy_mat(int **mat);

int **add_mat(int **mat1, int **mat2);

void aff_mat(int **mat);

int main(void) {
    int **mat1;
    mat1 = creer_mat_rectangulaire(2, 3);

    return 0;
}

int **creer_mat_rectangulaire(int n, int m) {
    int i;
    int **mat;
    mat = (int **) malloc(n * sizeof(int *));
    assert(mat != NULL);
    for (i = 0; i < n; i++) {
        mat[i] = (int *) calloc(m, sizeof(int));
        assert(mat[i] != NULL);
    }
    return mat;
}