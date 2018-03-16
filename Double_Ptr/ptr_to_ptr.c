#include<stdio.h>
#include<stdlib.h>

int mian(void)
{
	
	int val_a = 5;
	int val_b = 10;

	int *ptr_to_a = &val_a;
//	int *ptr_to_b = &val_b;

	int **ptr_to_ptr = &ptr_to_a;
	
	printf("the current ptr_to_ptr is point to ptr_to_a\n");
	printf("the value of the **ptr_to_ptr is  %d\n",**ptr_to_ptr);
	
	//**ptr_to_ptr = &ptr_to_b;

	printf("the current ptr_to_ptr is point to ptr_to_b\n");
	printf("the value of the **ptr_to_ptr is %d\n",**ptr_to_ptr);
		
	return 0;
}
