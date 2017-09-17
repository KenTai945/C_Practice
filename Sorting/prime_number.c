#include<stdio.h>
#include<stdlib.h>
/*

find the prime number in the limited interger 

*/


void find_prime(int N)
{
	int not_prime_count = 0;
	
	for(int i=2;i<N;i++)
	{
		for(int j= 2;j<i;j++)//be careful the j!!?
		{
			if (i%j==0)
			{
				not_prime_count ++;
				break;
			}
		}
	}
	printf("%d\n",not_prime_count);
}

int main(void){
	int Number = 10;
	/*
	printf("enter the value you want to test\n");
	scanf("%d\n",&Number);
	printf("%d\n",Number);
	*/
	find_prime(Number);
	return 0;
}
