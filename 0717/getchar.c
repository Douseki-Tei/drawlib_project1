#include <stdio.h>

int main (void) {
  char c1, c2;

  /*
    getchar関数は，呼び出されると（scanfと同様）
    入力待ち状態になる．
    その間，入力された文字はバッファと呼ばれる
    一時保存領域に読み込まれる．
    エンターキーが入力されるか，バッファがあふれると
    getchar関数が終了し，戻ってくる．
    戻り値にはバッファの中に保存されている一番
    古い文字の文字コードが与えられる．
    （scanfと異なりエンターに相当する改行文字も
      戻り値となる）
    戻り値として与えられた文字は，バッファから消去される．
  */
  printf ("1文字入力してください: ");
  c1 = getchar ();
  printf ("c = %c, c = 0x%02x\n", c1, c1);

  /*
    getchar関数はバッファが空でなければ即座に
    最も古い文字を戻し，バッファから消去した上で
    終了する */
  printf ("1文字入力してください: ");
  c2 = getchar ();
  printf ("n = %c, n = 0x%02x\n", c2, c2);

  return 0;
}
