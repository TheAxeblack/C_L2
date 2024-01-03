#include <stdio.h>
#include <stdlib.h>

#define DEUX 75
#define TROIS 100
#define DEJ 15
#define DINER 35

typedef struct
{
    char prenom[50], nom[50];
    int hotel;      /* 2 ou 3 étoiles */
    int accompagne; /* 1 si accompagné, 0 sinon */
    int dej;        /* 1 si déjeuner, 0 sinon */
    int diner;      /* 1 si diner, 0 sinon */
} participant;

typedef participant tabPart[100];

void nb2etoiles(tabPart t, int nb_part)
{
    int i;

    for (i = 0; i < nb_part; i++)
    {
        if (t[i].hotel == 2)
        {
            printf("%s %s\n", t[i].prenom, t[i].nom);
        }
    }
}

int nbDej(tabPart t, int nb_part)
{
    int i, nb = 0;

    for (i = 0; i < nb_part; i++)
    {
        if (t[i].dej == 1)
        {
            if (t[i].accompagne == 1)
                nb++;
            nb++;
        }
    }

    return nb;
}

int montant(participant p) {
    int total = 0;

    if (p.hotel == 2)
        total += DEUX;
    else
        total += TROIS;

    if (p.accompagne == 1)
        total += (2 * DEJ * p.dej);
    else
        total += (DEJ * p.dej);
    
    /* TODO: a finir */
}