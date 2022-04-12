/**
 *Petit programme de complement la questions V du TD3
 *
 *
 *  A. Habrard le 01/02/2016 - mise a jour
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
  int *p1=malloc(3*sizeof(int)); 
  char *p2=malloc(4*sizeof(char));  
  float *p3=malloc(10*sizeof(float));
  
  *p1=-1;
  *(p3+4)=5.7;
  *p2='c';
  
  *(p2+3)='a';
      
  printf("\n\nElement bonus\n p1[0]:%d, p1[1]:%d, p2[0]:%c, p2[3]:%c, p2[2]:%c, p3[0]:%f, p3[4]:%f, p3[9]:%f\n",p1[0],p1[1],p2[0],p2[3],p2[2],p3[0],p3[4],p3[9]);


  return EXIT_SUCCESS;
}

  
