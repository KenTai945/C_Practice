#include <stdio.h>
#include <limits.h>

/*
	the last of the string is "\0"
*/
int main(int argc, char **argv)
{
	int len = 0;

	if(argc < 2){
		printf("%s [input string]\n", argv[0]);
		return -1;
	}

	// this time, argv[1] point to next of \0
	while(*argv[1]++ && len < INT_MAX)
		len++;

	printf("length = %d\n", len);
	
	return 0;
}
