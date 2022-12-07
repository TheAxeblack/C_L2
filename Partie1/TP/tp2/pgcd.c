#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom)
{
  printf("Usage %s : <entier1> <entier2>\n", nom);
}

int main(int argc, char **argv)
{
  int entier1, a;
  int entier2, b;
  int tmp;
  int res;
  int reste;

  res = 0;
  tmp = 0;
  if (argc != 3)
  {
    ft_usage(argv[0]);
    exit(EXIT_FAILURE);
  }
  else
  {
    entier1 = atoi(argv[1]);
    entier2 = atoi(argv[2]);
    if (entier1 < entier2)
    {
      tmp = entier1;
      entier1 = entier2;
      entier2 = tmp;
    }
    a = entier1;
    b = entier2;
    reste = a % b;
    while (reste != 0)
    {
      a = b;
      b = reste;
      reste = a % b;
    }
    res = b;
    printf("PGCD(%d, %d) = %d\n", entier1, entier2, res);
  }
  exit(EXIT_SUCCESS);
}
