#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  
	Topic  	
*/
/* use the function of fseek to modify the code to read the last several line*/

size_t sizeof_file(FILE *ptr)
{
	size_t size_document;
	fseek(ptr,0L,SEEK_END);
    size_document = ftell(ptr);
	return size_document;
}


int main (void)
{
	FILE *fp; 

    size_t sz_fl = 0;

    //size_t medium_sz_fl;
    char buffer[128] = {0};

    char buffer_ssid[16] = {0};
	char buffer_pwd[16] = {0};

    fp = fopen("ssid_pwd.txt","r");   
    if (fp == NULL)                                                                                                                                                    
    {
        printf("failed to fopen\n");
        exit(EXIT_FAILURE);
    }
    /*
        Don' forget to reset the position of fp                                   
        use the function of fseak &ftell to calculate the size of the file       
    */ 
	sz_fl = sizeof_file(fp);    
	
    rewind(fp);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
    
    fread(buffer,sz_fl,1,fp);
    
    //printf("printf the whole document\n");
    //printf("%s/n",buffer);
    rewind(fp);
	
	int a = 3;
	char *p;
	char *ptr = buffer;

	strcpy(buffer_ssid,buffer);
	p = strstr (buffer,"\n");
	
	if(p)
  	{
		printf("string found\n");
		printf("%s\n",ptr);
    	printf ("%s and %s\n",buffer,p);
		printf("%s\n",p);
  	}
  	else
	{ 
		printf("string not found\n" );
	}
	return 0;
}
