#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom) {
    printf("usage %s : <reel>\n", nom);
}

int main(int argc, char **argv) {
    int n;
    double x;
    double res;

    n = 2;
    if (argc != 2) {
        ft_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        x = atof(argv[1]);
        res = x;
        while (n <= 10) {
            res *= x;
            printf("%f^%d = %f\n", x, n, res);
            n++;
        }
    }
    exit(EXIT_SUCCESS);
}
