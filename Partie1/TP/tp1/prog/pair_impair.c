#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x;

  printf("Veuillez rentrez un entier :\n");
  if(scanf("%d", &x) != 1)
    {
      printf("Erreur. Pas le bon nombre d'arguments...\n");
      exit(-1);
    }
  else
    {
      if(x % 2 == 0)
	printf("Cet entier est pair\n");
      else
	printf("Cet entier est impair\n");
    }
  exit(0);
}
