#include <stdio.h>

int main (void) {
  /* 
     文字列（char型の配列）も宣言時に初期化することができます．
     文字列の場合は特別に，ダブルクォーテーション（"）で囲った
     文字列（文字列定数と呼ぶ）で初期化をすることができます．
     下の例では，"C Language"という文字列を使って str1 と str2 が
     初期化されています．目に見える文字は 10文字しかありませんが，
     文字列は必ずヌル文字と呼ばれるASCIIコードが0の文字で終わらせる
     約束になっています．したがって，この文字列を保持するために
     必要となる配列の要素数は11となります．
     str2では要素数を明示していませんが，自動的に11個の要素を
     持つように初期化されます．
   */
  char str1[11] = "C Language", str2[] = "C Language";
  int i;
  
  /*
    試しに，str1とstr2の要素を1つずつ，文字，および数値（16進数）で
    表示してみます．
    実行してみるとわかりますが，11番目の要素（str[10]）は，
    数値として表示すると 0 になり，文字としては何も表示されません．
  */
  for (i = 0; i < 11; i++) {
    printf ("str1[%02d] = %c (0x%02x), str2[%02d] = %c (0x%02x)\n",
	   		  i, str1[i], str1[i], i, str2[i], str2[i]);
  }

  /*
    printf関数で，文字列を表示する場合は，出力変換指定子に %s
    を使います．
   */
  printf ("printf: %s, %s\n", str1, str2);
  
  return 0;
}

