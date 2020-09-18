#include <drawlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*プロトタイプ宣言*/
void init(void);	/*初期化用関数*/
/*ダイス描画用の関数　引数は　ダイスの中心座標x,y,表示する目,ダイスの大きさ*/
void disp_dice(int b_x,int b_y,int num,int b_siz);
/*各目の描画関数*/
void dice_1(int b_x, int b_y, int b_siz);
void dice_2(int b_x, int b_y, int b_siz);
void dice_3(int b_x, int b_y, int b_siz);
void dice_4(int b_x, int b_y, int b_siz);
void dice_5(int b_x, int b_y, int b_siz);
void dice_6(int b_x, int b_y, int b_siz);

int main(){
	int flg_play = 1;	/*ダイスのロール，ストップ用のフラグ*/
	int d_x = 0;	/*移動するダイスの初期位置*/
	int d_vx = 5;	/*移動するダイスの速度*/
	int x,y,t,k;	/*dl_get_event用の関数*/
	srand((unsigned int)time(NULL));/*ランダム*/

	init();

	while(1){
		/*イベントの取得　今回は何かしらのキー入力があった場合*/
		if(dl_get_event(&t, &k, &x, &y)){
			if(t==DL_EVENT_KEY){
					flg_play ^= 1;	/*フラグの1,0切り替え*/
			}
		}
		/*ダイスの描画　１：ロール　０：ストップ*/
		if(flg_play==1){
			dl_clear(DL_RGB(0,0,0));	/*画面の初期化*/
			disp_dice(220,240,rand()%6+1,100);	/*左側の中サイズのダイス*/
			disp_dice(420,240,rand()%6+1,150);	/*右側の大サイズのダイス*/
			disp_dice(d_x+=d_vx,100,rand()%6+1,50);	/*上で動いてる小サイズのダイス*/
			if(d_x>640 || d_x<0){	/*ダイスを動かすための関数　壁まで行ったら進行方向を逆に*/
				d_vx *= -1;
			}
		}
		dl_wait(0.1);
	}
	return 0;
}

void init(void){
	dl_initialize(1.0);
}

void disp_dice(int b_x,int b_y,int num,int b_siz){
	/*入力*/
	int siz = b_siz;
	int x = b_x;
	int y = b_y;
	/*入力された情報をもとに描画*/
	/*サイコロの四角部分　x,y,siz*/
	dl_rectangle(x-siz/2, y-siz/2, x+siz/2, y+siz/2, dl_color_from_rgb(255,255,255), 1, 1);
	/*numからサイコロの目を選択，描画*/
	switch(num){
		case 1:
		dice_1(x,y,siz);
		break;

		case 2:
		dice_2(x,y,siz);
		break;

		case 3:
		dice_3(x,y,siz);
		break;

		case 4:
		dice_4(x,y,siz);
		break;

		case 5:
		dice_5(x,y,siz);
		break;

		case 6:
		dice_6(x,y,siz);
		break;

		default:
		break;
	}
}

void dice_1(int b_x, int b_y, int b_siz){
	int x = b_x;
	int y = b_y;
	int siz = b_siz/2/2;
	int line = 1;
	int fill = 1;
	dl_circle(x,y,siz,dl_color_from_rgb(255,0,0),line,fill);
}

void dice_2(int b_x, int b_y, int b_siz){
	int x = b_x;
	int y = b_y;
	int siz = b_siz/3/2;
	int line = 1;
	int fill = 1;
	dl_circle(x-b_siz/4,y-b_siz/4,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/4,y+b_siz/4,siz,dl_color_from_rgb(50,50,50),line,fill);
}

void dice_3(int b_x, int b_y, int b_siz){
	int x = b_x;
	int y = b_y;
	int siz = b_siz/4/2;
	int line = 1;
	int fill = 1;
	dl_circle(x-b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x,y,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
}

void dice_4(int b_x, int b_y, int b_siz){
	int x = b_x;
	int y = b_y;
	int siz = b_siz/4/2;
	int line = 1;
	int fill = 1;
	dl_circle(x-b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x-b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
}

void dice_5(int b_x, int b_y, int b_siz){
	int x = b_x;
	int y = b_y;
	int siz = b_siz/4/2;
	int line = 1;
	int fill = 1;
	dl_circle(x-b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x-b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x,y,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
}

void dice_6(int b_x, int b_y, int b_siz){
	int x = b_x;
	int y = b_y;
	int siz = b_siz/4/2;
	int line = 1;
	int fill = 1;
	dl_circle(x-b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x-b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x-b_siz/3,y,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y+b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
	dl_circle(x+b_siz/3,y-b_siz/3,siz,dl_color_from_rgb(50,50,50),line,fill);
}

