/**
 *Petit programme qui corrige la questions V du TD3
 *
 *Il y a un warning a la ligne 54 qui peut causer un bug
 *a eviter, donc a commenter pour avoir un code propre
 *
 *  A. Habrard le 01/02/2016 - mise a jour
 *             le 02/02/2016 - mise a jour affichage pointeurs
 *             le 30/01/2022 - mis a jour affichage %ld et %p
 */

 /* Solution pas à pas
                    a  b  c  p1   p2
      Init.         1  2  3  NULL NULL
      p1=&a         1  2  3  &a   NULL
      p2=&c         1  2  3  &a   &c
      *p1=(*p2)++   3  2  4  &a   &c
      p1=p2         3  2  4  &c   &c
      p2=&b         3  2  4  &c   &b
      *p1-=*p2      3  2  2  &c   &b
      ++*p2         3  3  2  &c   &b
      *p1*=*p2      3  3  6  &c   &b
      a=++*p2**p1  24  4  6  &c   &b
      p1=&a        24  4  6  &a   &b
      *p1/=*p2      6  4  6  &a   &b 
      *p2=*p1       6  6  6  &a   &b
   */

#include <stdio.h>
#include <stdlib.h>


int main()
{
  int a = 1;
  int b = 2;
  int c = 3;
  int *p1=NULL, *p2=NULL;

  printf("Question V - adresses initiales des variables a, b et c ;\n&a: %p\n&b: %p\n&c: %p\n\n",(void *)&a,(void *)&b,(void *)&c);
  /* printf("Question III - adresses initiales des variables a, b et c ;\n&a: %ld\n&b: %ld\n&c: %ld\n\n",&a,&b,&c);*/
  p1=a;
  //p1=&a;
  p2=&c;
  *p1=(*p2)++;
  p1=p2;
  p2=&b;
  *p1-=*p2; /* (*p1)= (*p1) - (*p2) ou (*p1) -= (*p2) */
  ++*p2; /*(*p2)++ */
  *p1*=*p2; /* (*p1) *= (*p2) ou (*p1) = (*p1) * (*p2) */
  a=++*p2**p1; /* a = (++(*p2)) * (*p1) */
  p1=&a;
  *p2=*p1/=*p2;
  /* *p1/=*p2; //(*p1) /= (*p2) ou (*p1)=(*p1)/(*p2) */
  /* *p2=*p1; */

  /*choisissez votre mode d'affichage*/
  printf("Question V;\na: %d\nb: %d\nc: %d\np1 %p - (*p1): %d\np2: %p - (*p2): %d\n\n\n",a,b,c,(void *)p1,*p1,(void *)p2,*p2);
  printf("Question V - resultat final;\na: %d\nb: %d\nc: %d\np1 %ld - (*p1): %d\np2: %ld - (*p2): %d\n\n\n",a,b,c,(long)p1,*p1,(long)p2,*p2);
  printf("Question V - Autres pointeurs: &p1:%ld, &p2:%ld\n",(long)&p1,(long)&p2);

  return EXIT_SUCCESS;
}

  
