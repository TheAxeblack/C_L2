#include <stdio.h>
#include <stdlib.h>

void ft_usage(char *nom)
{
  printf("Usage %s : <entier1_positif> <entier2_positif>\n", nom);
}

int main(int argc, char **argv)
{
  int x;
  int y;
  int M;
  int N;

  x = 0;
  y = 0;
  if (argc != 3)
  {
    ft_usage(argv[0]);
    exit(EXIT_FAILURE);
  }
  else
  {
    M = atoi(argv[1]);
    N = atoi(argv[2]);
    if (M >= 0 && N >= 0)
    {
      while (y < N)
      {
        x = 0;
        while (x < M)
        {
          printf("*");
          x++;
        }
        printf("\n");
        y++;
      }
      printf("\n");
    }
    else
    {
      ft_usage(argv[0]);
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
