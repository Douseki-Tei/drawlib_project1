#include <drawlib.h>

int main(void) 
{
  dl_initialize(1.0);

  dl_line(0,330,1000,330,dl_color_from_name("black"),3);
  dl_line(150,300,300,300,dl_color_from_name("blue"),2);
  dl_line(150,300,150,250,dl_color_from_name("blue"),2);
  dl_line(150,250,200,250,dl_color_from_name("blue"),2);
  dl_line(200,250,200,200,dl_color_from_name("blue"),2);
  dl_line(200,200,250,200,dl_color_from_name("blue"),2);
  dl_line(250,200,250,250,dl_color_from_name("blue"),2);
  dl_line(250,250,300,250,dl_color_from_name("blue"),2);
  dl_line(300,250,300,300,dl_color_from_name("blue"),2);
  

  while(1)
  {
    dl_wait(0.01);
   }
    return 0;
}
