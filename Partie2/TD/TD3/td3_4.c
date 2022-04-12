/**
 *Petit programme qui corrige la questions IV du TD3
 *
 *  A. Habrard le 01/02/2017 - mise a jour
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{/* question II */
  
  int a=3; 
  int b=10; 
  int c, *pa, *pb, *pc;
  
  pa = &a; 
  *pa = *pa * 2; 
  pb = &b; 
  c = 3 * (*pb - *pa); 
  pc = pb; 
  pa = pb; 
  pb = pc; 
    
  printf("Question IV;\n*pa: %d\n*pb: %d\n*pc: %d\na: %d\nb: %d\nc: %d\n\n\n",*pa,*pb,*pc,a,b,c);
  printf("adresses: pa:%p, pb:%p, pc:%p\n",(void *)pa,(void *)pb,(void *)pc);
    
  return EXIT_SUCCESS;
}
