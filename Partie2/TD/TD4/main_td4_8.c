/**
 *fichier main du TD4_8
 *
 *hist A. Habrard
 * le 16/03/2015
 *  maj le 08/03/2016
 *  maj le 27/02/2017
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "td4_8.h"

int main()
{
  liste l=insere_element_liste(insere_element_liste(insere_element_liste(liste_vide(),4),3),2);
  liste l2=insere_liste_ordonnee(insere_liste_ordonnee(insere_liste_ordonnee(liste_vide(),5),6),7);
  liste l3=liste_vide();
  liste l4=liste_vide();
  liste l5=liste_vide();
  liste l3_inv=liste_vide();
  liste l6_inv=liste_vide();
  liste l6=liste_vide();
  liste l7=liste_vide();
  liste p_elem=recherche_element(l,6);

  liste r=concatene_listes(l,l2);

  printf("Pointeur de liste contenant 6 trouve dans l: %p, dans l2: %p\n",p_elem,recherche_element(l2,6));
  printf("\nAffiche concatenation de l et l2, l devient la liste concatenee\n");
  affiche_liste(r);
  recopie_liste_iter(l2,&l3);
  printf("\nAffiche recopie liste iter de l2 de l3\n");
  affiche_liste(l3);
  recopie_liste_recu(l,&l4);
  printf("\nAffiche recopie liste recu, de l dans l4\n");
  affiche_liste(l4);
  l7=recopie_liste_recu2(l);
  printf("\nAffiche recopie liste recu2, de l dans l7\n");
  affiche_liste(l7);
  l3_inv=inverse_liste(l3);
  printf("\nAffiche inverse liste de l3\n");
  affiche_liste(l3_inv);
  l5=trie_liste_solution2bis(l3_inv);
  printf("\nAffiche trie liste (solution 2) de l3inverse\n");
  affiche_liste(l5);
  l6_inv=inverse_liste(l);
  printf("\nAffiche inverse liste l dans l6inv\n");
  affiche_liste(l6_inv);
  l6=trie_liste_solution2bis(l6_inv);
   printf("\nAffiche trie liste (solution 2bis) de l6inv\n");
  affiche_liste(l6);

  return EXIT_SUCCESS;
}
