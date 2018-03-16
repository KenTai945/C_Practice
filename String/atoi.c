#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   int val;
   char str[20];
   
   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d", str, val);

   strcpy(str, "gitbook.net");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);
   return 0;
}
