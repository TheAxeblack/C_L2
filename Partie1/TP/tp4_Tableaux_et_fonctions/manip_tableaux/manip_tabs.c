#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25

void remplir_tab_alea(int t[], int n) {
    int i = 0;
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

int minimum(int t[], int n) {
    int i;
    int mini;

    i = 0;
    mini = t[0];
    while (i < n) {
        if (mini > t[i])
            mini = t[i];
        i++;
    }
    printf("La valeur minimale de t est : %d\n", mini);
    return mini;
}

int maximum(int t[], int n) {
    int i;
    int maxi;

    i = 0;
    maxi = t[0];
    while (i < n) {
        if (maxi < t[i])
            maxi = t[i];
        i++;
    }
    printf("La valeur maximale de t est : %d\n", maxi);
    return maxi;
}

double moyenne(int t[], int n) {
    double res;
    int i;

    res = 0;
    i = 0;
    while (i < n) {
        res += t[i];
        i++;
    }
    res = res / n;
    printf("La moyenne des valeurs de t est : %f\n", res);
    return res;
}

void remplir_tab2(int t[], int t2[], int n) {
    int i;
    int j;

    i = n - 1;
    j = 0;
    while (i >= 0) {
        t[i] = t2[j];
        i--;
        j++;
    }
}

void remplir_tab3(int t[], int t2[], int n) {
    int i;

    i = 0;
    while (i < n) {
        t[i] = t2[i] % 4;
        i++;
    }
}

int compte_zero(int t[], int n) {
    int i;
    int acc;

    i = 0;
    acc = 0;
    while (i < n) {
        if (t[i] == 0)
            acc++;
        i++;
    }
    printf("Il y a %d zero", acc);
    if (acc != 0)
        printf("s dans t3\n");
    else
        printf(" dans t3\n");
    return acc;
}

int remplir_tpair(int t[], int t2[], int n) {
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < n) {
        if (t2[j] % 2 == 0) {
            t[i] = t2[j];
            i++;
            j++;
        } else
            j++;
    }
    return i;
}

int main(void) {
    int t1[N];
    int t2[N];
    int t3[N];
    int tpair[N];

    remplir_tab_alea(t1, N);
    afficher_tab(t1, N);
    minimum(t1, N);
    maximum(t1, N);
    moyenne(t1, N);
    remplir_tab2(t2, t1, N);
    afficher_tab(t2, N);
    remplir_tab3(t3, t2, N);
    afficher_tab(t3, N);
    compte_zero(t3, N);
    afficher_tab(tpair, remplir_tpair(tpair, t3, N));
    exit(EXIT_SUCCESS);
}
