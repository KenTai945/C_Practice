#include<stdio.h>
#include<stdlib.h>
/*
   the original version is doing the traversal 
 */

int main(void)
{


	int array[6] = {2,3,4,5,10,13};

	int i,j,k,l;

	printf("the current value of the array is \n");
	for(i=0;i<sizeof(array)/sizeof(array[0]);i++)
	{
		printf("the %dnth of the value is %d\n",i,*(array+i));
	}	
	for(j=0;j<sizeof(array)/sizeof(array[0]);j++)
	{
		if(5 == *(array+j))//thinl about why I use this way of if statement
		{
			for(int k=j;k<(sizeof(array)/sizeof(array[0]));k++)
			{
				*(array+k) = *(array+k+1);
			}
		}
	}
	printf("when we remove the target the current array is\n");
	for(l=0;l<(sizeof(array)/sizeof(array[0]))-1;l++)
	{
		printf("the %dnth of the value is %d\n",l,*(array+l));
	}
	return 0;
}
