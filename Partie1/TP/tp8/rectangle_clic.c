#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int x;
  int y;
  int i;
  int x_s;
  int y_s;
  int w;
  int h;

  MLV_create_window("rectangle_clic.c", "tp8", 640, 480);

  i = 0;
  x_s = 10;
  y_s = 10;
  w = 200;
  h = 120;
  
  do
  {
    if (i % 2 == 0)
    {
      MLV_draw_filled_rectangle(x_s, y_s, w, h, MLV_COLOR_RED);
    }
    else
    {
      MLV_draw_filled_rectangle(x_s, y_s, w, h, MLV_COLOR_BLUE);
    }
    i++;
    MLV_actualise_window();
    MLV_wait_mouse(&x, &y);
  } while ((x >= x_s && x <= (x_s + w)) && (y >= y_s && y <= (y_s + h)));
  MLV_free_window();
  exit(EXIT_SUCCESS);
}
