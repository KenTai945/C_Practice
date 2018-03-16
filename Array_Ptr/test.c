#include<stdio.h>


int remove_element(int *nums, int numsSize, int val) 
{
    int i;
    int length = numsSize;

    for(i = 0;i<numsSize;i++){
        if(nums[i] == val){
            if(i!=numsSize-1){
                nums[i] = nums[numsSize-1];
                i--;
            }

            length--;
            numsSize--;
        }
    }
	return length;
}
int main(void)
{
	int array[5] = {49,89,69,77,67};
	for(int count=0;count<sizeof(array)/sizeof(array[0]);count++)
	{
		printf("%d\t",array[count]);
	}
	printf("%d\n");
	/*
	remove_element(&array[0],sizeof(array)/sizeof(array[0]),87);
	for(int count=0;count<sizeof(array)/sizeof(array[0]);count++)
	{
		printf("%d\t",*(array+count));
	}
	printf("%d\n");
	*/
	return 0;
}
