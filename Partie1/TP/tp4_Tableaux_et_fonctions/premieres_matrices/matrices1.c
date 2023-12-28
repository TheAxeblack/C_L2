#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MAX 100
#define N 10


void remplissage(int n, float m[][NB_MAX]) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = rand() / (float) RAND_MAX * (25 - 10);
        }
    }
}

void affichage(int n, float m[][NB_MAX]) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fprintf(stdout, "%f ", m[i][j]);
        }
        fprintf(stdout, "\n");
    }
}

void remplissage_tri_inf(int n, float m[][NB_MAX]) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i < j)
                m[i][j] = 0;
            else
                m[i][j] = rand() / (float) RAND_MAX * (25 - 10);
        }
    }
}

int tri_inf(int n, float m[][NB_MAX]) {
    int i;
    int j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (m[i][j] != 0)
                return (0);
        }
    }
    return (1);
}

void remplissage_tri_sup(int n, float m[][NB_MAX]) {
    int i;
    int j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j)
                m[i][j] = 0;
            else
                m[i][j] = rand() / (float) RAND_MAX * (25 - 10);
        }
    }
}

int tri_sup(int n, float m[][NB_MAX]) {
    int i;
    int j;
    for (j = 0; j < n - 1; j++) {
        for (i = j + 1; i < n; i++) {
            if (m[i][j] != 0)
                return (0);
            else i++;
        }
    }
    return (1);
}

int main(void) {
    float m[NB_MAX][NB_MAX];
    int n = N;

    srand(time(NULL));
    /* remplissage(n, m);
       affichage(n, m);*/
    remplissage_tri_sup(n, m);
    affichage(n, m);
    if (tri_inf(n, m))
        fprintf(stdout, "La matrice est triangulaire inferieure\n");
    else
        fprintf(stdout, "La matrice est triangulaire superieure\n");
    if (tri_sup(n, m))
        fprintf(stdout, "La matrice est triangulaire superieure\n");
    else
        fprintf(stdout, "La matrice est triangulaire inferieure\n");
    exit(EXIT_SUCCESS);
}
