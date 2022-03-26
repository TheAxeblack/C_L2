#include <stdio.h>
#include <stdlib.h>
#define NB_MAX 100

void ft_usage(char *nom)
{
  fprintf(stderr, "usage %s : <entier>, <entier> > 0\n", nom);
}

void affichage(int n, int t[][NB_MAX])
{
  int i;
  int j;

  i = 0;
  while (i < n)
    {
      j = 1;
      while (j <= i + 1)
	{
	  fprintf(stdout, "%d ", t[i][j]);
	  j++;
	}
      fprintf(stdout, "\n");
      i++;
    }
}

int main(int argc, char **argv)
{
  int n;
  int t[NB_MAX][NB_MAX];
  int i;
  int j;
  
  if (argc < 2 || (n = atoi(argv[1])) <= 0)
    {
      ft_usage(argv[0]);
      exit(EXIT_FAILURE);
    }
  else
    {
      /* Initialisation a 0 */
      for (i = 0; i <= n; i++)
	for (j = 0; j <= n; j++)
	  t[i][j] = 0;
      /* Triangle de Pascal */
      t[0][1] = 1;
      for (i = 1; i < n; i++)
	{
	  for (j = 1; j <= i + 1; j++)
	    t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
	}
    }
  affichage(n, t);
  exit(EXIT_SUCCESS);
}
