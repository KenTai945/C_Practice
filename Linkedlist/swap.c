#include<stdio.h>
#include<stdlib.h>

void swap(int number1,int number2){
	int tmp;
	tmp = number1;
	number1 = number2;
	number2 = tmp;
	printf("a is %d,b is%d\n",number1,number2);
}
int main(void){
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	swap(a,b);
	printf("after swap\n");
	printf("a is %d,b is %d\n",a,b);	
	return 0;
}
