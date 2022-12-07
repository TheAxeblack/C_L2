#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ft_deg2(void)
{
    float a;
    float b;
    float c;
    float delta;
    float x1;
    float x2;
    float x0;

    a = 0;
    b = 0;
    c = 0;
    printf("Please enter 3 float\n");
    if (scanf("%f %f %f", &a, &b, &c) != 3)
        printf("Error. You don't have the right amount of arguments.\nRemind: you need 3.\n");
    else
    {
        delta = (b * b) - 4 * a * c;
        printf("Delta = %lf\n", delta);
        if (delta > 0)
        {
            x1 = (-b - sqrt(delta)) / 2 * a;
            x2 = (-b + sqrt(delta)) / 2 * a;
            printf("x1= %lf\nx2 = %lf\n", x1, x2);
        }
        else if (delta == 0)
        {
            x0 = (-b) / 2 * a;
            printf("La racine reelle est : x0 = %f\n", x0);
        }
        else
            printf("Pas de racines reelles\n");
    }
}

int main(void)
{
    ft_deg2();
    exit(0);
}