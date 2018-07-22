#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	/*
		the ASIIC code must have to be reset ,bcz if the bufferstring what we store is smaller than 32
		Some of the part may have the problem if we didn't reset. The stack memory doesn't clean clearly.

	*/
	int fd;//int fd = 0; Bcz we will assign the 
	char ssid[32] = {0}; 	 
	char passwd[32] = {0};	
	size_t wlen;
	/*
		
	*/
	fd = open("/tmp/123.txt", O_CREAT|O_RDWR);
	if(fd < 0){
		printf("open: %s\n", strerror(errno));
		return -1;
	}
	
	// TODO: check the length 
	printf("Enter the ssid: ");
	fgets(ssid, sizeof(ssid), stdin);
	
	printf("Enter the password: ");
	fgets(passwd, sizeof(passwd), stdin);

	/*
		do while(0) can be instead of the goto function 
		
		In this case, once the error happened, the function won't 

		waste time to jump to the function 
	*/
	do{
		wlen = write(fd, ssid, strlen(ssid));
		if(wlen < 0){
			printf("Write ssid: %s\n", strerror(errno));
			break;
		}
	
		wlen = write(fd, passwd, strlen(passwd));
		if(wlen < 0){
			printf("Write passwd: %s\n", strerror(errno));
			break;
		}
	}while(0);

	close(fd);
	
	return 0;
}

