/* 整数型と浮動小数点型 */
#include <stdio.h>

int main(void) {
  /* 
    整数型には，short，int，long の3種類がある．
    異なる型の変数を宣言する際は，宣言文を複数書く
    必要がある．
  */
  short is = 10;
  int ii = 10;
  long il = 10;
  
  /*
    浮動小数点型には，float と double の2種類がある．
    浮動小数点型の変数は，実数を扱うことができる．
  */
  float ff = 10.2;
  double fd = 10.2;

  /*
    整数型には，符号ありと符号なしの2種類が存在する．
    宣言時に，符号ありの場合は signed，
    符号なしの場合は unsigned をつける．
    省略した場合は符号ありと見なされる．
    符号なし整数型の変数では，負の数が扱えない．
  */
  unsigned short ius = 10;
  unsigned int iui = 10;
  unsigned long iul = 10;

  /*
    同じ整数型でも，型によって扱える値の範囲が異なる．
    short型は，-32768〜32767
    int型は，-2147483648〜2147483647
    が扱える．詳しくは参考資料を見て欲しい．
  */
  is = 32000;
  ii = 2100000000;
  il = 9200000000000000000;

  /*
    型によって出力変換指定子を変更する必要がある．
    short型の場合は %hd，long型の場合は %ld にする．
    符号なし整数型の場合は， %hu, %u, %lu などとする．
  */
  printf("%hd, %d, %ld\n", is, ii, il);
  printf("%hu, %u, %lu\n", ius, iui, iul);

  /*
    浮動小数点型の場合，
    float型は %f ，double型は %df にする．
  */
  printf("%f, %lf\n", ff, fd);

  /*
    練習(1)
    -------
    浮動小数点型の値で，わり切れない数のわり算を
    計算し，結果を確認してみよう
  */

  /*
    練習(2)
    -------
    特に浮動小数点型の値を printf で表示した際に
    小数点以下の桁が多すぎて見た目がよくない．
    示する桁を調整してみよう．
    %f の間に数字を入れて %10f や %10.5f などと
    すると調整できる．
  */

  /*
    練習(3)
    -------
    整数型の変数に，扱える範囲を超える値を入れようと
    するとどうなるか確認してみよう．
    また，そうした後にどのような値になっているか表示して
    確認してみよう．
    例えば，short型の変数に 60000 （6万）を代入してみよう．
  */

  return 0;
}