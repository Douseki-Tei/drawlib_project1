/*
author：清水慧悟
*/
/*
command
$ gcc typing.c -o typing -ldrawlib
$ ./typing < dictionary.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<drawlib.h>

void start();
void typing(char dict[100][20], int *number, int *total_time);

int main(){
  /*txt読み込みのための変数*/
  int r, i = 0;
  char dict[100][20];
  int number = 0, total_time = 0;
  /*txtファイルの読み込みを行う*/
  while(1){
    r = scanf("%s" , dict[i]);
    if (r < 0)
      break;
    i++;
  }
  dl_initialize(1.0);
  /*start画面に移動*/
  start();
  /*game画面に移動*/
  typing(dict,&number,&total_time);/*txtファイルから読み込んだ文字列や個数、時間を入力する*/
  printf("%d個の単語に対して%d秒かかりました\n", number, total_time);
  return 0;
}
/*start画面の描写*/
  void start(void){
    int x, y, t, k;
    dl_text("TYPING", 70, 180, 5, DL_C("black"), 3);
    dl_rectangle(100, 230, 580, 370, DL_C("red"),1,1);
    dl_text("START", 110, 350, 5, DL_C("black"), 3);
    while(1){
      if(dl_get_event(&t,&k,&x,&y)){
        if(t == DL_EVENT_L_DOWN){
          if(100 < x && x < 580 && 230 < y && y < 370){
            /*if文で指定した範囲を左クリックしたら次の画面に移動*/
            dl_clear(DL_C("white"));           
            break;
             }
          }
        }
     } 
  }
  
  void typing(char dict[100][20], int *number, int *total_time){
    time_t start_time, end_time;/*時間計測の変数宣言*/
    int randam, l, th, len;/*raodam：1~100を乱数によって生成,　len：文字列の長さ*/
    int x, y, t, k;/*イベント処理用変数*/
    char str[20];
    start_time = time(NULL);/*開始時間*/
    while(1){
      l = 50;/*l：入力した文字のx座標*/
      th = 0;
      srand((unsigned int)time(NULL));
      randam = rand() % 100+1;
      len = strlen(dict[randam]);/*文字列の長さを取得*/
      dl_text(dict[randam], 50, 160, 3, DL_C("black"), 3);
      dl_rectangle(420, 330, 620, 430, DL_C("red"),1,1);
      dl_text("END", 430, 410, 3, DL_C("black"), 3);     
      while(1){
        dl_resume();
        if(dl_get_event(&t,&k,&x,&y)){
          if(t == DL_EVENT_L_DOWN){
            /*'END'ボタンが押された時の処理*/
            if(420 < x && x < 620 && 330 < y && y < 430){
              dl_clear(DL_C("white")); 
              end_time = time(NULL);/*終了時間*/
              *total_time = end_time - start_time;/*かかった時間をmainに返す*/          
              return;
               }
          }else if(t == DL_EVENT_KEY){
                /*タイピングしたときの処理*/
            sprintf(str, "%c", k);
            if(k == DL_KEY_ENTER && len == th){
                  /* 表示した文字まで入力してENTERキーを押したときの処理*/              
              *number+=1;
              break;
            }else if(k == dict[randam][th]){
                  /*入力した文字が表示されている文字のnumber番目の
                    アルファベットと同じときの処理*/
              dl_text(str, l, 260, 3, DL_C("black"), 3);
              l += 50;/*表示させるx軸を50ずつずらす*/
              th++;
            }else{
                  /*入力した文字が表示されている文字のnumber番目の
                    アルファベットと違うときの処理*/
              dl_stop();
               }
             }
          }
        }
      dl_wait(1);
      dl_clear(DL_C("white"));
    }    
  }

