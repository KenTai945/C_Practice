#include <stdio.h>
#include <stdlib.h>
/*
	typecasting
*/
int main(void)
{
    int *a ;
    void *tmp;
    printf("before malloc %p\n",a);
    tmp = malloc(sizeof(a));
    printf("malloc address %p\n", tmp);
    a = tmp;
    printf("after malloc %p\n", a);
    *a = 1;
    printf("%d\n",*a);
    printf("%d\n",*(int *)tmp);//(int *) is a pointer point to interger,void轉型成int 再取它質                                                                         
    return 0;
}
