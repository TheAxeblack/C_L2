#include <MLV/MLV_all.h>

int main(int argc, char **argv)
{
  MLV_create_window("rectangle.c", "tp8", 640, 480);

  MLV_draw_filled_rectangle(300, 220, 150, 70, MLV_COLOR_RED);

  MLV_actualise_window();

  MLV_wait_seconds(10);
}
