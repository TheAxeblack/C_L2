#include "../inc/class.h"

int main(void) {
    STRING ch1, ch2;
    student c1, c2;
    PtrStudent p1, p2;
    student classe[20];

    /* 1. */
    p1->name[1]; /* 2eme caractère du champ name de p1 */
    p2->firstname[0]; /* 1er caractère du champ firstname de p2 */
    c1.name[3]; /* 4eme caractère du champ name de c1 */
    c2.firstname[2]; /* 3eme caractère du champ firstname de c2 */
    &(classe[2].name[3]) - &ch2[1];  /* Soustraction entre @ du 4eme caractère de name de l'élément en 3eme position dans le tableau d'étudiant et @ du 2eme caractère de ch2 */

    /* 2. */
    c1 = c2; /* c1 prend la valeur de c2 */
    c2.name[4] = c1.name[5]; /* le 5eme caractère du champ name de c2 prend la valeur du 6eme caractère du champ name de c1 */
    strcpy(c2.name, c1.name); /* Le champ name de c1 est copié dans le champ champ name de c2 */
    strcpy(c2.firstname, ch2); /* Le tableau de caractère ch2 est copié dans le champ firstname de c2*/
    classe[2].id++;
    exit(EXIT_SUCCESS);
}
