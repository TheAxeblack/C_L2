/**
 *fichier d'en-tete de l'implementation d'une file avec 2 pointeurs de liste
 *
 * on a rajouter une fonction d'affichage de liste
 *
 * hist A. Habrard
 *  creation le 23/03/2015
 */

#ifndef _FILE_H_
#define _FILE_H_

/*on utilise le type liste doublement chainee*/
#include "liste.h"

/*definition d'un element vide*/
#define ELEMENT_VIDE -1

/*definition du type*/
typedef struct cell_file {
    liste debut;
    liste fin;
} cell_file;
typedef cell_file *file;

/*creation d'une file vide*/
file file_vide();

/*test pour savoir si une file est vide*/
int est_file_vide();

/*ajout d'une element dans la file*/
void enfiler(file f, element e);

/*renvoie le premier element en debut de file*/
element debut_file(file f);

/*supprimer l'element en tete de file et le renvoie*/
element defiler_av_element(file f);

/*supprimer l'element en tete de file */
void defiler(file f);

/*renvoie le nombre d'elements dans la file*/
int taille_file(file f);

/*affichage du contenu de la file*/
void affiche_file(file f);

#endif
