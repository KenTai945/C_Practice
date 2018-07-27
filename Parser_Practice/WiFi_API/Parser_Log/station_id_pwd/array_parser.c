#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	FILE *fp;
	
	char buf[128] = {0};
	char ssid[16] = {0};
	char passwd[16] = {0};

	size_t rlen;//return length
	fp = fopen("ssid_pwd.txt","r");//open file
	//assert(fp);

	/*
		read all file into buffer
		(1)read sizeof(buf)/1 data elements, each of which is 1 byte long.
	*/
	
	rlen = fread(buf,1,sizeof(buf), fp);

	buf[rlen] = '\0';
	/*
		(1)Null-terminated string,The length of a C string is found by searching 		for the (first) NUL byte. 
		(2) In order to avoid contaion other stuff which is not cleared
	*/

	/*
		get ssid
		(1)find the end the first line
		(2)store the firstline (memcpy)
	*/
	int pos;
	for(pos = 0;pos < rlen; pos++)
	{
		if(buf[pos] == '\n'){
			break;
		}
	}

	memcpy(ssid,buf,pos+1);
	ssid[pos+2] = '\0';
	printf("\nthe ssid what we got is %s\n",ssid);
	/*
		get pwd
		(1)keep find the last line of the string
		(2)store the second line()
		
		BUG:
		(1) need to know the sizeof buffer 
		
		Solved:
		
		(2) sloved the problem
		Problem:
		The pwd may printf something else?
	*/
	int count =0;
	/* 	*/
	char *string_ptr;
	for(string_ptr = (buf+pos-2); *string_ptr != '\0'; string_ptr++){
		//printf("%c\t",*string_ptr);
		count ++;
	}
	// Bug	memcpy(passwd,&passwd[pos+1],sizeof(passwd));   &passwd[pos+1] is the address
	memcpy(passwd, &buf[pos+1], sizeof(passwd)/sizeof(passwd[0]));
	printf("\n the password what we got is %s\n",passwd);
	return 0;
}
