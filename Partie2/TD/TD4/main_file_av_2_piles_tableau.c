/*
 *Fichier main de test pour file_av_2_piles_tableau.c
 *
 *
 *hist A. Habrard,  le 25/03/2015
 *     modification    le 01/03/2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_av_2_piles_tableau.h"

/*exemple de main, note: l'element 4 est quand même insere dans la file grace a l'action d'inversion des piles de la fonction enfiler, on voit que la mention pile saturee est affichée parce que le premier appel a empiler ne marche pas.
Vous pouvez rajouter plus d'affichage pour voir ce qui se passe */
int main()
{
  objet x;
  file f=creer_file(3);
  
  enfiler(f,1);
  enfiler(f,2);
  enfiler(f,3);
  enfiler(f,4);

  x=defiler(f);
  printf("%d\n",x);
  enfiler(f,5);
  x=defiler(f);
  printf("%d\n",x);
  x=defiler(f);
  printf("%d\n",x);
  x=defiler(f);
  printf("%d\n",x);
  x=defiler(f);
  printf("%d\n",x);
  
  return EXIT_SUCCESS;
}
