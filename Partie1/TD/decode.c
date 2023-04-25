#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom);

int main(int argc, char **argv) {
    int mini;
    int maxi;
    int n;
    int i;

    if (argc < 4) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((mini = atoi(argv[1])) >= (maxi = atoi(argv[2]))) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((n = atoi(argv[3])) < 0) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc < (4 + n)) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 4; i < 4 + n; i++) {
        if (atoi(argv[i]) < mini || atoi(argv[i]) > maxi) {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}

void ft_usage(char *nom) {
    printf("usage : %s <entier1> <entier2> <entier4> <suite_d_entiers>\n<entier1> < <entier2>, <suite_d_entiers> contient <entier3> entiers entre <entier1> et <entier2>\n",
           nom);
}
