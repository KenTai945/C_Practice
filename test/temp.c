#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	float temp[5] = {1.0,2.0,3.0,4.0,5.0};
	
	for(int i=1;i<sizeof(temp)/sizeof(temp[0]);i++)
	{
		temp[i] = temp [i-1] + temp[i+1]/2;
		for(int j=0;j<sizeof(temp)/sizeof(temp[0]);j++)
		{
			printf("temp[%d] is %f",j,temp[j]);
		}
		printf("next round\n");
	}

	return 0;
}
