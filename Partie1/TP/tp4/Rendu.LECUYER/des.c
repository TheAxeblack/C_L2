#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_MAX 601

void ft_usage(char *nom) {
    fprintf(stderr, "usage %s : <entier1> <entier2>, <entier1> > 0, <entier2> > 0", nom);
}

void lancer(int nb_des, int nb_lances, int tab_occ[]) {
    int i;
    for (i = 0; i < nb_lances; i++)
    {
        tab_occ[i] = rand() % ((6 * nb_des) - nb_des + 1) + nb_des;
        fprintf(stdout, "%d ", tab_occ[i]);
    }
    fprintf(stdout, "\n");
}


void afficher(int nb_des, int tab_occ[]) {
    int i;
    int j;
    int nb_faces;

    nb_faces = 6 * nb_des;
    for (i = nb_des; i <= nb_faces; i++) {
        fprintf(stdout, "%d ", i);
        j = 0;
        while (j < tab_occ[i])
        {
            fprintf(stdout, "*");
            j++;
        }
        fprintf(stdout, "\n");
    }
}

int main(int argc, char **argv) {
    int i;

    if (argc != 3)
    {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        int nb_des;
        int nb_lances;
        int t[NB_MAX];

        nb_des = atoi(argv[1]);
        nb_lances = atoi(argv[2]);
        srand(time(NULL));

        if (nb_des < 0 || nb_lances < 0 || nb_des > 100)
        {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            for (i = 0; i < 6 * nb_des; i++)
                t[i] = 0;

            lancer(nb_des, nb_lances, t);
            afficher(nb_des, t);
        }
    }
    exit(EXIT_SUCCESS);
}
