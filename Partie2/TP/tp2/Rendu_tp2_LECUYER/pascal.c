#include "allocation.h"
#include "tp2.h"
#include <assert.h>

void pascal(int x) {
    int i, j;
    int **tableau;


    tableau = (int **) malloc(x * sizeof(int *));
    assert(tableau != NULL);
    for (i = 0; i <= x; i++) {
        tableau[i] = (int *) malloc((i + 1) * sizeof(int));
        assert(tableau[i] != NULL);
    }

    /* Initialisation à 0 */
    for (i = 0; i < x; i++)
        for (j = 0; j <= x; j++)
            tableau[i][j] = 0;


    /* Attribution des valeurs */
    for (i = 0; i < x; i++) {
        for (j = 0; j <= i; j++) {
            if (i == 0 || j == 0)
                tableau[i][j] = 1;
            else
                tableau[i][j] = tableau[i - 1][j - 1] + tableau[i - 1][j];
        }
    }

    /* Affichage du triangle de Pascal */
    for (i = 0; i < x; i++) {
        for (j = 0; j < i + 1; j++) {
            fprintf(stdout, "%d ", tableau[i][j]);
        }
        fprintf(stdout, "\n");
    }

    assert(tableau != NULL);
    free(tableau);
    tableau = NULL;
}