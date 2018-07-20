#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE *fp; 	

	char buffer[20];

	fp = fopen("./filefread.txt","");
	
	fseek(fp, 0, SEEK_END);

	size_t sz_fl;	//declare a variable to store the size of the file we are going to open
	
	sz_fl = ftell(fp);
	fseek(fp, 0, SEEK_SET);	
	fread(buffer,sz_fl,1,fp);
	/*
		printf("%s/n",buffer);
	*/
	fclose(fp);
	return 0;
}
