#include<stdio.h>
#include<string.h>

int main ()
{
	char a[] ="Just some random string";
	char * ptr_b;
	ptr_b = strstr (a,"other some random");
	if(ptr_b != NULL)
	{
		printf("found\n");
	}
	else
	{
		printf("not found \n");
	}
	return 0;
}
