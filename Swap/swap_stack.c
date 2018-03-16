#include<stdio.h>
#include<stdlib.h>

/*
	example to discuss about the concept of the stack and heap 
*/

void swap(int a,int b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
	printf("in the swpa function(stack memory) a is %d, b is %d\n ",a,b);
}

int main(void)
{
	int a = 67;
	
	int b = 87;

	printf("before the swap a is %d, b is %d\n ",a,b);
	swap(a,b);
	printf("call swap function(stack memory)\n ");
	printf("after call the function computer release the stack memorya is %d, b is %d\n ",a,b);
	return 0;
}
