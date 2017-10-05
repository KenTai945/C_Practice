#include<stdio.h>

/*

first in and first out 

function memory allocat the way is stack?? 

so,what you change the variable it has been memory changed

*/

void foo()
{
	int a[3] = {1,2,3};
}

void bar()
{
	int b[3];
	printf("%d\t %d\t %d\t\n",b[0],b[1],b[3]);
}

int main(void){
	foo();
	bar();
}
