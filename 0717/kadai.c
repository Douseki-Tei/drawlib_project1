#include <stdio.h>

int main(void) 
{
  /* 20文字の文字列を読み込むためには
     21個の配列の要素が必要です．*/
     
  char str[21];
  
  /* 変数は必要に応じて追加してください．*/

  /* 下記で配列 str に文字列を読み込むことができます．
     しかし，20文字を超える長さの文字列が入力されると
     不具合が発生することがあります．
     このままでもいいですが，20文字以内に制限する工夫を
     してもらうと加点になります． */
     
  printf("20文字以内の文字列を入力してください: ");
  scanf("%20s", str);


  while(*p != '\0')
  
  {
  
   if ('a' <= *p && *p <= 'z')
    {
      *p -= 'a' - 'A';
    }
   else
    {
      *p -= 'a' - 'A';
    }
    ++p;

  }
 
  
  printf("%s\n", str);
  

  return 0;
}
