#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	char buffer[64];
	int opt;

	if(argc < 2){
		printf("%s [command]\n",argv[0]);
		return -1;
	}
	//argv[1];
	//printf("Excute %s\n",argv[1]);
	//system(argv[1]);
	
	while((opt = getopt(argc, argv, "dv")) != -1){
		switch(opt){
		case 'd':
			system("argv[1] /dev");
			break;
		case 'v':
			system("argv[1] /var");
			break;
		
		default:
			printf("Unknow argument\n");	
		}
	}
	return 0;
}
