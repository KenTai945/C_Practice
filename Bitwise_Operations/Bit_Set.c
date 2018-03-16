#include<stdio.h>
#include<stdlib.h>
/*
  Practice of Bitwise Operator 
*/

void convert_binary(int value)
{
	while(value != 0)
	{
		value &= 1;		
	}
}
int main(void)
{
	int REG = 4;
	printf("printf the cruuent value of REG by heixmal %d",REG);
	printf("set the register RGE 6 bit to 1",convert_binary(REG));
	return 0;	
}
