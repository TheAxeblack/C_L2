#include "tp3.h"

int main(int argc, char **argv) {
    liste liste1 = liste_vide();
    pile pile1 = pile_vide();
    pile pile2 = pile_vide();
    file file1 = file_vide();
<<<<<<< refs/remotes/origin/main
    int a = 0;

    printf("Exercice 1\n");
=======
>>>>>>> ajout corrections Partie2/TD
    test_module_liste(liste1);
    test_module_pile(pile1);
    test_module_file(file1);

<<<<<<< refs/remotes/origin/main
    printf("\nExercice 3\n");
    a = calcul_postfixe(argc, argv, pile2);
    printf("Resultat du calcul de l'expression postfixee = %d\n", a);
=======

>>>>>>> ajout corrections Partie2/TD
    return (0);
}