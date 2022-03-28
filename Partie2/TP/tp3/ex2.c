#include "tp3.h"

file ajout_message(char *msg) {
    file p = file_vide();
    p->objet = msg;
    p = p->suivant;
    return p;
}

void affiche_file(file f) {
    printf("Message %s\n")
}