#include "../inc/postfixe_inversee.h"

arbre creer_arbre_expression(char *expression, int *position) {
    arbre a, b, droite, gauche;
    if (*expression == '+' || *expression == '*' || *expression == '-' || *expression == '/') {
        a = creer_arbre(*expression, NULL, NULL);
        *position += 1;
        gauche = creer_arbre_expression(expression++, position);
        droite = creer_arbre_expression(expression++, position);
        a->gauche = gauche;
        a->droit = droite;
        return a;
    } else if (*expression >= 48 && *expression <= 57) {
        b = creer_noeud(*expression);
        return b;
    }
}
