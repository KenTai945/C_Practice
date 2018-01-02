#include<stdio.h>
#include<stdlib.h>
/*
	declare a void  pointer(tmp) memory allocate a pointer
	memory allocate for the pointer tmp
	assign the pointer to the pointer a which is point to the 
	void could be changed to the other type!!! 	
*/


int main(void)
{
    int *a ;
    void *tmp;
    printf("before malloc the address of the poionter is %p\n",a);
    tmp = malloc(sizeof(a));
    printf("after the malloc the address of tmp is %p\n", tmp);
    a = tmp;
    printf("after malloc %p\n", a);
    *a = 1;
	printf("assign pointer point to 1\n");
    printf("%d\n",*a);
    printf("the tmp address now is %p\n",tmp);                  
   	return 0;
}

