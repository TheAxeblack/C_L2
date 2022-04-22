#include "../inc/postfixe_inversee.h"

arbre creer_arbre_expression(char *expression, int *position) {
    arbre a, b, droite, gauche;
    a = b = droite = gauche = creer_arbre_vide();

    if (expression[*position] == '\0')
        return a;
    if (expression[*position] == '+' || expression[*position] == '*' || expression[*position] == '-' ||
        expression[*position] == '/') {
        a = creer_arbre(expression[*position], NULL, NULL);
        *position += 1;
        gauche = creer_arbre_expression(expression, position);
        a = inserer_fils_gauche(a, gauche);
        droite = creer_arbre_expression(expression, position);
        a = inserer_fils_droit(a, droite);
    } else if (expression[*position] >= '0' && expression[*position] <= '9') {
        b = creer_noeud(expression[*position]);
        *position += 1;
        return b;
    }
    return a;
}

int eval(arbre a) {
    if (est_vide(a))
        return 0;
    if (a->noeud >= '0' && a->noeud <= '9')
        return a->noeud - '0';
    else {
        int evalg = eval(a->gauche);
        int evald = eval(a->droit);
        switch (a->noeud) {
            case '+':
                return evalg + evald;
            case '-':
                return evalg - evald;
            case '*':
                return evalg * evald;
            case '/':
                return evalg / evald;
            default:
                fprintf(stderr, "L'operateur n'est pas present dans la liste\n");
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}