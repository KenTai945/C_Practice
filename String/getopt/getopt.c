#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int opt;
	int var;
	
	if(argc < 2){
		printf("%s [-a/-b]\n", argv[0]);
		return -1;
	}

	while((opt = getopt(argc, argv, "ab:")) != -1){
		switch(opt){
		case 'a':
			printf("get -a\n");
			break;
		case 'b':
			printf("get -b\n");
			var = atoi(optarg);
			printf("var = %d\n", var);
			break;
		default:
			printf("Unknow argument\n");
		}
	}
	
	return 0;
}
