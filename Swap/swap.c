#include<stdio.h>
#include<stdlib.h>

/*
	* classic swap problem
*/

int main(void)
{
    int a = 15, b = 17;
	printf("before swap a = %d, b = %d\n", a, b);    
    a = a+b;
    b = a-b;
    a = a-b;
    printf("after swap a = %d, b = %d\n", a, b);
	return 0;
}
