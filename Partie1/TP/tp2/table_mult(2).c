#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;
  int mult;
  int res;

  mult = 2;
  while (mult < 10)
    {
      i = 1;
      while (i <= 10)
	{
	  res = i * mult;
	  printf("%d x %d = %d\n", i, mult, res);
	  i++;
	}
      printf("\n");
      mult++;
    }
  exit(EXIT_SUCCESS);
}
