#include "../inc/dictionnaire.h"

int existe(dictionnaire d, char *mot) {
    int i = 0;
    if ((mot[i] == d->gauche->noeud || mot[i] == d->gauche->droit->noeud) && mot[i] != '\0' && d->noeud != '0')
        i++;
    else
        return 0;
    return 1;
}

