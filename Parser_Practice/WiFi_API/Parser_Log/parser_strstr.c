#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Target: Using the strstr to check for the log message have the "wifi setup" for 5 times 
	
	Step By step:
	(1)set up the fp to point to the log file 
	(2)read the lat part of the log ot store in the buffer
	(3)compare the string to return the ptr, to check the parser
*/

size_t size_ftell_fseek(FILE *file_ptr)                                                                                                                        
{
	size_t sizeof_document;

	fseek(file_ptr,0L,SEEK_END);                                                                                             
    sizeof_document = ftell(file_ptr);
    rewind(file_ptr);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
    return sizeof_document;
}

int parser_check()
{
	char buffer[512] = {0};
	FILE *fp;
	size_t sz_of_txt;
	char *ptr = buffer;
	fp = fopen("station_success.txt","r+");
	if(fp == NULL){
		perror("Error opening file");
		return(-1);
	}	
	fseek(fp,0L,SEEK_END);	// seek to end of file
	sz_of_txt = size_ftell_fseek(fp);
	fseek( fp, -100, SEEK_END );
	
	//fread(buffer,sz_of_txt/4,1,fp);
	fread(ptr,100,1,fp);
	puts(ptr);
	rewind(fp);

	char *parsercheck;
	
	parsercheck = strstr(buffer,"wlx4c0fc716fbaf: link becomes ready");
	if (parsercheck != NULL){
		printf("find \n");
		return 0;
	}
	else{
		printf("not found\n");
		return 1;
	}
	fclose(fp);// important, don't gorget
}

int main(void)
{
	int find = 0;
	int count = 0;
	while(count < 10)
	{
		find = parser_check();
		if(find == 0){
			break;
		}
		else {
			count++;
		}
		sleep(1);
	}
	if (count == 9){
		printf("not found\n");
	}
	return 0;
}	
