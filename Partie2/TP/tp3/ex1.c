#include "tp3.h"

liste test_module(liste l) {
    int elem = 0;
    l = inserer_element_liste(l, 5);
    l = inserer_element_liste(l, 12);
    l = inserer_element_liste(l, 42);
    l = inserer_element_liste(l, -12);
    elem = renvoie_premier_liste(l);
    printf("%d\n", elem);
    l = supprimer_premier_liste(l);
    elem = renvoie_premier_liste(l);
    printf("%d\n", elem);

    /*MLV_create_window("Exercice 1 - Listes - Test module", "liste", 640, 480);

    MLV_draw_rectangle(10, 50, 12, 12, MLV_COLOR_AQUAMARINE);
    MLV_draw_text(10, 53, "5", MLV_COLOR_MAGENTA);
    MLV_draw_rectangle(10, 62, 12, 12, MLV_COLOR_YELLOW2);

    MLV_actualise_window();

    MLV_wait_seconds(10);
    MLV_free_window();*/
    return l;
}

