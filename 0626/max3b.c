#include <stdio.h>

int main(void) {
  int x = 10, y = 20, z = 30, m;

  m = x;
  if (y > m) {
    m = y;
  }
  if (z > m) {
    m = z;
  }
  printf("最大値は%dです\n", m);

  return 0;
}
