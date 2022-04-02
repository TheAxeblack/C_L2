#include "tp3.h"

int main(int argc, char **argv) {

    liste liste1 = liste_vide();
    pile pile1 = pile_vide();
    file file1 = file_vide();
    test_module_liste(liste1);
    test_module_pile(pile1);
    test_module_file(file1);

/*    file file1 = file_vide();
    element e = {"Noah", "Poisson", "30-03-2022", "Salut je veux acheter un poisson !"};
    ajout_message(file1, e);
    affiche_message(file1);
    supprime_message(file1);
    affiche_message(file1);*/
    return (0);
}