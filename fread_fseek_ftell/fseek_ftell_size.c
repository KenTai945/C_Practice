#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;

	size_t fl_size;

	fp = fopen("fread_file.txt","r");

	if (fp == NULL)
    {
        printf("failed to fopen \n");
        exit(EXIT_FAILURE);
    }

	/* 
		use the function fseak &ftell to calculate the size of the file 
		Don' forget to reset the position of fp
	*/

	fseek(fp,0L,SEEK_END);

	fl_size = ftell(fp);

	rewind(fp);//  fseek(fp,0L,SEEK_SET)) ,seeking to go to the beginning
	
	printf(" the size of the file is %zu\n",fl_size);
	
	fclose(fp);//Don't Forget

	return 0;
}
