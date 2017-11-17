#include<stdio.h>

typedef struct person{
	int age;
	int height;
	char name[5];
};



int main(void){
	struct person Bob = {18,180,"BOB"};

	printf("the sizeof the Bob is %lu\n",sizeof(Bob));



	return 0;
}
