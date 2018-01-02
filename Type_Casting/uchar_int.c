#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned char i = 255;
	int j = 1023;
	printf("the size of the unsigned char is %lu\n",sizeof(i)); //lu is the correct format for unsigned long
	//unsigned char is 8 bit (2*2*2)
	printf("the size of the int is %lu\n",sizeof(j)); 
	
	printf("the i is %04x in 16 bit\n ",i);
	printf("the j is %04x in 16 bit\n ",j);

	return 0;
}
