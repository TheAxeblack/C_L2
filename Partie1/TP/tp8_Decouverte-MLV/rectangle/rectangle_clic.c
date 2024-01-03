#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 0, y = 0; // Coordonnées du clic
    int i = 0; // Compteur
    int x_s = 10, y_s = 10; // Coordonnées du rectangle
    int w = 200, h = 120; // Largeur et hauteur du rectangle

    MLV_create_window("rectangle_clic.c", "tp8", 640, 480);

    do {
        if (i % 2 == 0) {
            MLV_draw_filled_rectangle(x_s, y_s, w, h, MLV_COLOR_RED);
        } else {
            MLV_draw_filled_rectangle(x_s, y_s, w, h, MLV_COLOR_BLUE);
        }
        i++;
        MLV_actualise_window();
        MLV_wait_mouse(&x, &y);
    } while (x >= x_s && x <= x_s + w && y >= y_s && y <= y_s + h);

    MLV_free_window();
    exit(EXIT_SUCCESS);
}
