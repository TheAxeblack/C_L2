#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NB_MAX 1024

void ft_usage(char *nom) {
    fprintf(stderr, "Usage %s: <entier1> <entier2>, <entier1> > 0, <entier2> < 10", nom);
}

void to_base_b(int n, int b) {
    int x;
    int i;
    int taille;
    int t[NB_MAX];

    x = 0;
    i = 0;
    taille = 0;
    while (n != 0) {
        x = n % b;
        n = n / b;
        t[i] = x;
        i++;
        taille++;
    }
    for (i = taille - 1; i >= 0; i--)
        fprintf(stdout, "%d", t[i]);
    fprintf(stdout, "\n");
}

void to_base_10(void) {
    int b;
    int i;
    int t[8];
    int n;
    int j;
    fprintf(stdout, "Veuillez choisir une base de depart\n");
    if (fscanf(stdin, "%d", &b) != 1 || b > 10) {
        fprintf(stderr,
                "Erreur vous n'avez pas renseigner le bon nombre d'arguments ou l'argument choisi est trop grand. Vous ne devez en rentrer qu'un seul.\n");
        exit(EXIT_FAILURE);
    } else {
        n = 0;
        /* Remplissage du tableau */
        for (i = 0; i < 8; i++) {
            t[i] = rand() % b;
            fprintf(stdout, "%d ", t[i]);
        }
        fprintf(stdout, "\n");

        /* Calcul de n */
        for (i = 7, j = 0; i >= 0; i--, j++)
            n += (t[i] * pow(b, j));
        fprintf(stdout, "n = %d\n", n);
    }
}

int main(int argc, char **argv) {
    if (argc != 3 || atoi(argv[1]) < 0 || atoi(argv[2]) > 10) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        int n;
        int b;

        n = atoi(argv[1]);
        b = atoi(argv[2]);
        srand(time(NULL));
        to_base_b(n, b);
        to_base_10();
    }
    exit(EXIT_SUCCESS);
}