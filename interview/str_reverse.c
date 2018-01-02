#include <stdio.h>

static void swap(char **a, char **b)
{
	**a ^= **b;
	**b ^= **a;
	**a ^= **b; 
}

static void reverse(char *s)
{
	char *p = s;

	// this time, p point to \0	
	while(p && *++p != '\0'){}

	for(p--; s < p; p--, s++)
		swap(&p, &s);
}

int main(int argc, char **argv)
{
	if(argc < 2){
		printf("%s [string]\n", argv[0]);
		return -1;
	}
	
	printf("Before : %s\n", argv[1]);
	reverse(argv[1]);
	printf("After reverse: %s\n", argv[1]);
	
	return 0;
}
