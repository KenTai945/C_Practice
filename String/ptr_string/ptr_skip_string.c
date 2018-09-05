#include<stdio.h>
#include<stdlib.h>
/*
	Target:
	(1)	practice to declare a string
	(2)	practice to use the function of "puts"
	(3) know the how mechanism of pointer in string
*/

void skip(char *msg)
{
	puts(msg+4);
	printf("\n%s\n",(msg+4));	
}


int main(void)
{
	char *whole_message = "One Two Three";
	/* 
		one two three |  one two three
		^			  |      ^
		|					 | 
						(shift right 4,hence )  
	*/
	printf("printf the whole string\n");
	puts(whole_message);
	printf("skip the first word\n");
	skip(whole_message);
	return 0;
}
