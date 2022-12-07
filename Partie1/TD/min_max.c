#include <stdio.h>
#include <stdlib.h>

int question(void)
{
    int x;
    printf("How much numbers?\n");
    if (scanf("%d", &x) != 1)
    {
        printf("Error\n");
        return (1);
    }
    else
    {
        return (x);
    }
}

int main(void)
{
    int i;
    int x;
    int mini;
    int maxi;
    int tmp;
    x = question();
    i = 0;
    while (i <= x)
    {
        printf("Entrer un entier\n")
    }
}