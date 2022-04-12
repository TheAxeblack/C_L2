#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *cpy_tableau(int *tab, int taille) {
    int i;
    int *copie = NULL;
    copie = (int *) malloc((taille + 2) * sizeof(int));
    assert(copie != NULL);
    copie[0] = taille;
    for (i = 0; i < taille; i++) {
        copie[1] += tab[i];
        copie[i + 2] = tab[i];
    }
    return copie;
}

int main(void) {
    int i;
    int tab[6] = {1, 42, 52, 30, 4, 8};
    int *res;
    res = cpy_tableau(tab, 6);
    for (i = 0; i < 8; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}