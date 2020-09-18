#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <drawlib.h>

int main(){
     /*プロタイプ宣言*/
    dl_initialize(1.5);
    char x, y, z, p;
    int a, b, c , user_input , input_count = 1;
    int row = 30;
    int column = 80;
    int eat_count, bite_count;

     /* 3桁の乱数値を生成 */
    srand((unsigned int)time(NULL));
    x = (char)(rand()%10);
    do {
        y = (char)(rand()%10);
    } while(y == x);
    do {
        z = (char)(rand()%10);
    } while(z == x||z == y);

    /* Answer */
    printf("x:%d,y:%d,z:%d\n",x,y,z);


    dl_text("Numer0n",row - 15, column - 30, 1.5, dl_color_from_name("red"), 3);
    dl_text("count",  row - 15, column, 0.7, dl_color_from_name("red"), 2);
    dl_text("input",  row + 110, column, 0.7, dl_color_from_name("red"), 2);
    dl_text("EAT - BITE",row + 200,column,0.7,dl_color_from_name("red"),2);


    for (;;) {
          /* ユーザの入力を1の位、10の位、100の位に分割 */
        scanf("%3d", &user_input);
        a = user_input / 100;
        b = user_input % 100 / 10;
        c = user_input % 10;

        char str_user_input[16];
        char str_input_count[16];
        char colon[] = " : ";
        char hyphen[] = "-";
        char eat_bite[16];
        int column_space = column + (input_count * 35);


        sprintf(str_user_input,"%d %d %d",a,b,c);
        sprintf(str_input_count,"%d %s ",input_count,colon);
        printf("%s\n",str_user_input);
        dl_text(str_input_count,row,column_space,1.0,dl_color_from_name("red"),3);
        dl_text(str_user_input,row + 90,column_space,1.0,dl_color_from_name("red"),3);

          /* 不正な入力値をはじいて再度入力を促す */
        if (user_input < 12||user_input > 987||a == b||a == c||b == c){
            printf("再度入力お願いします\n");
            dl_text("retry",row + 230,column_space,1.0,dl_color_from_name("blue"),3);
            
           }
        else{
                /* 「イート」の数 */
            eat_count = 0;
            if (a == x) eat_count++;
            if (b == y) eat_count++;
            if (c == z) eat_count++;

                /* 「バイト」の数 */
            bite_count = 0;
            if (a == y || a == z) bite_count++;
            if (b == x || b == z) bite_count++;
            if (c == x || c == y) bite_count++;
            
            if (eat_count != 3){
                printf("%d-%d\n", eat_count, bite_count);
                sprintf(eat_bite,"%d %s %d",eat_count,hyphen,bite_count);
                dl_text(eat_bite,row + 210,column_space,1.0,dl_color_from_name("blue"),3);
                }
            else {
                puts("Hit!\n");
                while(1){
                    sprintf(eat_bite,"%d %s %d",eat_count,hyphen,bite_count);
                    dl_text(eat_bite,row + 210,column_space,1.0,dl_color_from_name("blue"),3);
                    dl_text("Hit!!!",row + 350,column_space,1.0,dl_color_from_name("blue"),3);
                    dl_wait(0.1);
                    dl_text(eat_bite,row + 210,column_space,1.0,dl_color_from_name("red"),3);
                    dl_text("Hit!!!",row + 350,column_space,1.0,dl_color_from_name("red"),3);
                    dl_wait(0.1);
                     }
                }
        }input_count++;
     }return 0;
}









