#include<stdio.h>
#include<stdlib.h>


/*
	Single Number
	XOR: no carry addition
*/


int main(void){
	int array[7] = {0,0,1,2,2,3,3};
	int answer = array[0];
	for(int i=1;i<sizeof(array)/sizeof(array[0]);i++)
	{ 
		answer ^= array[i];
	}
	printf("the single element is %d\n",answer);
	return 0;
}
