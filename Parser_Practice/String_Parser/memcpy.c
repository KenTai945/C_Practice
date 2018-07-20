#include <stdio.h>  
#include <string.h>  
  
int main(int argc, char **argv){  
   char str[256];  
  
   memcpy(str, "memcpy test", 7);  
  
   printf("str = (%s)\n", str);  
   // str = (memcpy )  
  
   return 0;  
}  
