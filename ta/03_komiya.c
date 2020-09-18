#include <stdio.h>
#include <stdlib.h>
#include <drawlib.h>
#include <time.h>

/*--表示する色---------------------------------------------------------------------------------------------------------------------------*/
#define dl_black dl_color_from_name("black")
#define dl_white dl_color_from_name("white")
#define dl_red   dl_color_from_name("red")
#define dl_blue  dl_color_from_name("blue")
#define dl_cyan  dl_color_from_name("cyan")

/*--表示する座標--------------------------------------------------------------------------------------------------------------------------*/
#define  lv1_x 50
#define  lv1_y 400
#define  lv2_x 200
#define  lv2_y 400
#define  lv3_x 350
#define  lv3_y 400
#define  deb_x 520
#define  deb_y 450
#define exit_x 540
#define exit_y 30

/*--表示する文字---------------------------------------------------------------------------------------------------------------------------*/
#define font_size_l 1.5
#define font_size_m 1
#define font_size_s 0.7
#define font_thick_l 1.5
#define font_thick_m 1
#define font_thick_s 0.5



int main (void) {
	
	char  str[10];
	int num = 0;		/*発生させる乱数の数*/
	int correct_ans;	/*問題の正解        */
	int ans;		/*ユーザの回答      */

	int a[20];	/*表示した数字を格納する*/
	int t,k;	/*dl_get_eventで使う*/
	
	int x ,y ;	/*各座標値を格納する変数*/
	int x1,y1;		
	int x2,y2;
	
	int count;	/*カウンター*/
	int mode=0;	/*mode0：デバックモード，mode1：初級，mode2：中級，mode3：上級*/
	float wait_time = 1;	/*待ち時間*/
	
	int num_min = 2;		/*発生させる乱数の下限数*/
	int num_max = 2;		/*発生させる乱数の上限数を決める．4ならrand%4が0～3なので2～5個*/

	
	
	
	dl_initialize(1.0);	/*画面初期化*/
	
	while(1){
	
		t = 0;			/*各値をリセットする*/
		correct_ans = 0;		//答えをリセット
		count = 1;		//カウンターリセット
		x  =  50;y  = 50;	//数値を表示する座標値をセット
		x1 = 150;y1 = 50;
	
		dl_rectangle( 0, 0, DL_WIDTH, DL_HEIGHT, dl_white, 0, 1);	/*画面を真っ白に*/

/*------------------------タイトル画面の表示--------------------------------------------*/

		dl_text("Flash Mental Arithmetic", 50, 150, font_size_l, dl_cyan, font_thick_l);
	
		dl_text("LEVEL 1",  lv1_x,  lv1_y, font_size_m, dl_black, font_thick_m);	//defineした値を基にボタンを描画
		dl_text("LEVEL 2",  lv2_x,  lv2_y, font_size_m, dl_black, font_thick_m);
		dl_text("LEVEL 3",  lv3_x,  lv3_y, font_size_m, dl_black, font_thick_m);
		dl_text(" debug ",  deb_x,  deb_y, font_size_s, dl_black, font_thick_s);
		dl_text(" exit " , exit_x, exit_y, font_size_s, dl_black, font_thick_s);
	
		dl_wait(0.1);
	
		while(1){
			if(dl_get_event(&t, &k, &x2, &y2)){
				
				//printf("x:%d y:%d, k:%d \n",x2,y2,k);	/*入力の確認用*/
			
				if(t==DL_EVENT_L_DOWN){			/*左クリックされた時，tはDL_EVENT_L_DOWN*/
					if( ((lv1_x-5)<=x2) && (x2<=(lv1_x+125)) && ((lv1_y-20)<=y2) && (y2<=(lv1_y+20)) ){	/*lv1_x=50,lv1_y=400のときx:45～175,y:380～420でtrue*/
						mode = 1;
						printf("mode1\n");
						break;
					}
					if( ((lv2_x-5)<=x2) && (x2<=(lv2_x+125)) && ((lv2_y-20)<=y2) && (y2<=(lv2_y+20)) ){
						mode = 2;
						printf("mode2\n");
						break;
					}
					if( ((lv3_x-5)<=x2) && (x2<=(lv3_x+125)) && ((lv3_y-20)<=y2) && (y2<=(lv3_y+20)) ){
						mode = 3;
						printf("mode3\n");
						break;	
					}
					if( ((deb_x-5)<=x2) && (x2<=(deb_x+80)) && ((deb_y-15)<=y2) && (y2<=(deb_y+15)) ){
						mode = 0;
						printf("debugMode\n");
						break;
					}
					if( ((exit_x)<=x2) && (x2<=(exit_x+50)) && ((exit_y-15)<=y2) && (y2<=(exit_y+5)) ){
						printf("終了します。\n");
						exit(0);	/*exitを押されたら終了する。exit(0)は正常に終了*/
					}
				}
			}
		}
	
		dl_rectangle( 0, 0, DL_WIDTH, DL_HEIGHT, dl_white, 0, 1);	/*画面をクリアに*/


/*------------------------モードの振り分け--------------------------------------------*/

		switch(mode){	/*modeによって表示時間や数字の数を変える*/
			case 0:
				wait_time = 2;
				num_min   = 2;
				num_max   = 2;	/*乱数は2～3個*/
				break;
		
			case 1:
				wait_time = 1.5;
				num_min   = 2;
				num_max   = 2;
				break;
		
			case 2:
				wait_time = 1;
				num_min   = 3;
				num_max   = 4;	/*乱数は3～6個*/
				break;
		
			case 3:
				wait_time = 0.5;
				num_min   = 6;
				num_max   = 4;	/*乱数は6～*/
				break;
		
			default:
				printf("mode値が不正です\n");
		
		}
	
	
		//printf("ModeCheck:%d\n",mode);	//モードのチェック
		
		srand((unsigned int)time(NULL));
		num = rand() % num_max + num_min;		/*num_max4,num_min2のとき，numは2～5*/
	
/*------------------------数の表示，正解の計算------------------------------------*/
		dl_wait(1);
	
		for(count; count <= num ; count++){
			dl_rectangle( 0, 0, DL_WIDTH, DL_HEIGHT, dl_white, 0, 1);
			a[count] = rand() % 100;					/*100で割った余り（0～99）         */
			correct_ans = a[count] + correct_ans;				/*正解を計算する                   */
			sprintf(str,"%d",a[count]);					/*strにaを格納（dl_textで扱うため）*/
	
			dl_text(str, x, y, 1.0, dl_blue, 1);
			

			if(mode==0){	
				sprintf(str,"%d Numbers",count);			
				dl_text(str, 515, 455, font_size_s, dl_black, font_thick_s);	/*乱数の個数を確認*/
			}
		
			dl_wait(wait_time);	/*難易度によって表示時間を変える*/
			
		}
			
		dl_rectangle( 0, 0, DL_WIDTH, DL_HEIGHT, dl_white, 0, 1);
	
		printf("合計値は？\n");
		scanf("\n%d",&ans);	/*ユーザ入力の方法もいろいろある*/
	
/*------------------------答えの確認------------------------------------------*/	
		if(mode==0){
			printf("User   :%d\n",ans);		//確認用
			printf("correct:%d\n",correct_ans);	//確認用
		}
	
		if(ans==correct_ans){	/*もし正解なら*/
			if(mode==3)	/*かつmode3なら*/
				dl_text( "Great!!",250,250,font_size_l,dl_black,font_thick_l);
			else			/*mode3でないなら*/
				dl_text(   "true!",250,250,font_size_l,dl_black,font_thick_l);
		}else{			/*正解でないなら*/
			dl_text("false...",250,240,font_size_l,dl_black,font_thick_l);
			dl_text("Let's try again",210,270,font_size_m,dl_black,font_thick_l);
		}

/*------------------表示した数と答えの表示-------------------------------------------------*/
	int x1 = 100,y1 = 360;
	for(int i=1;i<=num ;i++){
		x1 = x1 + 50;		/*表示する座標をずらして被らないようにする*/
		sprintf(str,"%d",a[i]);
		dl_text(str, x1, y1, font_size_s, dl_red, font_thick_m);	
	}
	sprintf(str,"answer:%d",correct_ans);
	dl_text(str, 450, 400, font_size_m, dl_red, font_thick_m);

/*-----------------------エンディングの表示-------------------------------------------*/
	
	
		dl_wait(2);
	
		t = 0;

		dl_text("Click window to continue...",50,420,1.0,dl_black,1.5);	/*クリックされたら続けます...*/

		while(1){
			if(dl_get_event(&t, &k, &x2, &y2)){
				if(t==DL_EVENT_L_DOWN)
					break;		/*whileの先頭へ行く*/
			}
		}
	
	}
	return 0;
}

