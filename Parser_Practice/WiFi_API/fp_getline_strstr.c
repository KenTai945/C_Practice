#include<stdio.h>                                                                                                                                                      
#include<stdlib.h>
#include<string.h>
int main(void)
{
    FILE * fp;
    
	char * line = NULL;
    
	size_t len = 0;
    
	ssize_t read;//why?

    fp = fopen("/home/paul/c_code/file_open/test.txt", "r");
    if (fp == NULL)
	{
			
	}

    while ((read = getline(&line, &len, fp)) != -1) 
	{
		/*
			use the function "strstr" as the parser to check IP
		*/        
		if(strstr(line, "ab"))
		{		
        	printf("%s\n", line);
		}
		else	
		{
			printf("there is no string match\n");
		}
    }

    fclose(fp);
    if (line)
        free(line);
	return 0;
}

