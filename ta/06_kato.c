#include <drawlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
 int x, y, t, k, a=0, eye=-300, eyebrow=-300, mouth=-300;
 dl_initialize(1.0);

 while (1) {

/*お手本ぴえんの描画*/
  dl_clear(DL_RGB(255,255,255));

  dl_circle (200, 200, 100, dl_color_from_name("yellow"), 1, 1);

  dl_circle (158, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (242, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (150, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (234, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (160, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (244, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (172, 192, 3, dl_color_from_name("white"), 1, 1);
  dl_circle (256, 192, 3, dl_color_from_name("white"), 1, 1);

  dl_line(120, 166, 136, 158, dl_color_from_name("black"), 3);
  dl_line(136, 159, 150, 144, dl_color_from_name("black"), 3);

  dl_line(280, 166, 264, 158, dl_color_from_name("black"), 3);
  dl_line(264, 159, 250, 144, dl_color_from_name("black"), 3);

  dl_line(185, 260, 189, 253, dl_color_from_name("black"), 3);
  dl_line(189, 253, 200, 248, dl_color_from_name("black"), 3);
  dl_line(215, 260, 211, 253, dl_color_from_name("black"), 3);
  dl_line(211, 253, 200, 248, dl_color_from_name("black"), 3);

  dl_wait(0.01);

/*ひだりクリックでとめる*/
  if(dl_get_event(&t, &k, &x, &y) && t == DL_EVENT_L_DOWN)
   break ;
  }

 while (1) {
/*ぴえん目の移動*/
  dl_clear(DL_RGB(255,255,255));

  eye = eye + 1 ;

  dl_circle (200, 200, 100, dl_color_from_name("yellow"), 1, 1);

  dl_circle (158 + eye, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (242 + eye, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (150 + eye, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (234 + eye, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (160 + eye, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (244 + eye, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (172 + eye, 192, 3, dl_color_from_name("white"), 1, 1);
  dl_circle (256 + eye, 192, 3, dl_color_from_name("white"), 1, 1);

  dl_wait(0.01);

  if(dl_get_event(&t, &k, &x, &y) && t == DL_EVENT_L_DOWN)
   break ;
  }

 while (1) {
/*ぴえん眉の移動*/
  dl_clear(DL_RGB(255,255,255));

  eyebrow = eyebrow + 1 ;

  dl_circle (200, 200, 100, dl_color_from_name("yellow"), 1, 1);

  dl_circle (158 + eye, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (242 + eye, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (150 + eye, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (234 + eye, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (160 + eye, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (244 + eye, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (172 + eye, 192, 3, dl_color_from_name("white"), 1, 1);
  dl_circle (256 + eye, 192, 3, dl_color_from_name("white"), 1, 1);

  dl_line(120 + eyebrow, 166, 136 + eyebrow, 158, dl_color_from_name("black"), 3);
  dl_line(136 + eyebrow, 159, 150 + eyebrow, 144, dl_color_from_name("black"), 3);

  dl_line(280 + eyebrow, 166, 264 + eyebrow, 158, dl_color_from_name("black"), 3);
  dl_line(264 + eyebrow, 159, 250 + eyebrow, 144, dl_color_from_name("black"), 3);

  dl_wait(0.01);

  if(dl_get_event(&t, &k, &x, &y) && t == DL_EVENT_L_DOWN)
   break ;
  }

 while (1) {
/*ぴえん口の移動*/
  dl_clear(DL_RGB(255,255,255));

  mouth = mouth + 1 ;

  dl_circle (200, 200, 100, dl_color_from_name("yellow"), 1, 1);

  dl_circle (158 + eye, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (242 + eye, 192, 32, dl_color_from_name("black"), 1, 1);
  dl_circle (150 + eye, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (234 + eye, 180, 15, dl_color_from_name("white"), 1, 1);
  dl_circle (160 + eye, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (244 + eye, 205, 5, dl_color_from_name("white"), 1, 1);
  dl_circle (172 + eye, 192, 3, dl_color_from_name("white"), 1, 1);
  dl_circle (256 + eye, 192, 3, dl_color_from_name("white"), 1, 1);

  dl_line(120 + eyebrow, 166, 136 + eyebrow, 158, dl_color_from_name("black"), 3);
  dl_line(136 + eyebrow, 159, 150 + eyebrow, 144, dl_color_from_name("black"), 3);

  dl_line(280 + eyebrow, 166, 264 + eyebrow, 158, dl_color_from_name("black"), 3);
  dl_line(264 + eyebrow, 159, 250 + eyebrow, 144, dl_color_from_name("black"), 3);

  dl_line(185 + mouth, 260, 189 + mouth, 253, dl_color_from_name("black"), 3);
  dl_line(189 + mouth, 253, 200 + mouth, 248, dl_color_from_name("black"), 3);
  dl_line(215 + mouth, 260, 211 + mouth, 253, dl_color_from_name("black"), 3);
  dl_line(211 + mouth, 253, 200 + mouth, 248, dl_color_from_name("black"), 3);

  dl_wait(0.01);

  if(dl_get_event(&t, &k, &x, &y) && t == DL_EVENT_L_DOWN)
   break ;
  }

/*ぴえんスコアの表示*/

/*お手本とのズレを100点満点から1ピクセルごとに減点*/
 int score = 100 - abs(eye) - abs(eyebrow) - abs(mouth);
/*int型の点数をchar型に変換*/
 char cscore[12];
 snprintf(cscore, 12, "%d", score);
 
 char pien[] = "PIEN";

 while(1){
  dl_text(cscore, 30, 380, 3, dl_color_from_name("black"), 3);
  dl_text(pien, 150, 380, 3, dl_color_from_name("black"), 3);
  if(dl_get_event(&t, &k, &x, &y) && t == DL_EVENT_L_DOWN)
   break ;
 }

 return 0;
}