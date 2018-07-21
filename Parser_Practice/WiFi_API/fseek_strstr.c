#include<stdio.h>
#include<stdlib.h>
/*
	Function
	(1)strstr
	(2)strchr
	(3)fseek
	(4)ftell


	Target: 
	(1)use the function fseek to get the sizeof file.txt and read from  last 1/10  of the code
	(2) using the parser to search for the key word 
	
	Pending Function:
	(1)?
*/
	


/*
	Don' forget to reset the position of fp                                   
	Use the function of fseak &ftell to calculate the size of the file       
*/
size_t size_ftell_fseek(FILE *file_ptr)
{
	size_t sizeof_document;

	fseek(file_ptr,0L,SEEK_END);                                                                                             
    sizeof_document = ftell(file_ptr);
    rewind(file_ptr);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
	return sizeof_document;
}

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
		 
	fseek(fp,0L,SEEK_END);
	
	sz_fl = size_ftell_fseek(fp);

	printf("the size is %d",sz_fl);
	rewind(fp);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
	
	fclose(fp);//Don't Forget
	
	return 0;
}
