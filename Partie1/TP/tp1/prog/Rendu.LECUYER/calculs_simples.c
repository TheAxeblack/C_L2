#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a;
  int b;

  printf("Entrez deux entiers a et b : \n");
  if (scanf("%d %d", &a, &b) != 2)
    {
      printf("Veuillez entrer uniquement deux entiers x et y");
      exit(EXIT_FAILURE);
    }
  else
    {
      printf("a = %d, b = %d\n", a, b);
      printf("a * b = %d\n", a * b);
      if (b != 0)
	{
	  printf("Quotient entier = %d\n", a / b);
	  printf("Reste entier = %d\n", a % b);
	}
    }
  exit(0);
}
