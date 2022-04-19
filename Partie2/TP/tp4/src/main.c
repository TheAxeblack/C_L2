#include "../inc/postfixe_inversee.h"

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage %s TD4 : <expression_arithmetique>\n<expression_arithmetique> doit comporter"
                        " des operateurs ainsi que des chiffres.\nLes operateurs sont \'+\', \'*\', \'-\' \'/\'\n"
                        "Les chiffres vont de 0 a 9\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    arbre a, b, c, d, e, f, g, h, i, j;
    a = b = c = d = e = f = g = h = i = j = creer_arbre_vide();
    int acc = 0;
    int *position = &acc;

    a = b = c = d = e = f = g = h = i = j = creer_arbre_vide();

    printf("Test du module arbre_binaire.c\n%d\n", *position);

    d = creer_noeud(2 + '0');
    e = creer_noeud(5 + '0');
    g = creer_noeud(3 + '0');
    h = creer_noeud(7 + '0');
    i = creer_noeud(1 + '0');

    f = creer_arbre('*', h, i);
    c = creer_arbre('-', f, g);
    b = creer_arbre('+', d, e);
    a = creer_arbre('*', b, c);

    afficher_arbre(a);

    printf("\nFin du test du module arbre_binaire.c\nTest du module postfixe_inversee.c\n");
    j = creer_arbre_expression(argv[1], position);
    afficher_arbre(j);
    exit(EXIT_SUCCESS);
}