#include <stdio.h>
#include <stdlib.h>
#define NB_MAX 2048

void ft_usage(char *nom)
{
  printf("Usage %s : <entier> superieur a 2\n", nom);
}

void eratosthene(int n)
{
  int t[NB_MAX];
  int i;
  int j;

  for (i = 0; i < n; i++)
      t[i] = 1;
  for (i = 2; i < n; i++)
    {
      if (t[i] == 1)
	  for (j = i + 1; j < n; j += i)
	    t[j] = 0;
      printf("Les entiers premiers de 2 a %d sont :\n", n);
      for (i = 2; i < n; i ++)
	if (t[i] == 1)
	  printf("%d ", i);
      printf("\n");
    }
}

int main(int argc, char **argv)
{
  if (argc != 2)
    {
      ft_usage(argv[0]);
      exit(EXIT_FAILURE);
    }
  else
    eratosthene(atoi(argv[1]));
  exit(EXIT_SUCCESS);
}
		
