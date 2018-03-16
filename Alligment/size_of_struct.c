#include<stdio.h>
/*
	static 
*/
typedef struct person{
	int age;
	int height;
	char name[5];
};



int main(void){
	struct person Bob = {18,180,"BOB"};
	/*
		Dynamic
	*/
	struct person Paul;


	Paul.age = "27";
	Paul.height = "172";
	Paul.name = "Paul";
	
	printf("the sizeof the Bob is %lu\n",sizeof(Bob));//%lu unsigned long
	printf("the size of the Paul is %lu\n",sizeof(Paul));
	return 0;
}
