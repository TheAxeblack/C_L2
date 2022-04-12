/*
 *Fichier d'en tete de l'implementation de file avec 2 piles implementees sous
 * la forme d'un tableau
 *
 *
 * hist: A. Habrard
 *  creation le 25/03/2015
 *  modif le 01/03/2016
 */

#ifndef _FILE_AV_2_PILES_TABLEAU_H_
#define _FILE_AV_2_PILES_TABLEAU_H_

#include "pile_tableau.h"

/*structure définissant  la file*/
/*on ajoute à la fin et on défile au début de la file*/
typedef struct struct_file {
    pile pile_entree;
    pile pile_sortie;
} file_struct;
typedef file_struct *file;

/* ------------------------------ */

/* creation d'une file*/
file creer_file(int dim);

/* test de file vide */
int est_file_vide(file f);

/* enfiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la file) */
int enfiler(file f, objet x);

/* defilement d'un objet */
objet defiler(file f);

#endif
