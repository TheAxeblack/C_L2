/*
 *Fichier main de test pour file_tableau.c
 *
 *
 * hist: A. Habrard,  25/03/2015
 *        modifle 01/03/2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_tableau.h"


/* exemple de main, vous pouvez afficher plus de messages pour voir ce qui se passe*/

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

