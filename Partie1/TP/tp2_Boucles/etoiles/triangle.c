#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom) {
    printf("Usage %s : <entier_positif>\n", nom);
}

int main(int argc, char **argv) {
    int x;
    int y;
    int i;
    int h;

    y = 0;
    i = 0;
    if (argc != 2) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        h = atoi(argv[1]);
        if (h < 0) {
            ft_usage(argv[0]);
            exit(EXIT_FAILURE);
        } else {
            while (y < h) {
                x = 0;
                while (x < h) {
                    if (x <= i) {
                        printf("*");
                        x++;
                    } else {
                        printf(" ");
                        x++;
                    }
                }
                printf("\n");
                i++;
                y++;
            }
        }
    }
    exit(EXIT_FAILURE);
}
