#include <stdio.h>
#include <stdlib.h>
#include "types.h"

tablette creer_tablette(int n, int m)
{
    int i;
    int j;
    tablette t;

    t.n = n;
    t.m = m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            t.terrain[i][j] = 1;
        }
    }
    return t;
}

void manger(tablette *t, int x, int y)
{
    int i, j, n, m;

    n = t->n;
    m = t->m;
    for (i = x; i < n; i++)
    {
        for (j = y; j < m; j++)
        {
            t->terrain[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", t->terrain[i][j]);
        }
        printf("\n");
    }
}

int est_legal(configuration *config, coup *cp)
{
    int c, y;
    tablette t;

    c = cp->c;
    y = cp->y;
    t = config->tab;

    if (t.terrain[c][y] == 0)
        return 0;
    return 1;
}

int est_finie(configuration *config, joueur *gagnant)
{
    tablette t;

    t = config->tab.terrain;
    if (t.terrain[0][0] == 0)
    {
        return 1;
    }
    return 0;
}

void jouer_coup(configuration *config, coup *cp)
{
    tablette t;
    t = config->tab;

    if (est_legal(config, cp) == 1)
    {
        manger(&t, cp->c, cp->y);
        if (config->j == J1)
            config->j = J2;
        else if (config->j == J2)
            config->j = J1;
    }
    else
    {
        printf("Erreur le coup que vous souhaitez jouer n'est pas valide\n");
    }
}

int main(void)
{
    tablette tablette1;
    tablette *pointeurtablette;
    configuration *config;
    joueur j;
    tablette1 = creer_tablette(2, 5);
    pointeurtablette = &tablette1;
    j
        config->tab = tablette1;
    config->j = j;
    while (est_finie(config, j))
        manger(pointeurtablette, 0, 2);
    exit(EXIT_SUCCESS);
}
