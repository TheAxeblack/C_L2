#include "tp3.h"

int calcul_postfixe(int taille, char **params, pile p) {
    int i, n, res = 0;
    char *b;

    if (taille < 4) {
        fprintf(stderr, "Usage %s : <entier_1> ... <entier_n> <operateur_1> ... <operateur_m>\n"
                        "Il doit y avoir au moins 4 paramètres. Le nom du programme, deux entiers et un operateur\n"
                        "Si vous souhaitez effectuer une multiplication entrez '*'.\n"
                        "Liste des opérateurs disponible : < + - * / >\n", params[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < taille; i++) {
        b = params[i];
        if (strcmp(b, "+") == 0) {
            res = sommet_pile(p);
            p = depiler(p);
            res += sommet_pile(p);
            if (!est_pile_vide(p))
                p = depiler(p);
            p = empiler(p, res);
        } else if (strcmp(b, "-") == 0) {
            res = sommet_pile(p);
            p = depiler(p);
            res -= sommet_pile(p);
            if (!est_pile_vide(p))
                p = depiler(p);
            p = empiler(p, res);
        } else if (strcmp(b, "*") == 0) {
            res = sommet_pile(p);
            p = depiler(p);
            res *= sommet_pile(p);
            if (!est_pile_vide(p))
                p = depiler(p);
            p = empiler(p, res);
        } else if (strcmp(b, "/") == 0) {
            res = sommet_pile(p);
            p = depiler(p);
            res /= sommet_pile(p);
            if (!est_pile_vide(p))
                p = depiler(p);
            p = empiler(p, res);
        } else {
            n = atoi(params[i]);
            p = empiler(p, n);
        }
    }
    return sommet_pile(p);
}