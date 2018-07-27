#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char *line;
	char ssid[16];
	char passwd[16];
	size_t rlen;
	
	if(argc < 2){
		printf("%s [FILE PATH]\n", argv[0]);
		return -1;
	}
	
	fp = fopen(argv[1], "r");
	assert(fp);

	int r = getline(&line, &rlen, fp);	
	memcpy(ssid, line, r);
	ssid[r-1] = '\0';
	printf("read len = %d\n", r);
	printf("You Got the ssid: %s\n", ssid);
	
	if(line)	
		free(line);	

	fclose(fp);
	
	return 0;
}
