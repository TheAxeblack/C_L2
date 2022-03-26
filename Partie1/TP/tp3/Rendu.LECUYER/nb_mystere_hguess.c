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
      n = rand() % 100;
      printf("La machine a choisi un nombre mystere entre 0 et 100, a vous de le trouver\n");
      while (x != n)
	{
	  printf("Votre proposition ?\n");
	  if (scanf("%d", &x) != 1)
	    {
	      ft_usage(argv[0]);
	      ft_kbuffer();
	      exit(EXIT_FAILURE);
	    }
	  else
	    {
	      if (x >= 0 && x <= 100)
		{
		  if (x < n) {
		    printf("C'est faux, le nombre mystere est superieur a %d\n", x);
		    i++;
		    ft_kbuffer();
		  }
		  else if (x > n)
		    {
		      printf("C'est faux, le nombre mystere est inferieur a %d\n", x);
		      i++;
		      ft_kbuffer();
		    }
		  else
		    {
		      printf("C'est juste, vous avez trouver le nombre mystere (%d) en %d etape", n, i);
		      if (i == 1)
			printf("\n");
		      else
			printf("s\n");
		      ft_kbuffer();
		    }
		}
	      else
		{
		  ft_usage(argv[0]);
		  ft_kbuffer();
		  exit(EXIT_FAILURE);
		}
	    }
	}
      printf("Voulez-vous recommencer ? (oui:1 / non:0)\n");
    }
  while ((x = getchar()) != '0');
  exit(EXIT_SUCCESS);
}
