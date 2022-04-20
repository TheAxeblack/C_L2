#ifndef C_DICTIONNAIRE_H
#define C_DICTIONNAIRE_H

#include "arbre_binaire.h"

typedef arbre dictionnaire;

int existe(dictionnaire d, char *mot);

void affiche_dico(dictionnaire d);

dictionnaire insere_dico(dictionnaire d, char *mot);

#endif
