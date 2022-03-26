#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ft_usage(char *nom)
{
  printf("Usage %s : <entier> qui doit etre entre 0 et 100.\n", nom);
}

void ft_kbuffer(void) {
  int x;

  x = 0;
  while (x != '\n' && x != EOF)
    x = getchar();
}



int main(int argc, char **argv)
{
  int n;
  int x;
  int i;
  (void)argc;

  i = 1;
  srand(time(NULL));

  do
    {
      printf("Entrez un entier que la machine devra trouver\n");
      if ((scanf("%d", &n) != 1) || n < 0 || n > 100)
	{
	  ft_usage(argv[0]);
	  ft_kbuffer();
	  exit(EXIT_FAILURE);
	}
      else
	{
	  printf("L'utilisateur a choisi un nombre mystere entre 0 et 100, a la machine de le trouver\n");
	  x = 0;
	  while (x != n)
	    {
	      
	      printf("Proposition de la machine ? ");
	      x = rand() % 100;
	      printf("%d\n", x);
	      if (x < n)
		{
		  printf("C'est faux, le nombre mystere est superieur a %d\n", x);
		  i++;
		}
	      else if (x > n)
		{
		  printf("C'est faux, le nombre mystere est inferieur a %d\n", x);
		  i++;
		}
	      else
		{
		  printf("C'est juste, la machine a trouver le nombre mystere (%d) en %d etape", n, i);
		  if (i == 1)
		    printf("\n");
		  else
		    printf("s\n");
		}
	    }
	}
      printf("Voulez-vous recommencer ? (oui:1 / non:0)\n");
      ft_kbuffer();
    }
  while ((n = getchar()) != '0');
  exit(EXIT_SUCCESS);
}
	
