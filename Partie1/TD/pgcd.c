#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom)
{
    printf("usage %s : <entier1> <entier2>\n", nom);
}

int main(int argc, char **argv)
{
    int entier1;
    int entier2;
    int res;

    if (argc != 3)
    {
        ft_usage(argv[0]);
        exit(-1);
    }
    else
    {
        entier1 = atoi(argv[1]);
        entier2 = atoi(argv[2]);
        res = entier1 % entier2;
        while (res != 0)
        {
            res = entier1 % entier2;
            entier1 = entier2;
            entier2 = res;
        }
        printf("pgcd(%s, %s) = %d", argv[1], argv[2], res);
    }
    exit(0);
}
