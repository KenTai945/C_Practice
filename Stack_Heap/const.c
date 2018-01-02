#include<stdio.h>
#include<stdlib.h>
/*
	practice for the constant and pointer

	(1)	global and constant
	
	(2)	what's the diferent between

		const int *ptr = &reference 

		and int const *ptr = &reference 

		*(a)  指針本身是常量不可變
    		(char*) const pContent;
    		const (char*) pContent;
 
   		*(b)  指標所指向的內容是常量不可變
    		const (char) *pContent;
    		(char) const *pContent;
*/



int e;//global

int main(void){

	const int a = 10;
	double c = 5.0;
	
	a=5;
	
	/*
	*	const.c: In function ‘main’:
	*	const.c:10:3: error: assignment of read-only variable ‘a’a=5;
	*/
	

	/*	
	const int *b = &a;
	*/
	/*
	(1)  指針本身是常量不可變
	(char*) const pContent;
	const (char*) pContent;
 
	(2)  指標所指向的內容是常量不可變
	const (char) *pContent;
	(char) const *pContent;

	*/
	int const *b = &a;

	b = &c;	
	return 0; 
}
