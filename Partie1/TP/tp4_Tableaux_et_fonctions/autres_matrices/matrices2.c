#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MAX 100
#define N 2
#define M 3

void affichage_matrice(int matrice[][NB_MAX], int n, int m) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            fprintf(stdout, "%d ", matrice[i][j]);
        fprintf(stdout, "\n");
    }
}

void remplir_matrice(int matrice[][NB_MAX], int n, int m) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            matrice[i][j] = rand() % (100 - (-100) + 1) + (-100);
    }
}

void addition(int A[][NB_MAX], int B[][NB_MAX], int C[][NB_MAX], int n, int m) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            A[i][j] = B[i][j] + C[i][j];
    }
}

void multiplication(int A[][NB_MAX], int B[][NB_MAX], int C[][NB_MAX], int n, int m) {
    int i;
    int j;
    int k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            A[i][j] = 0;
            for (k = 0; k < m; k++)
                A[i][j] += B[i][k] * C[k][j];
        }
    }
}

void transpose(int A_tr[][NB_MAX], int A[][NB_MAX], int n, int m) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            A_tr[j][i] = A[i][j];
    }
}

int main(void) {
    int matrice1[NB_MAX][NB_MAX];
    int matrice2[NB_MAX][NB_MAX];
    int matrice3[NB_MAX][NB_MAX];
    int n = N;
    int m = M;

    srand(time(NULL));

    remplir_matrice(matrice1, n, m);
    affichage_matrice(matrice1, n, m);
    fprintf(stdout, "+\n");
    remplir_matrice(matrice2, n, m);
    affichage_matrice(matrice2, n, m);
    fprintf(stdout, "=\n");
    addition(matrice3, matrice1, matrice2, n, m);
    affichage_matrice(matrice3, n, m);
    fprintf(stdout, "\n\n");

    affichage_matrice(matrice1, n, m);
    fprintf(stdout, "*\n");
    remplir_matrice(matrice2, m, n);
    affichage_matrice(matrice2, m, n);
    fprintf(stdout, "=\n");
    multiplication(matrice3, matrice1, matrice2, n, m);
    affichage_matrice(matrice3, n, m);
    fprintf(stdout, "\n\n");

    affichage_matrice(matrice1, n, m);
    fprintf(stdout, "transpose\n");
    transpose(matrice2, matrice1, n, m);
    affichage_matrice(matrice2, m, n);
    exit(EXIT_SUCCESS);
}
