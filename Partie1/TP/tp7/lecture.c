#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"

int stockage(tab t)
{
    int i;
    FILE *fichier = NULL;

    i = 0;
    fichier = fopen("../tp7/athlete.txt", "r");
    if (fichier == NULL)
    {
        printf("Vous tenter d'ouvrir un fichier inexistant\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fichier, "%d %s %s", &t[i].numero, t[i].prenom, t[i].nom) == 3)
    {
        i++;
    }
    fclose(fichier);
    return i;
}

void afficher_tab(int i, tab t)
{
    int j;
    for (j = 0; j < i; j++)
        printf("%d %s %s\n", t[j].numero, t[j].nom, t[j].prenom);
}