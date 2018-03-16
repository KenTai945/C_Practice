#include<stdio.h>

int main(void)
{
	int array[5] = {1,2,3,4,5};// declare an array with number
	int length = sizeof(array)/sizeof(array[0]);
	
	/*
		print the element of the array;	
	*/	
	for(int i=0;i<length;++i)
	{
		printf("array[%d] is %d\t",i,array[i]);
	}
	/*
		move every element to the exelement 
	*/
	printf("\n");
	printf("remove the first element from the array\n");
	
	for(int i=0;i<length-1;++i)
	{
		array[i] = array[i+1];
	}
	/*
		printf the first the element int the array
	*/
	printf("print the array which remove the first element\n");
	
	for(int i=0;i<length;i++)
	{
		printf("array[%d] is %d\t",i,array[i]);
	}
	printf("\n");

	
	return 0;
}
