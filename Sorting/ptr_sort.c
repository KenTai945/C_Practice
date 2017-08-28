#include<stdio.h>
#include<stdlib.h>
/*

   How to find the value in the array

   (1)target 
   (2)pointer
 */

/*
   void find_target(int val,int arr[],int count){
   int *element;
 *element = sizeof(arr)/sizeof(arr[0]);
 printf("element is ")
 for(int i = 0;i < *element;i++)
 {	
 if(val == arr[i])
 {
 printf("the target is the %dth element of the array\n",i);
 }	
 }
 }
 */


void find_target_ptr(int *arr,int target){//think about if the answer is not int the array?
	int *ptr_target = arr;//declare a ptr point to the array,and we use it to do 
	int i = 0;
	while(*ptr_target != target)
	{	
		ptr_target = ptr_target+1;
		i = i+1;
	}
	printf("the target is the %dth of the element in the array\n",i+1);
}
void print_traserval_ptr(int *arr,int element){
	for(int i = 0;i<element;i++)
	{   
		printf("the value of the %dth element of the is %d\n",i+1,*(arr+i));
	}

}
void print_traserval_variable(int arr[],int element){
	for(int i = 0;i<element;i++)
	{   
		printf("the value of the %dth element of the is %d\n",i+1,arr[i]);
	}
}
int main(void){
	int array[10] = {1,2,3,4,5,9,8,10,7,6};
	int target;
	int count = sizeof(array)/sizeof(array[0]);
	printf("type the value what you want to find?\n");
	scanf("%d",&target);
	/*
	   for(int i = 0;i<sizeof(array)/sizeof(array[0]);i++)
	   {	
	   printf("the value of the %dth element of the is %d\n",i+1,*(array+i));
	   }
	 */
	print_traserval_ptr(array,count);
	//print_traserval_variable(array,count);
	find_target_ptr(array,target);
	return 0;
}
