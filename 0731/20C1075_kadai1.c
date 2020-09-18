#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2);

int main(void)
{

  double x1, x2, y1, y2, x3, y3, a, b, c, d, e, f, max;
  int a2;
  int i = 1;
  
  printf("点1のx座標　：");
  scanf("%lf",&x1);
  printf("点1のy座標　：");
  scanf("%lf",&y1);
  printf("点2のx座標　：");
  scanf("%lf",&x2);
  printf("点2のy座標　：");
  scanf("%lf",&y2);
  printf("点3のx座標　：");
  scanf("%lf",&x3);
  printf("点3のy座標　：");
  scanf("%lf",&y3);
  
  d = dist(x1, y1, x2, y2);
  e = dist(x2, y2, x3, y3);
  f = dist(x3, y3, x1, y1);
  
  i = 0;
  double array[] = {d, e, f};
  max = array[i];
  for(i = 0; i < 3; i++)
  {
   if(max < array[i])
    {
      max = array[i];
    }
  }
  a = max;
  if(max == d)
  {
    b = e;
    c = f;
  }
  else if(max == e)
  {
    b = d;
    c = f;
  }
  else{
    b = d;
    c = e;
  }
  if(a == b + c)
  {
    printf("三角形にならない\n");
  }
  else if(a2 > b*b + c*c){
    printf("鈍角三角形\n");
  }
  else if(a2 == b*b + c*c){
    printf("直角三角形\n");
  }
  else if(a2 < b*b + c*c){
    printf("鋭角三角形\n");
  }
  

  return 0;
}

double dist(double x1, double y1, double x2, double y2){
  double x3, y3, dis;
  
  x3 = x1 - x2;
 
 if(x3 < 0)
  x3 -= 1;
 
  y3 = y1 - y2;

 if(y3 < 0)
  y3 -= 1;
  
  dis = sqrt(x3 * x3 + y3 * y3);
  return dis;
}
