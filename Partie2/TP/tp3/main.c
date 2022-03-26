#include "tp3.h"

int main(int argc, char **argv) {

    liste l;
    l = liste_vide();
    l = inserer_element_liste(l, 52);
    l = inserer_element_liste(l, 42);
    test_module(l);
    return (0);
}