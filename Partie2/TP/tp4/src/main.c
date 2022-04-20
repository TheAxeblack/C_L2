#include "../inc/usage.h"
#include "../inc/postfixe_inversee.h"
#include "../inc/dictionnaire.h"

int main(int argc, char **argv) {

    int acc = 0;
    int *position = &acc;

    int res = 0;

    arbre a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, dico;
    a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = dico = creer_arbre_vide();

    if (argc != 2)
        ft_usage(argv[0]);


    printf("Test du module arbre_binaire.c\n");

    d = creer_noeud(2 + '0');
    e = creer_noeud(5 + '0');
    g = creer_noeud(3 + '0');
    h = creer_noeud(7 + '0');
    i = creer_noeud(1 + '0');

    f = creer_arbre('*', h, i);
    c = creer_arbre('-', f, g);
    b = creer_arbre('+', d, e);
    a = creer_arbre('*', b, c);

    afficher_arbre_prefixe(a);
    printf("\nFin du test du module arbre_binaire.c\n\n--------- Test du module postfixe_inversee.c ---------\n"
           "Expression d'origine : %s\nArbre obtenu : ", argv[1]);
    j = creer_arbre_expression(argv[1], position);
    afficher_arbre_prefixe(j);
    printf("\n");
    res = eval(a);
    printf("Résultat de l'evaluation de l'arbre ");
    afficher_arbre_prefixe(a);
    printf(" = %d\n", res);
    res = 0;
    res = eval(j);
    printf("Résultat de l'evaluation de l'arbre ");
    afficher_arbre_prefixe(j);
    printf(" = %d\n", res);
    printf("Fin du test du module postfixe_inversee.c\n\n--------- Test du module dictionnaire.c ---------\n");
    a = creer_noeud('\0'); /* noeud '\0' */

    b = creer_arbre('s', a, NULL);
    b = creer_arbre('n', a, b);

    d = creer_arbre('e', a, NULL);
    d = creer_arbre('\0', NULL, d);
    d = creer_arbre('l', d, NULL);

    b = creer_arbre('i', b, d);

    h = creer_arbre('n', a, NULL);
    h = creer_arbre('o', h, NULL);

    b = creer_arbre('a', b, h);

    k = creer_arbre('t', a, NULL);
    k = creer_arbre('s', a, k);
    k = creer_arbre('o', a, k);
    k = creer_arbre('\0', NULL, k);
    k = creer_arbre('n', k, NULL);
    k = creer_arbre('o', k, NULL);
    k = creer_arbre('s', k, NULL);
    b = creer_arbre('m', b, k);
    dico = creer_arbre('_', b, NULL);
    afficher_arbre_prefixe(dico);
    exit(EXIT_SUCCESS);
}