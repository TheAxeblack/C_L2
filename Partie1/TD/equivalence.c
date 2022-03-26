#include <stdio.h>
#include <stdlib.h>

void tq(void) {
    int i;
    i = 0;
    while (i < 10) {
        printf("Le carre de %d est : %d\n", i, i * i);
        i++;
    }
}

void f_tq(void) {
    int i;
    i = 0;
    do {
        printf("Le carre de %d est : %d\n", i, i * i);
        i++;
    } while (i < 10);
}

int main(void) {
    printf("Debut fct tq ...\n");
    tq();
    printf("\nDebut fct f_tq ...\n");
    f_tq();
    exit(0);
}