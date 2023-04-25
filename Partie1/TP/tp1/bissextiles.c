#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a;

    printf("Entrez une année : \n");
    if (scanf("%d", &a) != 1) {
        printf("Erreur. Vous n'avez pas renseigner le bon nombre de parametres !\n");
        exit(-1);
    } else if (a < 0) {
        printf("Une annee ne peut pas etre negative.\n");
        exit(-1);
    } else {
        if ((a > 0) && (((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0)))
            printf("L\'annee %d est une annee bissextile\n", a);
        else
            printf("L'annee %d n'est pas une annee bissextile\n", a);
    }
    exit(0);
}
