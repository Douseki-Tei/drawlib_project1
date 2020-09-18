#include <drawlib.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  /* 要素数10で、0〜100のint型の配列 */
  int values[10] = {82, 15, 32, 75, 24, 10, 42, 68, 93, 67};
  int i, j, k, s;
  int x1, y1, x2, y2;
  /* 変数は自由に増やして良いが，その他は変更しないこと */
  
  dl_initialize(1.0);

  while (1) {
    /* --- ここから変更可 --- */

    v=9;
    while(1)
    {
    
    for (i = 0; i < v; i++) 
    
    {
      /* i番目とi+1番目を入れ替える */
    
     if (values{i}>values[i+1])
     {
      
      s = values[i];
      values[i] = values[i+1];
      values[i+1] = s;
      
     }
      /* --- ここまで変更可 --- */

      /* --- ここから変更しない --- */
      dl_stop();
      dl_clear(DL_C("white"));
      for(k = 0; k < 10; k++) {
	x1 = k * 60 + 20;
	x2 = x1 + 50;
	y1 = 440;
	y2 = 440 - values[k] * 4;
	dl_rectangle(x1, y1, x2, y2, 
		     DL_RGB(100, 100, 56 + 2 * values[k]), 1, 1);
      }
      dl_resume();
      dl_wait(0.1);
      /* --- ここまで変更しない --- */
      /* --- ここから変更可 --- */ 
    }
     
     v=v-1
    if(v==0)
    
    {
     break;
    }
   }
    
    /* --- ここまで変更可 --- */
    /* --- これ以降変更しない --- */
    dl_wait(1.0);
    for (i = 0; i < 10; i++) {
      values[i] = random() % 90 + 10;
    }
  }
  while(1) {
    dl_wait(1.0);	
  }
  return 0;
}
