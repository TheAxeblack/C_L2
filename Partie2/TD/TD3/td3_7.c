/**
 *Petit programme qui corrige la questions VII du TD3
 *
 *A faire : inverser les lignes 23 et 24, modifier la ligne *f=*p en *p=*f (ou la supprimer) et regarder ce qui se passe
 *
 *  A. Habrard le 01/02/2016 
 *  A. Habrard le 10/02/2017 MAJ
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
  int i = 0; 
  int *p; 
  float x = 3.14; 
  float *f=NULL; 
  
  
  p = &i; 

  printf("adr de f 1: %p \n",(void *) f);
  f=&x;
  printf("adr de f 2: %p \n",(void *)f);
  *f = 666; /*faux f ne pointe sur qqchose d'inconnu -> il faut inverser cette ligne avec la ligne suivante */
  
  
  
  printf("adr de f 3: %p \n",(void *)f);
  printf("valeur de f : %f \n",*f);

  *f = *p; /*et si on inverse (*p=*f;) potentiel probleme */
  *p = 34; 
  printf("*p: %d, *f: %f -- adresse p: %p et adrese f: %p\n",*p,*f,(void *)p,(void *)f);
 

  p =  f;  /*attention ici : types de pointeurs incompatibles pas d'erreur -> mais warning */
  /**f = *f + 1; */ /*si on change la ligne *f=*p; au dessus en *p=*f; ou si on la supprime -> pb avec le +1 !!! */
  *p=*p+1;
  printf("***Apres +1 : *p: %d, *f:%f -- adresse p: %p et adrese f: %p\n",*p,*f,(void *)p,(void *)f);
  
  *f=*f+1;
  printf("***Apres +1 numero 2 : *p: %d, *f:%f -- adresse p: %p et adrese f: %p\n",*p,*f,(void *)p,(void *)f);
  
 /*Decommenter la 1ere ligne pour ne plus avoir de warning */
   printf("Question VII\n i:%d, *f:%f, f:%p, p:%p, *p:%d, x:%f\n\n\n", i, *f, (void *)f, (void *)p, *p, x ); 
   /*printf("Question VII\n i:%d, *f:%f, f:%ld, p:%ld, *p:%d, x:%f\n\n\n", i, *f, (int *)f, (int *)p, *p, x ); */
   *p=-12;
printf("Question VII-v2\n i:%d, *f:%f, f:%p, p:%p, *p:%d, x:%f\n\n\n", i, *f, (void *)f, (void *)p, *p, x ); 

  return EXIT_SUCCESS;
}

  
