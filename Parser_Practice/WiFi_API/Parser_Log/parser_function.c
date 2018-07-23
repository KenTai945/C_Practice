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
	(1)
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
	char buffer[1024];

	char buffer_less[256];

	fp = fopen("creare_ap.txt","r");	
	if (fp == NULL)
	{
		printf("failed to fopen\n");
		exit(EXIT_FAILURE);
	}
		 
	fseek(fp,0L,SEEK_END);
	
	sz_fl = size_ftell_fseek(fp);
			
	printf("the size is %d\n",sz_fl);
	rewind(fp);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
	/*
		set up the size of the buffer 
	*/
	int x = sz_fl / 32;
	sz_fl = (x + 1) * 32;

	printf("the reorganize of the size is %d\n",sz_fl);
	char fread_buffer_parser[256];	
	/*
		parser dmeag	
		(1) store the messag to the data first
		(2) use "strstr" to do the parser part
	*/
	
	/*
		(1) first part use the fp(pointer) to look for the data form the 1/10
	*/
	/*
	sz_fl = sz_fl /5;
	fseek(fp, -(sz_fl), SEEK_END);
	fread(fread_buffer_parser, sz_fl, 1, fp);
	printf("%s/n",fread_buffer_parser);
	rewind(fp);
	fclose(fp);
	*/
	
	fread(buffer,sz_fl,1,fp);
    
    printf("printf the whole document\n");
    printf("%s/n",buffer);

    rewind(fp);
    //use the function of fseek to modify the code to read the last several line
    
    printf("\n printf the half of the document\n");
    fseek(fp,-(sz_fl/2),SEEK_END); 
    fread(buffer_less,sz_fl,1,fp);
    
    printf("%s/n",buffer_less);
    
    rewind(fp);
    fclose(fp);//Don't Forget

	return 0;
}
