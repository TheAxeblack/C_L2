#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float x;
  float y;
  float z;
  float tmp;

  printf("Entrez 3 reels x, y, et z : \n");
  if (scanf("%f %f %f", &x, &y, &z) != 3)
    {
      printf("3 reels attendus\n");
      exit(-1);
    }
  else
    {
      printf("x = %f, y = %f et z = %f\n", x, y ,z);
      tmp = z;
      z = y;
      y = x;
      x = tmp;
      printf("x = %f, y = %f et z = %f\n", x, y ,z);
    }
  exit(0);
}
