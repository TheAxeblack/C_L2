#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom) {
    printf("Usage %s : <entier1> <entier2> <entier3> <suite_d_entiers> contient entre <entier1> et <entier2>\n", nom);
}

int main(int argc, char **argv) {
    int minimum;
    int maximum;
    int n;
    int i;

    if (argc < 4) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        minimum = atoi(argv[1]);
        maximum = atoi(argv[2]);
        n = atoi(argv[3]);
        if (minimum >= maximum) {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        } else if (n < 0) {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        } else if (argc < (4 + n)) {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        } else {
            for (i = 4; i < (4 + n); i++) {
                if (atoi(argv[i]) < minimum || atoi(argv[i]) > maximum) {
                    ft_usage(argv[0]);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    exit(EXIT_SUCCESS);
}
