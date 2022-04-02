#include "tp3.h"

liste test_module_liste(liste l) {
    int elem = 0;
    liste l2 = liste_vide();
    printf("DEBUT TEST liste\n");
    affiche_liste(l);
    l = inserer_element_liste(l, 5);
    affiche_liste(l);
    l = inserer_element_liste(l, 12);
    affiche_liste(l);
    l = inserer_element_liste(l, 42);
    affiche_liste(l);
    l = inserer_element_liste(l, -12);
    affiche_liste(l);
    elem = renvoie_premier_liste(l);
    printf("%d\n", elem);
    l = supprimer_premier_liste(l);
    affiche_liste(l);
    elem = renvoie_premier_liste(l);
    printf("%d\n", elem);
    l2 = trouver_element(l, 42);
    printf("%d\n", renvoie_premier_liste(l2));
    affiche_liste(l2);
    printf("FIN TEST liste\n");
    return l;
}

pile test_module_pile(pile p) {
    int elem = 0;
    pile p2 = pile_vide();
    printf("DEBUT TESTS pile\n");
    p = empiler(p, 53);
    afficher_pile(p);
    p2 = empiler(p2, 42);
    afficher_pile(p2);
    elem = sommet_pile(p);
    printf("sommet_pile(p) = %d\n", elem);
    printf("taille(p) = %d\n", taille_pile(p));
    afficher_pile(p);
    p = depiler(p);
    printf("Taille(p) = %d\n", taille_pile(p));
    printf("FIN TESTS pile\n");
    return p;
}

pile test_module_file(file f) {
    int elem = 0;
    file f2 = file_vide();
    printf("DEBUT TESTS file\n");
    f = enfiler(f, 533);
    afficher_file(f);
    f2 = empiler(f2, 42);
    afficher_pile(f2);
    elem = debut_file(f);
    printf("Debut_file(f) = %d\n", elem);
    printf("taille(f) = %d\n", taille_file(f));
    afficher_file(f);
    f = defiler(f);
    printf("Taille(p) = %d\n", taille_file(f));
    printf("FIN TESTS file\n");
    return f;
}