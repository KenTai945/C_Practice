#include<stdio.h>
#include<stdlib.h>


int main(void){
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("the A[10] is\n");
	
	int length = sizeof(A)/sizeof(A[0]);
	//remove the element
	for(int i = 3;i<length-1;i++)
	{
		A[i-1] = A[i];
	}
	//print out the element
	for(int i = 0;i<length-2;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	return 0;
}
