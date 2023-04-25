#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom) {
    printf("Usage %s : <entier_positif>\n", nom);
}

int main(int argc, char **argv) {
    int x;
    int y;
    int M;

    x = 0;
    y = 0;
    if (argc != 2) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        M = atoi(argv[1]);
        if (M < 0) {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        } else {
            while (y < M) {
                x = 0;
                while (x < M) {
                    if (y == 0 || x == 0) {
                        printf("*");
                        x++;
                    } else if (y == (M - 1) || x == (M - 1)) {
                        printf("*");
                        x++;
                    } else {
                        printf(" ");
                        x++;
                    }
                }
                printf("\n");
                y++;
            }
        }
    }
    exit(EXIT_SUCCESS);
}
