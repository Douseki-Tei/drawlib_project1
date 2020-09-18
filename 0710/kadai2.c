#include <stdio.h>

int main(void) 

{
  int i, x[10], j, k, a;

  for (i = 0; i < 10; i++) 
  {
    scanf("%d", &x[i]);
  }

  /* x をソートする */
  
  for (k=0; k<10; ++k)
  {
   for (j=k+1; j<10; j++)
    {
    if (x[k] > x[j])
     {
       a = x[k];
       x[k] = x[j];
       x[j] = a;
     }
    }
   }
  
  /* x を表示する */


   for (i=0; i<10; i++)
   printf("%d ", x[i]);
   printf("\n");
   
   
  return 0;
}
