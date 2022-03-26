#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;

  i = 0;
  while (i < 10)
    {
      printf("Le carre de %d est : %d \n", i, i*i);
      i++;
    }

  i = 0;
  do
    {
      printf("Le carre de %d est : %d \n", i , i*i);
      i++;
    }
  while(i < 10);
  exit(0);
}
