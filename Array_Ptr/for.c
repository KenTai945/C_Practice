#include<stdio.h>
#include<stdlib.h>




int main(void)
{
	int a[5] = {1,2,3,4,5};
	int i;
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("the %dth of the element is %d",i,*(a+i));
		printf("\n");
	}

	
}

