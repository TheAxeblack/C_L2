#include <stdio.h>
#include <string.h>
#include "lecture.h"

int recherche_sequentielle(char *nom, int nb, tab t)
{
    int i;
    int compt;

    compt = 0;
    for (i = 0; i <= nb; i++)
    {
        compt++;
        if (strcmp(nom, t[i].nom) == 0)
        {
            printf("%s %s\n", t[i].nom, t[i].prenom);
            printf("Nombre de comparaisons effectuees : %d\n", compt);
            return 0;
        }
    }
    printf("Vous essayer de trouver quelqu'un qui n'est pas present dans la liste\n");
    return 1;
}

int recherche_dichotomique(char *nom, int nb, tab t)
{
    int i;
    int m;
    int f;
    int compt;

    i = 0;
    f = nb;
    compt = 0;
    while (i <= nb)
    {
        m = (f + i) / 2;
        compt++;
        if (strcmp(t[m].nom, nom) == 0)
        {
            printf("%s %s\n", t[m].nom, t[m].prenom);
            printf("Nombre de comparaisons effectuees : %d\n", compt);
            return 0;
        }
        else
        {
            if (strcmp(t[m].nom, nom) < 0)
                i = m + 1;
            else
                f = m - 1;
        }
    }
    printf("La valeur que vous cherchez n'est pas dans la liste\n");
    return 1;
}