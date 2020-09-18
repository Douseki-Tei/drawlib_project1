/* roulette.c
ルーレットで遊ぶプログラム
何食べるか決められないときに使ってください
==================================================
Usage:
  $ gcc roulette.c -o roulette -ldrawlib -lm
  $ ./roulette
Keys:
    enter, 左クリック    - 減速
    space, 右クリック    - リスタート
    q                   - 終了
--------------------------------------------------
__autor__='TAKAHASHI_Masaharu'
__version__='1.0.0'
__data__='2020/07/17' */

#include <drawlib.h>
#include <stdio.h>
#include <math.h>
double angle2rad(int a);
void draw_roulette(int ox, int oy, int r, int num_items, char **ptr);

int main(void) {
  float wait_time = 0.01;
  char *items[] = {"Apple", "Pineapple", "Lemmon", "Paprika", NULL}; /* ルーレットの要素(好きに増やせます) */
  char **ptr = items;
  int num_items; /* 要素数*/

  int originx = DL_WIDTH / 2 , originy = DL_HEIGHT / 2; /* 原点座標 */
  int r = 200; /* 回転させる線の長さ */
  int theta = 0;  /* 回転させる角度 */
  double rad = 0.0; /* thetaのラジアン表記 */
  double dtheta = 10; /* 角速度 */
  double ddtheta = -0.05; /* 角加速度 */
  int fg = 0; /* 減速モードに入るためのフラグ */

  int t, k, x, y; /* イベント処理変数 */

  for (num_items=0; *ptr != NULL; ptr++, num_items++); /* NULLが出てくるまで要素数をカウントしてnum_itemsに格納(今回は3)*/

  dl_initialize(1.0);
  
  while (1) {
    while (dl_get_event(&t, &k, &x, &y)) {
      if (t == DL_EVENT_KEY) {
        if (k == 113) /* q押下で終了 */
          return 0;
        else if (k == 10) /* enter押下で減速 */
          fg = 1; /* 減速モードフラグON */
        else if (k == 32) { /* space押下でrestart */
          dtheta = 10;
          fg = 0;
        }
      }
      if(t == DL_EVENT_L_DOWN) /* 左クリックでも減速 */
        fg = 1;
      else if(t == DL_EVENT_R_DOWN) {
        dtheta = 10; /* 右クリックでもrestart */
        fg = 0;
      }
    }
    if (theta >= 360) /* 頭打ち処理 */
      theta = 0;
    rad = angle2rad(theta);
    theta += dtheta;
    if (fg && dtheta > 0) /* 減速処理 */
      dtheta += ddtheta;
    if (dtheta < 0){ /* 停止処理 */
      dtheta = 0;
      fg = 0;
    }

    dl_stop();
    dl_clear(DL_C("white"));
    dl_line(originx, originy, originx + r * cos(rad), originy + r * sin(rad), DL_C("blue"), 2);
    dl_circle(originx, originy, r, DL_C("black"), 1, 0);
    draw_roulette(originx, originy, r, num_items, items);
    dl_resume();

    dl_wait(wait_time);
  }

  return 0;
}

double angle2rad (int angle) {
  /*
  度数法から弧度法への変換
  angle: 度数表記の角度
  return: ラジアン変換された値
  */
  return angle * 3.14 / 180;
}

void draw_roulette(int ox, int oy, int r, int num_items, char **ptr) {
  /*
  ルーレットの描画
  ox: 中心のx座標
  oy: 中心のy座標
  r:  ルーレット半径
  num_items: 要素数
  ptr: 文字列配列ポインタのポインタ
  */
  int i;
  int start, end, middle;
  for (i = 0; i < num_items; i++) {
    start = 360 * i / num_items - 90; /* 0時方向から描画したいので-90で調整 */
    end = 360 * (i+1) / num_items - 90; 
    middle = (start + end) / 2; /* 要素名は仕切り線の中間地点に配置 */

    dl_line(ox, oy, ox + r * cos(angle2rad(start)), oy + r * sin(angle2rad(start)), DL_C("black"), 1); /* 仕切り線 */
    dl_text(*ptr, ox + r*2/3 * cos(angle2rad(middle)), oy + r*2/3 * sin(angle2rad(middle)), 0.8, DL_C("black"), 2); /* 要素名 */
    ptr++;
  }
}