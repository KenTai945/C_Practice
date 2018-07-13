#include <stdio.h>    // printf(), sprintf()

int main(void) 
{
    char str[10];
    int num = 961406;

    sprintf(str, "%d", num);/*	sprintf make the interger with string*/
	
	printf("str = %s\n", str);

    return 0;
}

