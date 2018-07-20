#include <stdio.h>
#include <stdlib.h>

int mian(void)
{
	FILE *fp;

	size_t fl_size;

	fp = fopen("fread_file.txt","+r");
	if (fp == NULL)
	{
		printf("Error Opening File\n");
	}
	/* use the fseek & ftell to calculate the size of the function)*/

	fseek(fp,0,SEEK_END);

	fl_size = ftell(fp);

	rewind(fp);

	printf(" the size of the file is %zu\n",fl_size);

	fclose(fp);//Don't Forget

	return 0;
}
   
