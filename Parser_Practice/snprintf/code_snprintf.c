#include <stdio.h>
#include <string.h>
#define STRING "Your command is"


int main(int argc, char **argv)
{
	char buf[128];
	char buf1[4];

	int a = 10;
	
/*
	if(argc < 2) {
		printf("%s [command]\n", argv[0]);
		return -1;
	}
*/	


/*	
	printf("fuck you %d\n", a);
	printf("%s %d", STRING, a);
*/


/*
	sprintf(buf,"%s %d", STRING, a);
*/
	snprintf(buf, sizeof(buf), "%s %d", STRING, a);


	system("ifconfig eth0");
	system("ifconfig eth1")

	snprintf(buf, sizeof(buf), "ifconfig eht%d", a);
	system(buf);

	printf("%s\n", buf);	// output = "Your command is 10"

	return 0;
}


