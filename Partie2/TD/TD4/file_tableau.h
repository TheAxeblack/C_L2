/*
 *Fichier d'en tete de l'implementation de file avec un tableau
 *
 *
 * hist: A. Habrard
 *  creation le 25/03/2015
 *  modif le 01/03/2016
 */

#ifndef _FILE_TABLEAU_H_
#define _FILE_TABLEAU_H_


/*on defini le type des objets dans la file, des entiers >0 par exemple*/
typedef int objet;

#define OBJET_VIDE -1 /* set a definir la notion d'objet vide, pourrait etre NULL si les objets sont des pointeurs */

/* ------------------------------ */

/*structure définissant  la file*/
/*on ajoute à la fin et on défile au début de la file*/
typedef struct struct_file{
  int dimension_file; /*taille du tableau*/
  objet * tab;  /*tableau ou l'on stocke les elements*/
  int debut; /*debut de la file*/
  int fin; /*fin de la file*/
  int taille; /*nb d'elements dans la file*/
}file_struct;
typedef file_struct * file;

/* ------------------------------ */
/*petite fonction qui calcule l'indice suivant, de manière circulaire*/
int calcule_suivant_file(file f,int i);

/* creation d'une file*/
file creer_file(int dim);

/* test de file vide */
int est_file_vide(file f);

/* test file pleine */
int est_file_pleine(file f);

/* tete de file */
objet tete_file(file f);

/* enfiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la file) */
int enfiler(file f,objet x);

/* defilement d'un objet */
objet defiler(file f);

#endif
