/* 変数の例 */
#include <stdio.h>

int main(void) {
  /* 
     変数 x を宣言する．
     int は変数xの型を整数（正確には32ビット整数）
     にすると言う意味．
  */
  int x;

  /*
    一つの宣言文で複数の変数を宣言できる．
    その場合は変数名をカンマ区切りで複数並べる．
  */
  int y, z;

  /*
    変数名は，英数字を複数並べたものならなん
    でもよい（アルファベット1文字に限らない）．
    ただし，数字で始めることはできない．
    また，大文字やアンダースコア（_）を利用する
    こともできるが，できるだけ使わない方がよい．
  */
  int add, sub, mul, div, mod;

  /*
    変数は宣言時に初期化することができる．
    「初期化する」とは，初期値を与えることである．
    初期化しない場合，変数の初期値は不定（どんな値が
    入っているかはわからない）である．
    初期化する場合は，イコール（=）でその値を与える．
  */
  int sum = 10, dummy = 1000;

  /*
    注意: 変数宣言文は，関数定義の冒頭に書くのが
    原則．古いC言語のコンパイラでは途中に書くと
    エラーになることがある
  */

  /*
    代入文を使うことで，変数に値を代入することができる．
    イコール（=）を代入演算子と呼び，左辺の変数に右辺の
    値が代入される．
  */
  x = 10;

  /*
    代入文の右辺は，厳密には「式」でよい．
    式の計算結果が代入される．
    式を計算することを「評価する」と言う．
  */
  y = 20;

  /*
    変数を含む式を評価する際は，変数の値が利用される．
  */
  z = x + y;

  /*
    変数は関数呼び出しの引数（の式の一部）として
    利用することができる．
  */
  printf("%d + %d = %d\n", x, y, x + y);


  /*
    練習(1)
    -------
    変数 add, sub, mul, div, mod に，それぞれ
    x と y の足し算，引き算，かけ算，わり算，あまり
    の計算結果を代入し，その結果を標準出力に出力する
    プログラムを書いてみよう．
   */


  /*
    練習(2)
    -------
    初期化も代入もしていない，不定値をもつ変数の値を
    標準出力に表示するとどのようになるか確認してみよう．
  */
  
  
  return 0;
}
