#include "../inc/arbre_binaire.h"

int main(void) {
    arbre a, b, c, d, e, f, g, h, i;
    a = b = c = d = e = f = g = h = i = creer_arbre_vide();

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
    exit(EXIT_SUCCESS);
}