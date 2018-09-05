#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 *  Think about the meachanism of printf("%s",print_ssid); print_ssid is a pointer point to the beginning of the array
 */
void printf_string(char *print_ssid)
{
	printf("printf the pointer of print_ssid with p and result is %p\n",print_ssid); // what's the result?
	printf("printf the pointer of print_ssid with s and the result is %s\n",print_ssid); // this is the string address
	printf("print the string with for loop by character\n");	
	for(char *ptr_count = print_ssid; *ptr_count != '\0';ptr_count++)
	{
		printf("%c",*ptr_count);
	}
	printf("\n");
}



int main(void)
{
	char ssid[16] = "testing";

	char *ssid_ptr1 = &ssid[0];//char *ssid_ptr = ssid;

	char *ssid_ptr2 = ssid;
	
	printf("the address of ssid_ptr1 point to is %p\n",ssid_ptr1);
	
	printf("the address of ssid_ptr2 point to is %p\n",ssid_ptr2);

	printf_string(ssid);
	return 0;
}
