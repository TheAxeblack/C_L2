/**
 *
 *Ficher corrigeant la question II du TD3
 *
 * Note, dans les printf l'affichage des adresses contenues
 *  dans les pointeurs par des %ld provoque un warning,
 *  pour enlever ce warning il suffit de le remplacer
 *  par un %p impliquant un affichage en hexadecimal.
 *
 * hist
 * A. Habrard, le 03/02/2014 - creation
 * A. Habrard, le 08/02/2015 - modification
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* fonction echange demandee en question 1 */
void echange(int * p_a,int * p_b)
{
  int aux;

  aux=*p_a;
  *p_a=*p_b;
  *p_b=aux; 
  
  printf("Dans echange3, les adresses de a: %ld, et b: %ld\n",(long)p_a,(long)p_b);
}


/* fonction echange fausse: echange les pointeurs a l'interieur mais pas dans le main */
void echange_faux2(int * p_a,int * p_b)
{
  int * aux;
  

  aux=p_a;
  p_a=p_b;
  p_b=aux; 
  
  printf("Dans echange fausse2, les adresses de a: %ld, et b: %ld\n",(long)p_a,(long)p_b);
}


/*fonction echange fausse*/
void echange_faux(int a,int b)
{
  int aux;

  aux=a;
  a=b;
  b=aux;

  printf("Dans echange_faux, les adresses de a: %ld, et b: %ld\n",(long)&a,(long)&b);
}

/*main*/
int main()
{
  int a=0;
  int b=0;

  printf("Saisie du nombre a: ");
  scanf("%d",&a);
  printf("Saisie du nombre b: ");
  scanf("%d",&b);
  printf("\n --- \n");

  printf("\nAvant les fonctions, les adresses de a: %ld, et b: %ld - affichage avec %%ld\n",(long)&a,(long)&b);
  printf("Avant les fonctions, les adresses de a: %p, et b: %p - affichage avec %%p, pas de warning\n\n",(void *)&a,(void *)&b);

  printf("avant echange_faux: a:%d b:%d\n",a,b);
  echange_faux(a,b);
  printf("apres echange_faux: a:%d b:%d\n\n",a,b);

  printf("avant echange_faux2: a:%d b:%d\n",a,b);
  echange_faux2(&a,&b);
  printf("apres echange_faux2: a:%d b:%d\n\n",a,b);

  printf("avant echange de la question I : a:%d b:%d\n",a,b);
  echange(&a,&b);
  printf("apres echange de la question I : a:%d b:%d\n",a,b);
 

  
  return EXIT_SUCCESS;
}
