#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	
	int x = 0x0e;
	printf("x is 0x%08x\n",x);
	x = x << 1;
	//1110 =>11100 =>1100
	printf("after one left shift of x,now x is 0x%08x\n",x);
	//x | 0 << 5
	x = x & 0xf;
	printf("x is 0x%08x\n",x);
	return 0;
}
