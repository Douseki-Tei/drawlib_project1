#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<drawlib.h>

void start();

int main(void)
{

int life = 1;

   /*障害物の変更*/
int x1_1 = 0, y1_1 = 0, x1_2 = x1_1 + 75, y1_2 = 120, x2_1 = 350, y2_1 = 220, x2_2 = x2_1 + 50, y2_2 = 400, m=2, time =0, flag1 = 1, lo1 = 10, flag2 = 1, lo2 = 10;

float n = 2;
x1_1 += 640;  x1_2 += 640; x2_1 += 640; x2_2 += 640;



  /*車の移動*/
int t,k,x,y;
int myup = 'w';
int mydown = 's';
int myleft = 'a';
int myright = 'd';
int carx1_1=150,cary1_1=250,carx1_2=300,cary1_2=300;
int carx2_1=190,cary2_1=250,carx2_2=260,cary2_2=210;
int carx3_1=270,cary3_1=250,carx3_2=300,cary3_2=270;
int carx4_1=195,cary4_1=245,carx4_2=255,cary4_2=215;
int carx5_1=195,cary5_1=245,carx5_2=255,cary5_2=215;
int carx6_1=190,cary6_1=310,carx6_2=20;
int carx7_1=260,cary7_1=310,carx7_2=20;
int q;

dl_initialize(1.0);
  /*start画面に移動*/
  
  start();
  
  life = 1;
  
  while(life > 0)
  {
 
  /*コントロールボタン*/
 if(dl_get_event(&t, &k, &x, &y))
 {
  if(t == DL_EVENT_KEY)
      {
        if(k == myleft)
        {
           for(q=0;q<=50;q++)
          {
     carx1_1--;carx1_2--;carx2_1--;carx2_2--;carx3_1--;carx3_2--;carx4_1--;carx4_2--;carx5_1--;carx5_2--;carx6_1--;carx7_1--;
           }
        }
        else if(k == myright)
        {
           for(q=0;q<=50;q++)
           {
     carx1_1++;carx1_2++;carx2_1++;carx2_2++;carx3_1++;carx3_2++;carx4_1++;carx4_2++;carx5_1++;carx5_2++;carx6_1++;carx7_1++;
           }
        }
      
      
        if(k == myup)
        {
           for(q=0;q<=50;q++)
          {
     cary1_1--;cary1_2--;cary2_1--;cary2_2--;cary3_1--;cary3_2--;cary4_1--;cary4_2--;cary5_1--;cary5_2--;cary6_1--;cary7_1--;
           }
        }
        else if(k == mydown)
        {
           for(q=0;q<=50;q++)
           {
     cary1_1++;cary1_2++;cary2_1++;cary2_2++;cary3_1++;cary3_2++;cary4_1++;cary4_2++;cary5_1++;cary5_2++;cary6_1++;cary7_1++;
           }
        }
     } 
  }
  
  /*障害物*/
  dl_stop();
  dl_clear(DL_C("white"));
  dl_rectangle(x1_1,y1_1,x1_2,y1_2, DL_C("blue"), 25, 0);
  dl_rectangle(x2_1,y2_1,x2_2,y2_2, DL_C("red"), 1, 1);

   
   /*車*/
  dl_rectangle(carx1_1,cary1_1,carx1_2,cary1_2,dl_color_from_name("red"),2,1);
  dl_rectangle(carx2_1,cary2_1,carx2_2,cary2_2,dl_color_from_name("red"),2,1);
  dl_rectangle(carx3_1,cary3_1,carx3_2,cary3_2,dl_color_from_name("yellow"),2,1);
  dl_rectangle(carx4_1,cary4_1,carx4_2,cary4_2,dl_color_from_name("cyan"),2,1);
  dl_rectangle(carx5_1,cary5_1,carx5_2,cary5_2,dl_color_from_name("black"),1,0);
  dl_circle(carx6_1,cary6_1,carx6_2,dl_color_from_name("black"),2,1);
  dl_circle(carx7_1,cary7_1,carx7_2,dl_color_from_name("black"),2,1);
  
  dl_rectangle(0,330,1000,600,dl_color_from_name("black"),1,1);
  dl_rectangle(0,390,100,420,dl_color_from_name("white"),1,1);
  dl_rectangle(150,390,250,420,dl_color_from_name("white"),1,1);
  dl_rectangle(300,390,400,420,dl_color_from_name("white"),1,1);
  dl_rectangle(450,390,550,420,dl_color_from_name("white"),1,1);
  dl_rectangle(600,390,700,420,dl_color_from_name("white"),1,1);
  
 time++;

/*障害物の出る頻度*/
  if(flag1 == 0){
    lo1 = rand() % 75 - 0;
    if(lo1 == 1){
      flag1 = 1;
     }
   }
   if(flag2 == 0){
    lo2 = rand() % 60 - 0;
    if(lo2 == 1){
      flag2 = 1;
     }
   }
   
  if(x1_1 < x2_1 && x2_1 < x1_2){
    x2_1 = 1200;
    x2_2 = x2_1 + 75; 
    }
  if(x2_1 < x1_1 && x1_1 < x2_2){
    x1_1 = 1200;
    x1_2 = x1_1 + 75; 
    }
    
  
  /*障害物の速度*/
  if(flag1 == 1 && time %1 == 0){
    x1_1 -= m;
    x1_2 -= m;
  }
  if(flag2 == 1 && time %1 == 0){
    x2_1 -= n;
    x2_2 -= n;
  }

  
  if(x1_2 <= 0){
    x1_1 = 0; 
    x1_2 = x1_1 + 70; 
    x1_1 += 640;
    x1_2 += 640;
    flag1 = 0;
  }
  if(x2_2 <= 0){ 
    x2_1 = 200; 
    x2_2 = x2_1 + 75; 
    x2_1 += 640; 
    x2_2 += 640; 
    flag2 = 0;
  }

  dl_resume();
  
  
 /*当たり判定*/ 
if(x1_1 <= carx1_1 && carx1_1 <= x1_2 && y1_1 <= cary1_1 && cary1_1 <= y1_2){  
     life--;
   }    
if(x1_1 <= carx1_1 && carx1_1 <= x1_2 && y1_1 <= cary1_2 && cary1_2 <= y1_2){  
     life--;
   }    
if(x1_1 <= carx1_2 && carx1_2 <= x1_2 && y1_1 <= cary1_1 && cary1_1 <= y1_2){  
     life--;
   }
if(x1_1 <= carx1_2 && carx1_2 <= x1_2 && y1_1 <= cary1_2 && cary1_2 <= y1_2){  
     life--;
   }
if(x1_1 <= carx2_1 && carx2_1 <= x1_2 && y1_1 <= cary2_1 && cary2_1 <= y1_2){  
     life--;
   }    
if(x1_1 <= carx2_1 && carx2_1 <= x1_2 && y1_1 <= cary2_2 && cary2_2 <= y1_2){  
     life--;
   }    


if(x2_1 <= carx1_1 && carx1_1 <= x2_2 && y2_1 <= cary1_1 && cary1_1 <= y2_2){  
     life--;
   }    
if(x2_1 <= carx1_1 && carx1_1 <= x2_2 && y2_1 <= cary1_2 && cary1_2 <= y2_2){  
     life--;
   }  
if(x2_1 <= carx1_2 && carx1_2 <= x2_2 && y2_1 <= cary1_1 && cary1_1 <= y2_2){  
     life--;
   }    
if(x2_1 <= carx1_2 && carx1_2 <= x2_2 && y2_1 <= cary1_2 && cary1_2 <= y2_2){  
     life--;
   }  
if(x2_1 <= carx2_1 && carx2_1 <= x2_2 && y2_1 <= cary2_1 && cary2_1 <= y2_2){  
     life--;
   }    
if(x2_1 <= carx2_1 && carx2_1 <= x2_2 && y2_1 <= cary2_2 && cary2_2 <= y2_2){  
     life--;
   }   
   
    dl_wait(0.01);
   
  }
    return 0;

}


/*start画面の描写*/
  void start(void)
  {
    int x, y, t, k;
    dl_text("[CAR GAME]", 45, 180, 3, DL_C("magenda"), 20);
    dl_rectangle(245, 320, 385, 375, DL_C("red"),1,1);
    dl_text("START", 270, 357, 1, DL_C("white"), 5);
   
  dl_rectangle(50,330,200,380,dl_color_from_name("blue"),2,1);
  dl_rectangle(90,330,160,290,dl_color_from_name("blue"),2,1);
  dl_rectangle(170,330,200,350,dl_color_from_name("yellow"),2,1);
  dl_rectangle(95,325,155,295,dl_color_from_name("cyan"),2,1);
  dl_rectangle(95,325,155,295,dl_color_from_name("black"),1,0);
  dl_circle(90,390,20,dl_color_from_name("black"),2,1);
  dl_circle(160,390,20,dl_color_from_name("black"),2,1);
   
  dl_rectangle(430,330,580,380,dl_color_from_name("red"),2,1);
  dl_rectangle(470,330,540,290,dl_color_from_name("red"),2,1);
  dl_rectangle(550,330,580,350,dl_color_from_name("yellow"),2,1);
  dl_rectangle(475,325,535,295,dl_color_from_name("cyan"),2,1);
  dl_rectangle(475,325,535,295,dl_color_from_name("black"),1,0);
  dl_circle(470,390,20,dl_color_from_name("black"),2,1);
  dl_circle(540,390,20,dl_color_from_name("black"),2,1);
   
    while(1)
    {
      if(dl_get_event(&t,&k,&x,&y))
      {
        if(t == DL_EVENT_L_DOWN)
        {
          if(245 < x && x < 385 && 320 < y && y < 375)
          {
            /*if文で指定した範囲を左クリックしたら次の画面に移動*/
            dl_clear(DL_C("white"));           
            break;
          }
        }
      }
    }           
  }
