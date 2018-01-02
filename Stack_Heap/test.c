#include<stdio.h>                                       
void foo()
{
 	int a[3] = {4,5,6};
 	printf("the beginner of the array a[0]'s address is%p\n",a);
}
void bar()
{
	int b[5];
   	printf("the beginner of the array b[0]'s address is%p\n",b);
    printf("%d\t %d\t %d\t\n",b[0],b[4],b[5]);
}
int main(void){
    foo();
    bar();
}
