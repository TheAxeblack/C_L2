#include <stdio.h>
#include <stdlib.h>

#define NB_MAX 2048

int main(void) {
    int t[NB_MAX];
    int n;
    int e;
    int i;
    int j;

    n = 0;
    fprintf(stdout, "Entrer des entiers separes par 1 saut de ligne\n");
    fprintf(stdout, "Entrer un entier negatif pour arreter\n");
    while (n < NB_MAX && fscanf(stdin, "%d", &e) == 1) {
        if (e >= 0) {
            i = 0;
            while (i < n && e > t[i])
                i++;
            for (j = n; j > i; j--)
                t[j] = t[j - 1];
            t[i] = e;
            n++;
        } else
            break;
    }
    fprintf(stdout, "Les entiers rentres tries sont\n");
    for (i = 0; i < n; i++)
        fprintf(stdout, "%d ", t[i]);
    fprintf(stdout, "\n");
    exit(EXIT_SUCCESS);
}
