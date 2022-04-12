/*
 *Exemple d'implementation de pile avec un tableau
 *fiche d'en-tete
 *
 *pour plus de généricité et de portabilité, la pile
 *est mise dans une structure
 *
 *
 *hist A. Habrard, le 24/03/2014
 *     modif le 16/03/2016
 *     maj   le 12/04/2021     
 *
 */

#ifndef _PILE_TABLEAU_H_
#define _PILE_TABLEAU_H_

/*on defini le type des objets dans la file, des entiers >0 par exemple*/
typedef  int objet;
#define OBJET_VIDE -1 /* set a definir la notion d'objet vide, pourrait etre NULL si les objets sont des pointeurs */

/* structure définissant  la pile*/
typedef struct struct_pile{
  int dimension_pile;
  objet * tab; 
  int sommet;
}pile_struct;
typedef pile_struct * pile;

/* ------------------------------ */

/* creation d'une pile*/
pile creer_pile(int dim);

/*test de pile vide */
int est_pile_vide(pile p);

/*test de pile pleine */
int est_pile_pleine(pile p);

/* empiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la pile) */
int empiler(pile p,objet x);

/* depilement d'un objet */
objet depiler(pile p);
#endif
