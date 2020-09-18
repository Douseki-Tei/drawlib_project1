#include<stdio.h>
#include <stdlib.h>
#include <drawlib.h>

int main(void){
int x1_1 = 0, y1_1 = 0, x1_2 = x1_1 + 75, y1_2 = 240, x2_1 = 200, y2_1 = 240, x2_2 = x2_1 + 75, y2_2 = 480, m=2, time =0, flag1 = 1, lo1 = 10, flag2 = 1, lo2 = 10;
int x3_1 = 0, y3_1 = 150, x3_2 = x3_1 + 50, y3_2 = 200, x4_1 = 0, y4_1 = 300, x4_2 = 50, y4_2 = 350, flag3 = 1, flag4 = 1, log3 = 10, log4 = 10, lo3 = 10, lo4 = 10;
float n = 2;
x1_1 += 640;  x1_2 += 640; x2_1 += 640; x2_2 += 640; x3_1 += 640; x3_2 += 640; x4_1 += 640; x4_2 += 640;

dl_initialize(1.0);
while(1){
  dl_stop();
  dl_clear(DL_C("cyan"));
  dl_rectangle(x1_1,y1_1,x1_2,y1_2, DL_C("red"), 1, 1);
  dl_rectangle(x2_1,y2_1,x2_2,y2_2, DL_C("red"), 1, 1);
  dl_rectangle(x3_1,y3_1,x3_2,y3_2, DL_C("red"), 1, 1);
  dl_rectangle(x4_1,y4_1,x4_2,y4_2, DL_C("red"), 1, 1);
  
  
  time++;

  if(flag1 == 0){
    lo1 = rand() % 25 - 0;
    if(lo1 == 1){
      flag1 = 1;
     }
   }
   if(flag2 == 0){
    lo2 = rand() % 25 - 0;
    if(lo2 == 1){
      flag2 = 1;
     }
   }
   
   if(flag3 == 0){
    lo3 = rand() % 100 - 0;
    if(lo3 == 1){
      flag3 = 1;
     }
   }
   if(flag4 == 0){
    lo4 = rand() % 100 - 0;
    if(lo4 == 1){
      flag4 = 1;
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
    
    
  
  
  if(flag1 == 1 && time %1 == 0){
    x1_1 -= m;
    x1_2 -= m;
  }
  if(flag2 == 1 && time %1 == 0){
    x2_1 -= n;
    x2_2 -= n;
  }
  if(flag3 == 1 && time %1 == 0){
    x3_1 -= n;
    x3_2 -= n;
  }
  if(flag4 == 1 && time%1 == 0){
    x4_1 -= n;
    x4_2 -= n;
  }
  if(x1_2 <= 0){
    x1_1 = 0; 
    x1_2 = x1_1 + 75; 
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
  if(x3_2 <= 0){
    x3_1 = 200; 
    x3_2 = x3_1 + 50; 
    x3_1 += 640; 
    x3_2 += 640; 
    flag3 = 0;
  }
  if(x4_2 <= 0){
    x4_1 = 200; 
    x4_2 = x4_1 + 50; 
    x4_1 += 640; 
    x4_2 += 640; 
    flag4 = 0;
  }

  dl_resume();




  dl_wait(0.01);
  }
return 0;
}
