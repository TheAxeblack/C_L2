#ifndef TP_TP3_H
#define TP_TP3_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "allocation.h"
#include "liste.h"
#include "pile.h"
#include "file.h"
#include <MLV/MLV_all.h>
#include <stddef.h>
#include "ex2.h"

/* Fonctions de l'exercice 1 */

liste test_module_liste(liste l);

pile test_module_pile(pile p);

file test_module_file(file f);

/* Fonctions de l'exercice 2 */

liste ajout_message(file f, element msg);

file supprime_message(file f);

void affiche_message(file f);

/* Fonctions de l'exercice 2 */
typedef m_liste message;

message ajouter_message(message m, element val);

message supprimer_message(message m);

message afficher_message(message m);


/* Fonctions de l'exercice 3 */
int calcul_postfixe(int taille, char **params, pile p);

#endif
