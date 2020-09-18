#include <drawlib.h>

int main(void) {
  dl_initialize(1.0);

  dl_line(50, 50, 100, 50, dl_color_from_name("yellow"), 3);

  dl_line(50, 50, 20, 120, dl_color_from_name("yellow"), 3);

  dl_line(100, 50, 75, 100, dl_color_from_name("yellow"), 3);

  dl_line(75, 100, 100, 100, dl_color_from_name("yellow"), 3);

  dl_line(20, 120, 50, 120, dl_color_from_name("yellow"), 3);

  dl_line(100, 100, 35, 175, dl_color_from_name("yellow"), 3);

  dl_line(50, 120, 35, 175, dl_color_from_name("yellow"), 3);

  while (1) {
     dl_wait(0.01);
  }

 return 0;
}

