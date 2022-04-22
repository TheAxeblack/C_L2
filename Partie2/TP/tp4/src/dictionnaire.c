#include "../inc/dictionnaire.h"

int existe_aux(dictionnaire d, char *mot, int *position) {
    if (!est_vide(d)) {
        if (d->noeud != 0 && mot[*position] != '\0') {
            if (mot[*position] == d->noeud) {
                (*position)++;
                existe_aux(d->gauche, mot, position);
            } else
                existe_aux(d->droit, mot, position);
        }
        return 1;
    }
    return 0;
}

int existe(dictionnaire d, char *mot) {
    int acc = 0;
    int *ptr = &acc;
    return existe_aux(d, mot, ptr);
}

