#include<stdio.h>

/*
	Apple Interview??
*/


void foo()
{
	int a[3] = {1,2,3};
	int c[3] = {4,5,6};
	printf("%p\n",&a);
	printf("%p\n",&c);//first in ,first out!! "stack"?
}

void bar()
{
	int b[5];
	printf("%p\n",&b);
	printf("%p\t %p\t %p\t\n",&b[0],&b[1],&b[3]);
}

int main(void){
	foo();
	bar();
}
