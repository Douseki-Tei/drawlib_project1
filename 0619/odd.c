#include <stdio.h>

int main(void) {
  int x = 31;

  if (x % 2 == 1) {
    printf("%4dは奇数\n", x);
  }	

  /*
    練習
    ----
    x の値を奇数にしたときにどのようになるか
    確認してみよう
  */
  return 0;
}
