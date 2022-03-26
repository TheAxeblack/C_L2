#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ft_kbuffer(void)
{
  int x;

  x = 0;
  while (x != '\n' && x != EOF)
    x = getchar();
}

void discriminant(int a, int b, int c)
{
  float res;
  float rac1;
  float rac2;
  
  res = (b * b) - 4 * a * c;
  printf("delta = %f\n", res);
  if (res < 0)
    printf("Pas de racines reelles.\n");
  else if (res == 0)
    {
      rac1 = -b / (2.0 * a);
      printf("x0 = %f\n", rac1);
    }
  else
    {
      rac1 = (-b + sqrt(res)) / (2.0 * a);
      rac2 = (-b - sqrt(res)) / (2.0 * a);
      printf("Les racines sont :\nx1= %f et x2 = %f\n", rac1, rac2);
    }
}

int main(void)
{
  int a;
  int b;
  int c;
  char rep;
  
  do
    {
      printf("Entrez 3 entiers :\n");
      if (scanf("%d %d %d", &a, &b, &c) != 3)
	{
	  printf("Erreur\n");
	  exit(-1);
	}
      else
	{
	  discriminant(a, b, c);
	  ft_kbuffer();
	}
      printf("Continue ? O/N\n");
    }
  while( (rep=getchar()) != 'N');
  
  exit(0);
}
