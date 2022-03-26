#include <string.h>
#include "lecture.h"

void tri_a_bulles(int nb, tab t) {
    int i;
    int j;
    personne tmp;
    for (i = nb; i > 0; i--) {
        for (j = 0; j < (i - 1); j++) {
            if (strcmp(t[j].nom, t[j + 1].nom) > 0) {
                tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
        }
    }
}

