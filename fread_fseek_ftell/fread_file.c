#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE *fp; 

	size_t sz_fl;

	//size_t medium_sz_fl;
	char buffer[100];

	char buffer_less[50];

	fp = fopen("fread_file.txt","r");	
	if (fp == NULL)
	{
		printf("failed to fopen\n");
		exit(EXIT_FAILURE);
	}
	/*
        Don' forget to reset the position of fp                                   
		use the function of fseak &ftell to calculate the size of the file       
	*/ 
	fseek(fp,0L,SEEK_END);
	
	sz_fl = ftell(fp);

	rewind(fp);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
	
	fread(buffer,sz_fl,1,fp);
	
	printf("printf the whole document\n");
	printf("%s/n",buffer);

	rewind(fp);
	/* use the function of fseek to modify the code to read the last several line*/
	
	printf("\n printf the half of the document\n");
	fseek(fp,-(sz_fl/2),SEEK_END); 
	fread(buffer_less,sz_fl,1,fp);
    
    printf("%s/n",buffer_less);
	
	rewind(fp);
	fclose(fp);//Don't Forget

	return 0;
}
