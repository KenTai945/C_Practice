#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int array[5] = {1,2,3,4,5};

	int *ptr;
	
	for(ptr = &array[0]; *ptr != 4 ;ptr++)
	{
		printf("we got %d\n",*ptr);
	}
	return 0;
}
