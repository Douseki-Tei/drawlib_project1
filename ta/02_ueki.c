/*
author: 植木文弘
*/

#include <stdio.h>
#include <stdlib.h>
#include <drawlib.h>

/* 
ボタンの表示。
button_position: ボタンの配置座標が入った配列
                (左上のx座標, 左上のy座標, 右下のx座標, 右下のy座標)。
text: ボタンに表示する文字。
button_color: ボタンの色。
text_color: ボタンに表示する文字の色。
*/
void draw_button(int *button_position, 
    char *text, char *button_color, char *text_color);

/*
ボタンが押されたか判定をする。
button_position: ボタンの座標が入った配列。
x: マウスがクリックされたx座標の値。
y: マウスがクリックされたy座標の値。
return: 1: 押された, 0: 押されていない，-1: 意図しない結果を得た場合
*/
int push_button(int *button_position, int x, int y);

/*
スタート画面の表示。
ここで、クイズを開始するか終了するかボタンで判定する。
return: 開始: 1, 終了: 0
*/
int proc_start_menu(void);

/*
クイズを出題する処理。
return: 不正解の場合は0が返却される。
*/
int proc_quiz(void);

int main(void)
{
    /* スタート画面での判定結果を入れる変数。 */
    int result_start_menu = 0; 

    /* drawlibの初期化。 */
    dl_initialize(1.0); 

    /* 終了の指示があるまで無限ループ。 */
    while(1){

        /* スタート画面を表示し、クイズを開始するか終了するか判断する。 */
        result_start_menu = proc_start_menu();

        if(result_start_menu == 0){
            /* finishボタンを押された場合はプログラムを終了する。*/
            printf("finish.!!\n");
            break;
        }else if (result_start_menu == 1){
            /* startボタンを押された場合はクイズの出題画面に移動。 */

            printf("game start.!!\n");

            /* クイズの出題を行う関数へ */
            proc_quiz();
        }

    }

    return 0;
}

/* 
ボタンの表示。
button_position: ボタンの配置座標が入った配列
                (左上のx座標, 左上のy座標, 右下のx座標, 右下のy座標)。
text: ボタンに表示する文字。
button_color: ボタンの色。
text_color: ボタンに表示する文字の色。
*/
void draw_button(int *button_position, 
    char *text, char *button_color, char *text_color)
{

    int x1, x2, y1, y2;

    x1 = button_position[0];
    y1 = button_position[1];
    x2 = button_position[2];
    y2 = button_position[3];

    /* ボタンの表示。 */
    dl_rectangle(x1, y1, x2, y2, 
        dl_color_from_name(button_color), 1, 1);

    /* ボタンのテキストを表示。 */
    dl_text(text, x1 + 35, y1 + 35, 1.0, 
        dl_color_from_name(text_color), 2);

}

/*
ボタンが押されたか判定をする。
button_position: ボタンの座標が入った配列。
x: マウスがクリックされたx座標の値。
y: マウスがクリックされたy座標の値。
return: 1: 押された, 0: 押されていない，-1: 意図しない結果を得た場合
*/
int push_button(int *button_position, int x, int y)
{
    /* クリックされた座標がボタンの座標内であった場合、
       ボタンが押されたと判断する。                 */
    if(button_position[0] <= x && x <= button_position[2] &&
            button_position[1] <= y && y <= button_position[3]){
        return 1;
    }else{
        return 0;
    }

    return -1;
}

/*
スタート画面の表示。
ここで、クイズを開始するか終了するかボタンで判定する。
return: 開始: 1, 終了: 0
*/
int proc_start_menu(void)
{
    /* 開始ボタンの位置を定義。 */
    int position_start_button[4] = {100, 300, 250, 350}; 

    /* 終了ボタンの位置を定義。 */
    int position_finish_button[4] = {400, 300, 550, 350};

    /* イベント関連の変数 */
    int mouse_x = 0;
    int mouse_y = 0;
    int key = 0;
    int event_type = 0;

    /* 背景を黒に設定。 */
    dl_clear(dl_color_from_name("black")); 

    /* メッセージの表示 */
    dl_text("Are you ready ?!!", 150, 240, 1.0, 
        dl_color_from_name("white"), 2);

    /* 開始ボタンの表示。 */
    draw_button(position_start_button, "start", "red", "white");

    /* 終了ボタンの表示。 */
    draw_button(position_finish_button, "finish", "blue", "white");

    /* startボタンもしくはfinishボタンどちらが押されたか判定する。 */
    while(1){

        if(dl_get_event(&event_type, &key, &mouse_x, &mouse_y)){

            switch(event_type){

                /* マウスの左クリックにのみ反応する */
                case DL_EVENT_L_DOWN:
                    /* スタートボタンを押したか判定。 */
                    if(push_button(position_start_button, 
                                    mouse_x, mouse_y) == 1){
                        /* 背景を白く塗りつぶして、2秒待ってから終了。 */
                        dl_clear(dl_color_from_name("white")); 
                        dl_wait(2);
                        return 1;
                    }else if(push_button(position_finish_button, 
                                            mouse_x, mouse_y) == 1){
                        /* 背景を白く塗りつぶして、2秒待ってから終了。 */
                        dl_clear(dl_color_from_name("white")); 
                        dl_wait(2);
                        return 0;
                    }
                break;
            }

            /* たまったイベントを消化する。 */
            while(1){
                if(dl_get_event(&event_type, &key, &mouse_x, &mouse_y) == 0) break;
            } 
        }


        dl_wait(0.5);
    }
    
    return 0;
}

/*
クイズを出題する処理。
return: 不正解の場合は0が返却される。
*/
int proc_quiz(void)
{
    /*  イベント関連の変数。 */
    int mouse_x = 0;
    int mouse_y = 0;
    int key = 0;
    int event_type = 0;

    /* 分子を乱数によって生成する(1~100) */
    int nume = rand() % 100 + 1;
    
    /* 分母を乱数によって生成する(1~10) */
    int denom = rand() % 10 + 1;

    /* ウィンドウを更新するか判断する変数。
       1: 更新する。
       0: 更新しない。                */
    int flag_update_window = 1;

    /* ボタンの位置 */
    int position_true_button[4] = {170, 400, 320, 450};
    int position_false_button[4] = {320, 400, 470, 450};

    /* 画面に表示する問題文 */
    char message[200];

    while(1){

        if(flag_update_window == 1){
            /* ウィンドウを更新する処理。 */
            flag_update_window = 0;
            nume = rand() % 100 + 1;
            denom = rand() % 10 + 1;

            dl_stop();

            /* 背景を黒に設定。 */
            dl_clear(dl_color_from_name("black")); 

            /* ボタンを表示 */
            draw_button(position_true_button, "True", "red", "white");
            draw_button(position_false_button, "False", "blue", "white");

            sprintf(message, "%d %% %d == 0", nume, denom);

            /* 問題文の表示 */
            dl_text(message, 120, 240, 2.0, 
                dl_color_from_name("white"), 2);
            
            dl_resume();

            /* たまったイベントを消化する。 
               ここでイベントを消化することで，
               更新中に発生したイベントを無効化できる。 */
            while(1){
                if(dl_get_event(&event_type, &key, &mouse_x, &mouse_y) == 0) break;
            }

        }

        /* イベントが発生した場合の処理 */
        if(dl_get_event(&event_type, &key, &mouse_x, &mouse_y)){

            switch(event_type){

                /* マウスの左クリックにのみ反応する */
                case DL_EVENT_L_DOWN:

                    if(push_button(position_true_button, mouse_x, mouse_y) == 1){
                        /* Trueボタンが押された場合の処理。 */

                        /* 問題に正解していたら、update_windowに1を代入。
                           不正解の場合は0を返して終了。                 */
                        if(nume % denom == 0){
                            flag_update_window = 1;
                        }else{
                            return 0;
                        }

                    }else if(push_button(position_false_button, mouse_x, mouse_y) == 1){
                        /* Falseボタンが押された場合の処理。 */

                        /* 問題に正解していたら、update_windowに1を代入。
                           不正解の場合は0を返して終了。                 */
                        if(nume % denom == 0){
                            return 0;
                        }else{
                            flag_update_window = 1;
                        }

                    }
                break;
            }

            /* たまったイベントを消化する。 */
            while(1){
                if(dl_get_event(&event_type, &key, &mouse_x, &mouse_y) == 0) break;
            }
        }

        dl_wait(0.5);
    }

    return 0;
}