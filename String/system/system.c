#include <stdio.h>
#include <stdlib.h>
/*
	system: execute a shell command
*/

int main(int argc, char **argv)
{
	if(argc < 2){
		printf("%s [command]\n", argv[0]);
		return -1;
	}
	
	printf("Excute %s\n", argv[1]);
	
	system(argv[1]);
	
	return 0;
}
