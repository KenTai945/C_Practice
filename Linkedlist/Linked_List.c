#include<stdio.h>
#include<stdlib.h>
/*
	practice for the linkedlist 
	
	(1)creat list
	(2)traversal
	(3)deleted node
		(1)head
		(2)tail
		(3)middle part
*/
// definition of the struct
struct node 
{
	int value;
	struct node *next;
};

void create_new_node(int head,int value)
{
	struct node *new_node;
	new_node = malloc(sizeof(node));
	if (new_node == NULL)
	{
		
	}

}


int main(void)
{
	struct node *head;
	head = malloc(sizeof(node));
	if (head == NULL)
	{
		printf("memory allocated is failed\n");
	}
	struct node *tail;
	tail = malloc(sizeof(head));
	if (tail == NULL)
	{
		printf("memory allocated us failed\n");
	}
	
}
