#include  <stdio.h>


int  strcmp(const char *p1, const char *p2);
void distsort(char **, int);

char *color[] = {"white", "black", "red", "pink", "orange","blue", "yellow", "green", "purple", "gray", "brown", "gold", "silver"};

int main(void){
  int i;
 
 printf("ソート前 : ");

 for (i = 0;  i < 13; i++)
  printf("%s  ", color[i]);

 distsort(color, 13); 

 printf("\nソート後 : ");  
 for (i = 0; i < 13; i++)
  printf("%s  ", color[i]);

 printf("\n");
 return 0;
}



int strcmp(const char *p1, const char *p2)
{
  
   while (*p1 == *p2){
      if (*p1 == '\0')                   
          return (0);                    
      p1++;                              
      p2++;                              
    }
   if(*p1 - *p2 < 0){    
     return -1;
    }
   if(*p1 - *p2 > 0){
      return 1;
    }
}

void distsort(char *color[], int n){
  int i, j, k;
  char *temp;
 
  for (i = 0; i < n - 1; i++) {
      for (j = i + 1; j < n; j++) {
         if ((strcmp(color[j], color[i])) < 0) {
              temp = color[i];   
              color[i] = color[j]; 
              color[j] = temp;    
           }
       }
   }
}
