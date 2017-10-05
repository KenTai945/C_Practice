#include<stdio.h> 
#include<stdlib.h>


/*

reference:understanding more about c 

URL:https://goo.gl/A3s7bQ

*/
static int b = 3;
static int c = 3;

/*

static could be only used in the function.?glaobal


*/
void foo(void)
{
    int a = 3;
    ++a;
    printf("%d\n",a);
}

void foo_static(void)
{
	++b;
	printf("%d\n",b);
}
int main(void)
{	
	printf("memory stored in the stack\n");
    foo();
    foo();
    foo();
	printf("memory stored in the stactic\n");
	foo_static();
	foo_static();
	foo_static();
}

