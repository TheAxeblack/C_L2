#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MAX 1024
#define N 25


void renversement(int n, int *t) {
    int i;
    int tmp;
    int limit;

    i = 0;
    limit = n / 2;
    while (i < limit) {
        tmp = t[(n - 1) - i];
        t[(n - 1) - i] = t[i];
        t[i] = tmp;
        i++;
    }
}

void decallage(int n, int *t, char dir) {
    int i;
    int tmp;

    if (dir == 'g') {
        tmp = t[0];
        i = 0;
        while (i < n - 1) {
            t[i] = t[i + 1];
            i++;
        }
        t[n - 1] = tmp;
    } else {
        tmp = t[n - 1];
        i = n - 1;
        while (i > 0) {
            t[i] = t[i - 1];
            i--;
        }
        t[0] = tmp;
    }
}

void permutCirculaire(int n, int *t, int k) {
    int i;
    int t_tmp[NB_MAX];

    i = 0;
    while (i < n) {
        t_tmp[(i + k) % n] = t[i];
        i++;
    }
    i = 0;
    while (i < n) {
        t[i] = t_tmp[i];
        i++;
    }
}

/* Fonctions de l'exercice precedent */

void remplir_tab_alea(int t[], int n) {
    int i;

    i = 0;
    srand(time(NULL));
    while (i < n) {
        t[i] = (rand() % (15 - (-15) + 1)) + (-15);
        i++;
    }
}

void afficher_tab(int t[], int n) {
    int i;

    i = 0;;
    while (i < n) {
        if (i > (n - 2) && i <= (n - 1))
            printf("%d", t[i]);
        else
            printf("%d ", t[i]);
        i++;
    }
    printf("\n");
}

int main(void) {
    int t4[N];

    remplir_tab_alea(t4, N);
    afficher_tab(t4, N);
    renversement(N, t4);
    afficher_tab(t4, N);
    decallage(N, t4, 'g');
    afficher_tab(t4, N);
    permutCirculaire(N, t4, 5);
    afficher_tab(t4, N);
    exit(EXIT_SUCCESS);
}
