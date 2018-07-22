#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buffer[5] = "files";

	if(argc < 2){
		printf("%s [command]\n", argv[0]);
		return -1;
	}
	

	printf("Excute %s\n", argv[1]);
		
	system(argv[1] + "buffer");
	
	return 0;
}
