#include <stdio.h>
#include <stdlib.h>

int ft_question(void)
{
  int x;

  printf("Combien de nombres ?\n");
  if (scanf("%d", &x) != 1)
    return (-1);
  else
    return (x);
}

int main(void)
{
  int i;
  int x;
  int mini;
  int maxi;
  int tmp;

  x = ft_question();
  i = 0;
  mini = 0;
  maxi = 1;
  while (i < x)
  {
    printf("Entrez un entier :\n");
    if (scanf("%d", &tmp) != 1)
    {
      printf("Erreur. Vous n'avez pas le bon nombres d'arguments.\n");
      exit(-1);
    }
    else
    {
      if (tmp < mini)
      {
        mini = tmp;
        i++;
      }
      else if (tmp > maxi)
      {
        maxi = tmp;
        i++;
      }
      else
        i++;
    }
  }
  printf("min = %d et max = %d\n", mini, maxi);
  exit(0);
}
