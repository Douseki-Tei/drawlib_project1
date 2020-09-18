#include <stdio.h>

int main(void) {
  int x = 10, y = 20, z = 30;

  if (x > y && x > z) {
    printf("最大値は%dです\n", x);
  } else if (y > z) {
    printf("最大値は%dです\n", y);
  } else {
    printf("最大値は%dです\n", z);
  }
    
  return 0;
}
