#include <stdio.h>

int main(void) {
  int x, y;
	
  printf("Input X: ");
  scanf("%d", &x);
  printf("Input Y: ");
  scanf("%d", &y);
	
  /*
    条件式は，二つの値（または式の評価結果）を
    比較演算子でつなげたものである．
    C言語の比較演算子には以下のものがある．
    a == b ... aとbの値は等しい（等値演算子）
               【注意】イコール記号は必ず2つ！
    a != b ... aとbの値は等しくない
    a > b ... aはbより大きい
    a < b ... aはbより小さい
    a >= b ... aはb以上である（等しいか大きい）
    a <= b ... aはb以下である（等しいか小さい）
               【注意】イコール記号は不等号の後！
  */
  if (x == y) {
    printf ("XとYは等しい\n");
  } else if (x != y) {
    printf ("XとYは等しくない\n");
  } else if (x > y) {
    printf ("XはYより大きい\n");
  } else if (x < y) {
    printf ("XはYより小さい\n");
  } else if (x >= y) {
    printf ("XはY以上\n");
  } else if (x <= y) {
    printf ("XはY以下\n");
  }
	
  /*
    練習(1)
    -------
    上の例では，どんな数値をいれても
    必ず二行以上出力される．
    その理由を考えよう．
  */

  /*
    練習(2)
    -------
    上の例に対して，else if節を使って
    1行だけ出力されるようにしてみよう．
    そのとき，いくつかの条件は意味がなく
    なる．どれの意味がなくなるかを考えよう．
  */
	
  return 0;
}
