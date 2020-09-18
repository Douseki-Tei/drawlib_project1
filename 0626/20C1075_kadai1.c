#include <drawlib.h>

int main(void) {
  int i;
  
  dl_initialize(1.0);
  
  for (i = 0; i < 10; i++) {
    dl_line(100, 100, 10 + i * 50, i * i * 5, 
            DL_C("yellow"), 5 - i / 2);
    dl_line(100, 100, 5 + i * 50, i * i * 5,
            DL_C("red"), 5 - i / 3);
    dl_line(100, 100, 10 - i * 50, i * i * 5,
            DL_C("blue"), 5 - i /4);
                   
  }  
  
  while (1) {
    dl_wait(1.0);
  } 
  
  return 0;
}
