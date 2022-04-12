/**
 *Petit programme qui corrige la questions VIII du TD3
 *
 *
 *  A. Habrard le 01/02/2016 - mise a jour
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
  int t[]={12,25,28,35,45,78,95}; 
  int * p;
  
  /* -----------------------------------------*/
  /* Autres variables pour exemples complementaires, affichage plus bas */
  char c='a';
  char * adr_c=&c;
  double x=0.1;
  double * adr_x=&x;
  char ** adr2_c=&adr_c;
  int ** p2=&p;
  /* -----------------------------------------*/

  p=t; 
  
 
  /* */
  printf("Question VIII, affichage avec %%p:\n *p+2:%d\n *(p+2):%d\n &p: %p\n&p+1: %p\n&t[4]-4: %p\n p: %p\nt+2: %p\n&t[4]-t: %ld\n&t[4]-p: %ld\nt: %p\n\n", *p+2, *(p+2),(void *) &p, (void *) (&p+1), (void *) (&t[4]-4),(void *)p,(void *) (t+2),&t[4]-t,  &t[4]-p, (void *)t );
 /*pour avoir l'affichage avec les long int decommenter la 2eme ligne ci-dessous commencant par un commentaire */
  printf("Question VIII - affiche avec %%ld, avec affichages complémentaires:\n*p+2:%d\n*(p+2):%d\n &p: %ld\n&p+1: %ld\n&t[4]-4: %ld\n p: %ld\nt+2: %ld\n&t[4]-t: %ld\n&t[4]-p: %ld\n t: %ld\n *(t+2): %d\n &t:%ld\n", *p+2, *(p+2), (long) &p, (long) (&p+1), (long) (&t[4]-4), (long) p, (long)  (t+2) ,&t[4]-t, (long) (&t[4]-p), (long) t,*(t+2),(long)&t); 

  /* p=&p;*/

 
  printf("\n\n Autres affichages avec %%ld:\nadr char* &c:%ld\nadr char* &c+1:%ld\nadr double* adr_x:%ld\nadr double* adr_x+1:%ld\nadr char** adr2_c:%ld\nadr char** adr2_c+1:%ld\nadr int** p2:%ld\nadr int** p2+1:%ld\nadr int* p:%ld\nadr int* p+1:%ld\n",(long)adr_c,(long)(adr_c+1),(long)adr_x,(long)(adr_x+1),(long)adr2_c,(long)(adr2_c+1),(long)p2,(long)(p2+1),(long)p,(long)(p+1));

  return EXIT_SUCCESS;
}

  
