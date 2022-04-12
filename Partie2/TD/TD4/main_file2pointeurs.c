/**
 *fichier main du TD4_2
 *
 *hist A. Habrard
 *
 *le 16/03/2015
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_2pointeurs.h"


int main() {
    file f = file_vide();
    element e;

    enfiler(f, 2);
    enfiler(f, 1);
    enfiler(f, 5);

    affiche_file(f);
    e = defiler_av_element(f);
    printf("On a supprime : %d\nAffiche file:\n", e);
    affiche_file(f);
    enfiler(f, 7);
    affiche_file(f);

    e = defiler_av_element(f);
    printf("On a supprime : %dAffiche file:\n\n", e);
    affiche_file(f);
    e = defiler_av_element(f);
    printf("On a supprime : %d\nAffiche file:\n", e);
    affiche_file(f);
    e = defiler_av_element(f);
    printf("On a supprime : %d\nAffiche file:\n", e);
    affiche_file(f);
    e = defiler_av_element(f);
    printf("On a supprime : %d\nAffiche file:\n", e);
    affiche_file(f);
    e = defiler_av_element(f);
    printf("On a supprime : %d\nAffiche file:\n", e);
    affiche_file(f);


    printf("test 2\n");
    enfiler(f, 2);
    enfiler(f, 1);
    enfiler(f, 5);

    affiche_file(f);
    defiler(f);
    printf("On a defile \nAffiche file:\n");
    affiche_file(f);
    enfiler(f, 7);
    affiche_file(f);

    defiler(f);
    printf("On a defile \nAffiche file:\n");
    affiche_file(f);
    defiler(f);
    printf("On a defile \nAffiche file:\n");
    affiche_file(f);
    defiler(f);
    printf("On a defile \nAffiche file:\n");
    affiche_file(f);
    defiler(f);
    printf("On a defile \nAffiche file:\n");
    affiche_file(f);
    defiler(f);
    printf("On a defile \nAffiche file:\n");
    affiche_file(f);


    return EXIT_SUCCESS;
}
