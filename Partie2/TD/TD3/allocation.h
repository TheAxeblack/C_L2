/**
 * Ficher impl�mentant des fonctions d'allocation et de liberation memoire
 *
 * hist:
 *  A. Habrard le 10/02/2014
 *         MAJ le 06/02/2017 
 *         MAJ le 28/01/2018
 */


#ifndef _ALLOCATION_H_
#define _ALLOCATION_H_

/*--------------------------------------------------------------------
 *fonction d'allocation de memoire du type defini par taille 
 *pour un nombre nobjets
 *alloue un espace de memoire de taille  nobjets*taille octets
 */
void *allocation_mem(size_t nobjets, size_t taille);


/*--------------------------------------------------------------------
 *fonction d'allocation de memoire du type defini par taille 
 *pour un nombre nobjets, l'espace m�moire est initialise � 0 (null)
 *alloue un espace de memoire de taille  nobjets*taille octets
 */
void *allocation_mem_init0(size_t nobjets, size_t taille);


/*--------------------------------------------------------------------
 *fonction qui realloue un espace memoire DEJA ALLOUE precedemment
 *avec une taille memoire differente
 * l'adresse memoire deja allouee est definie par (*ptr) 
 * l'espace alloue est de taille nobjets*taille octets
 */
void *reallocation_mem(void *pt, size_t nobjets, size_t taille);

/*--------------------------------------------------------------------
 *fonction qui realloue un espace memoire DEJA ALLOUE precedemment
 *avec une taille memoire differente
 * l'adresse memoire deja allouee est definie par (*ptr) 
 * l'espace alloue est de taille nobjets*taille octets
  * cette fonction modifie le pointeur *pt en l'affectant � la nouvelle adresse
  */
void *reallocation_mem_peda(void **pt, size_t nobjets, size_t taille);

/*--------------------------------------------------------------------
 fonction qui libere de la memoire allouee en *pt
 on suppose que pt est l'adresse de la variable allou�e
 n�cessaire pour pouvoir lib�r�.
 */
void libere_mem(void *pt);


/*--------------------------------------------------------------------
 fonction qui libere de la memoire allouee en *pt
  version p�dagogique qui force � entrer un adresse de pointeur
  mais qui n�cessite un cast pour �viter un warning*/
void libere_mem_peda(void **pt);


/*--------------------------------------------------------------------
 fonction qui libere de la memoire allouee en pt
 mais il n'y a pas de controle
 */
void libere(void *pt);

#endif

