#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void ft_usage(char *nom)
{
  printf("Usage %s : <entier_n>\n", nom);
}

int main(int argc, char **argv)
{
  int n;
  int i;
  int res;

  i = 1;
  res = 1;
  if (argc != 2)
    {
      ft_usage(argv[0]);
      exit(EXIT_FAILURE);
    }
  else
    {
      n = atoi(argv[1]);
      if (n < 0)
	{
	  ft_usage(argv[0]);
	  exit(EXIT_FAILURE);
	}
      else if (n == 0)
	printf("%d! = 1\n", n);
      else
	{
	  while (i <= n)
	    {
	      if (res < (INT_MAX / i))
		  res = res * i;
	      else
		{
		  printf("Le calcul de %d! est impossible sur ce poste.\n", n);
		  exit(EXIT_FAILURE);
		}
	      i++;
	    }
	  printf("%d! = %d\n", n, res);
	}
    }
  exit(EXIT_SUCCESS);
}
      
	  
      
