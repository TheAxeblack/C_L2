#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include <MLV/MLV_all.h>

tablette creer_tablette(int n, int m) {
    int i, j;
    tablette t;

    t.n = n;
    t.m = m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            t.terrain[i][j] = 1;
    return t;
}

void manger(tablette *t, int x, int y) {
    int i, j, n, m;

    n = t->n;
    m = t->m;
    for (i = x; i < n; i++)
        for (j = y; j < m; j++)
            t->terrain[i][j] = 0;
}

int est_legal(configuration *config, coup *cp) {
    int c, y;
    tablette t;

    c = cp->c;
    y = cp->y;
    t = config->tab;

    if (t.terrain[c][y] == 0)
        return 0;
    return 1;
}

int est_finie(configuration *config, joueur *gagnant) {
    tablette t;

    t = config->tab;
    if (t.terrain[0][0] == 0) {
        if (config->j == J1) {
            *gagnant = J2;
            fprintf(stdout, "Joueur 2 a gagné\n");
        } else {
            *gagnant = J1;
            fprintf(stdout, "Joueur 1 a gagné\n");
        }
        return 1;
    }
    return 0;
}

void jouer_coup(configuration *config, coup *cp) {

    if (!est_legal(config, cp)) {
        fprintf(stderr, "Erreur le coup que vous souhaitez jouer n'est pas valide\n");
    } else {
        manger(&config->tab, cp->c, cp->y);
        config->j = (config->j == J1) ? J2 : J1;
    }
}

void afficher_configuration(configuration *config) {
    int i, j, n, m;
    tablette t;

    t = config->tab;
    n = t.n;
    m = t.m;


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            t.terrain[i][j] == 1 ? MLV_draw_filled_rectangle(50 * i, 50 * j, 50, 50, MLV_COLOR_CHOCOLATE)
                                 : MLV_draw_filled_rectangle(50 * i, 50 * j, 50, 50, MLV_COLOR_LIGHT_GRAY);
            MLV_draw_rectangle(50 * i, 50 * j, 50, 50, MLV_COLOR_BLACK);
        }
    }

    /* Affichage du joueur courant */
    if (config->j == J1)
        MLV_draw_text(10, m * 50 + 10, "Joueur 1 (chocolat noir) c'est votre tour.", MLV_COLOR_BLACK);
    else
        MLV_draw_text(10, m * 50 + 10, "Joueur 2 (chocolat blanc) c'est votre tour.", MLV_COLOR_BLACK);

    /* Affichage des joueurs et du carré empoisonné */
    MLV_draw_text(n * 50 / 2 - 40, m * 50 + 10, "Joueur 1 (chocolat noir)", MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(n * 50 / 2 - 20, m * 50 + 20, 10, 10, MLV_COLOR_BLACK);
    MLV_draw_text(n * 50 / 2 + 20, m * 50 + 10, "Joueur 2 (chocolat blanc)", MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(n * 50 / 2 + 40, m * 50 + 20, 10, 10, MLV_COLOR_WHITE);
    MLV_draw_text(n * 50 - 40, m * 50 + 10, "Carré empoisonné", MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(n * 50 - 20, m * 50 + 20, 10, 10, MLV_COLOR_LIGHT_GRAY);

    /* Affichage de la fenêtre */
    MLV_actualise_window();
}

coup lire_coup(configuration *config) {
    int x, y, i, j;
    coup cp;

    while (1) {
        MLV_wait_mouse(&x, &y);
        i = x / 50;
        j = y / 50;

        if (i >= config->tab.n || j >= config->tab.m) {
            continue;
        }
        if (config->tab.terrain[i][j] == 0) {
            continue;
        }
        cp.c = i;
        cp.y = j;
        break;
    }

    return cp;
}




int main(int argc, char **argv) {
    int n, m;
    configuration config;
    tablette t;
    joueur gagnant;
    coup cp;


    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n> <m>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    t = creer_tablette(n, m);
    config.tab = t;
    config.j = J1;

    MLV_create_window("Chomp", "", n * 50, m * 50);

    while (!est_finie(&config, &gagnant)){
        afficher_configuration(&config);
        cp = lire_coup(&config);
        jouer_coup(&config, &cp);
    }

    MLV_free_window();
    exit(EXIT_SUCCESS);
}
