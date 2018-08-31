#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	//declare txt as array of pointer to char
	char *txt[3] = {"one", "two", "three"};

	printf("the first element of the txt array is %s\n",*(txt));
	return 0;
}

