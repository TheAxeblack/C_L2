#include <stdio.h>
#include <stdlib.h>

void ft_kbuffer(void)
{
  int x;

  x = 0;
  while (x != '\n' && x != EOF)
    x = getchar();
}

int main(void)
{
  int n;
  int i;
  float res;

  n = 1;
  i = 1;
  res = 0;
  printf("Entrer la valeur de n :\n");
  if (scanf("%d", &n) != 1)
  {
    printf("Vous n'avez pas le bon nombre d'arguments.\nRappel, nous n'avons besoin que d'une valeur et il doit s'agir d'un entier.\n");
    ft_kbuffer();
    exit(EXIT_FAILURE);
  }
  else
  {
    while (i <= n)
    {
      res += 1.0 / i;
      i++;
    }
    printf("Fn = %f\n", res);
  }
  exit(EXIT_SUCCESS);
}
