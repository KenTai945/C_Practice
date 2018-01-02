#include <stdio.h>
#include <stdlib.h>
/*
	Fibonacci Numbers have two ways 
	(1)recursive
	(2)loop
*/

/*
	static global,local,function
*/

static int fib(int n)//why we need to use static?
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return fib(n-1)+fib(n-2);
}

int main(int argc, char **argv)
{
	if(argc < 2){
		printf("%s [n-element]\n", argv[0]);
		return -1;
	}

	for(int i = 0; i < atoi(argv[1]); ++i)
		printf("%d ", fib(i));
	printf("\n");
	
	return 0;
}
