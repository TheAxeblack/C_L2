#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom) {
    printf("Usage %s : <entier>\n", nom);
}

int main(int argc, char **argv) {
    int n;
    int i;

    n = 0;
    i = 0;
    if (argc != 2) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        n = atoi(argv[1]);
        while (i < n) {
            printf("*");
            i++;
        }
        printf("\n");
    }
    exit(EXIT_SUCCESS);
}
