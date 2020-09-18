/* 一次方程式のクイズ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int xa, a, b, x;
  
  /* 次の行はxa, a, bをランダムな数字にするため処理です．
     今は理解する必要はないので無視してください */
  srand((unsigned int)time(NULL));
  xa = rand() % 100;
  a = rand() % 28 + 3;
  b = rand() % 30 - 15;
  
  /* 
     ここまでの実行で，
     xa には0〜99，
     a には3〜30，
     b には-15〜14
     の整数がランダムに代入されている．
		
     標準出力に，
     「x * a + b = ○○のときのxを答えろ」，
     という問題を表示し，実際に入力させて正解か
     どうか判定して判定結果を表示するプログラム
     を作成してください．
     （上記の問題表示の際，a，b，○○適切な数字に
       直すこと）
     例えば，xaが2で，aが3，bが5のときは
     「x * 3 + 5 = 11 のときのxを答えよ」
     と表示し，入力結果が2と等しいか判定すればよい．
  */
  printf("X * %d + %d = %d の時のXを答えろ\n", a,b,xa*a+b);
  printf("input X: ");
  scanf("%d", &x);

  if(x==xa)
  {
   printf("正解\n");
  {
  else
   printf("不正解\n");
  }


  return 0;
}
