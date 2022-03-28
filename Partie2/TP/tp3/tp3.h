#ifndef TP_TP3_H
#define TP_TP3_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "liste.h"
#include "pile.h"
#include "file.h"
#include <MLV/MLV_all.h>

/* Fonctions de l'exercice 1 */

liste test_module_liste(liste l);


/* Fonctions de l'exercice 2 */
typedef struct msg {
    char *expedition;
    char *sujet;
    char *date;
    char *contenu;
    struct msg *suivant;
} struct_message;

typedef struct_message *messagerie;


#endif
