#include "tp3.h"

liste test_module_liste(liste l) {
    int elem = 0;
    liste l2 = liste_vide();
    pile p = pile_vide();
    printf("DEBUT TEST liste\n");
    l = inserer_element_liste(l, 5);
    l = inserer_element_liste(l, 12);
    l = inserer_element_liste(l, 42);
    l = inserer_element_liste(l, -12);
    elem = renvoie_premier_liste(l);
    printf("%d\n", elem);
    l = supprimer_premier_liste(l);
    elem = renvoie_premier_liste(l);
    printf("%d\n", elem);
    l2 = trouver_element(l, 42);
    printf("%d\n", renvoie_premier_liste(l2));
    printf("FIN TEST liste\nDEBUT TESTS Pile");
    p = empiler(p, 5);
    return l;
}

