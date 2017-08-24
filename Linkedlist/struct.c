#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *next;
};

int main(void){
	struct node *head;
	struct node *current;
	printf("the sizeof of the head pointer is %lu\n",sizeof(head));
	printf("the address of the head pointer is %p\n",head);
	printf("the sizeof of the current pointer is %lu\n",sizeof(current));
	printf("the address of the current pointer is %p\n",current);
	head = malloc(sizeof(struct node));
	printf("memorry allocation for the head\n");
	printf("the sizeof of the head pointer is %lu\n",sizeof(head));
	printf("the address of the head pointer is %p\n",head);
	printf("the address of the current pointer is %p\n",current);
	current = head;
	printf("we assign head the current pointer\n");
	printf("the address of the current pointer is %p\n",current);
	printf("the value of the current pointer is %p\n",*current);// it must be error


}
