#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ft_rand(void)
{
  int m;
  int n;
  int p;
  int q;
  int tmp;

  srand(time(NULL));
  m = rand() % 100;
  n = rand() % 100;
  p = rand() % 100;
  q = rand() % 100;
  printf("Avant SWITCH : \n");
  printf("m = %d, n = %d, p = %d et q = %d\nDebut du SWITCH\n", m, n, p, q);
  tmp = q;
  q = p;
  p = n;
  n = m;
  m = tmp;
  printf("SWITCH fini : \nm = %d, n = %d, p = %d et q = %d\n", m, n , p, q);
}

int main(void)
{
  ft_rand();
  exit(0);
}
