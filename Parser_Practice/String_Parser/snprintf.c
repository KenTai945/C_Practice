#include <stdio.h>
#define STRING "Your command is"


int main(int argc, char **argv)
{
	char buf[128];

	int a = 10;
	
/*
	if(argc < 2) {
		printf("%s [command]\n", argv[0]);
		return -1;
	}
*/	
	

//	snprintf(buf, sizeof(buf), "Your command is %s", argv[1]);
	
	printf("%s\n", buf);	// output = "Your command is 10"

	return 0;
}
