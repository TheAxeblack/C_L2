#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

void ft_calc1(void)
{
  float x;
  float calc;

  calc = 0;
  printf("Veuillez entrer un reel x :\n");
  if (scanf("%f", &x) != 1 || x <= 0)
    {
      printf("Rentrez un seul reel x (strictement superieur a 0).\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      calc = (x - 1) * log(x);
      printf("f(x) = %f\n", calc);
    }
}

void ft_calc2(void)
{
  float x;
  float y;
  float res;

  res = 0;
  printf("Veuillez entrer deux reels x et y:\n");
  if (scanf("%f %f", &x, &y) != 2 || (x ==  0 && y == 0))
    {
      printf("Rentrez SEULEMENT deux reels x et y. Ils doivent etre differents de 0. Et x doit etre plus positif.\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      res = sqrt(1 - (x * x)) / x + y;
      printf("g(x,y) = %f\n", res);
    }
}

void ft_calc3(void)
{
  float x;
  float result;
  
  result = 0;
  printf("Veuillez entrer un reel x: \n");
  if (scanf("%f", &x) != 1)
    {
      printf("Veuillez entrer SEULEMENT un reel x.\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      result = sin(x + (PI / 3));
      printf("h(x) = %f\n", result);
    }
}  

int main(void)
{
  ft_calc1();
  ft_calc2();
  ft_calc3();
  exit(0);
}
