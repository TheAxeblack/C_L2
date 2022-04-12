/**
 *fichier main du TD4_10
 *
 *hist A. Habrard
 *
 *le 16/03/2015
 *maj le 27/02/2017
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "listedc.h"


int main()
{
  liste l=inserer_element_trie(inserer_element_trie(inserer_element_trie(liste_vide(),2),1),5);
  
  affiche_liste(l);
  l=supprimer_element(l,2);
  affiche_liste(l);
  l=inserer_element_trie(l,7);
  affiche_liste(l);
  l=supprimer_element(l,3);
  affiche_liste(l);
  l=supprimer_element(l,7);
  affiche_liste(l);
  l=supprimer_element(l,4);
  affiche_liste(l);
  l=supprimer_element(l,1);
  affiche_liste(l);
  l=supprimer_element(l,5);
  affiche_liste(l);

  return EXIT_SUCCESS;
}
