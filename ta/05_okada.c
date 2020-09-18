#include <stdio.h>
#include <drawlib.h>
#include <math.h>

/*使用する色を定義しておく*/
#define dl_Black dl_color_from_name("black")
#define dl_White dl_color_from_name("white")
#define dl_Red   dl_color_from_name("red")
#define dl_Blue   dl_color_from_name("blue")
#define dl_Green   dl_color_from_name("green")

/*(x_f,y_f)最初の座標,(x_c,y_c)変化の座標*/
int x_f, y_f, x_c, y_c; 
int color = 0;
int color1;

int y_frame = 0, under = DL_HEIGHT, x_frame = 160, x_right = 640;

int circle_size = 50;

void click();


int main(void){
  
  dl_initialize(1.0);
  
  while(1){/*w1*/
    while(1){/*w2*/
		
      click();
            
            if(color == 0)color1 = dl_Red;
            else if(color == 1)color1 = dl_Blue;
            else if(color == 2)color1 = dl_Green;
            
              /*図形の描画*/
          dl_circle(x_c,y_c,circle_size,color1,1,0);
          dl_rectangle(x_f,y_f,x_c,y_c,color1,1,0);
         
          
      dl_wait(0.01);
     }/*w2*/
   }/*w1*/
  return 0;
}

/*マウスやキーボードによる動作*/
void click(){
  /*dl_get_eventの引数*/
  int t,k,x,y;
  if (dl_get_event(&t, &k, &x, &y)) {
      
      /*それぞれのキーやマウスでの処理*/
        if(t == DL_EVENT_L_DOWN){
              x_f = x;
              y_f = y;
          }
          
         else if(t == DL_EVENT_L_UP){
              x_c = x;
              y_c = y;
         }
         
         else if(t == DL_EVENT_R_UP){
              color = color +1;
                if(color == 3)color = 0;
         }
        else if(t == DL_EVENT_KEY){
             
             if(k == DL_KEY_LEFT){
               x_c = x_c - 1;
                }
             
             else if(k == DL_KEY_RIGHT){
               x_c = x_c + 1;
                } 
             
             else if(k == DL_KEY_UP){
               y_c = y_c - 1; 
                }
             
             else if(k == DL_KEY_DOWN){
               y_c = y_c +1;
                }
             else if(k == DL_KEY_ENTER){
               dl_rectangle( 0, 0, DL_WIDTH, DL_HEIGHT, dl_White, 0, 1);
               dl_rectangle( x_frame , y_frame, x_right, under, dl_Black, 2, 0);
               }
             else if(k == DL_KEY_SHIFT_L){
               
               circle_size = circle_size +10;
               if(99 < circle_size )circle_size =100;
               
               }
             else if(k == DL_KEY_SHIFT_R){
               
               circle_size = circle_size -5;
               if(26 > circle_size )circle_size =25;
               }
             else{
             
             char str[100];
                 sprintf(str,"%c",k);
                 dl_text(str, x_c, y_c, 1.0, color1, 1);
                
                 
                 
             } 
             
        }
       }
}
