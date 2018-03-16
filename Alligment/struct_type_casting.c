#include<stdio.h>
#include<stdlib.h>

struct foo{
	int a;//4 byte
	int b;//4 byte 
};

int main(void)
{
	unsigned char mem[8] = {0};
	void *p = mem;

	mem[0]=0xf1;
	mem[4]=0xff;
	
	printf("a = 0x%x\n", ((struct foo *)&mem)->a);
	printf("b = 0x%x\n", ((struct foo*)p)->b);
	
	return 0;
}
