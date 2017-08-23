#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};

int create_new_node(struct node *head_address,struct node *new_node_address,int val){
	new_node_address = malloc(sizeof(struct node));
	new_node_address->value = val;

	//traserval to find tail;
	struct node *current_tail;
	current_tail = head;
	while(current_tail->next != NULL){
		current_tail = current_tail->next;
	}
	current_tail->next = new_node_address;
	new_node_address->next = NULL;
}
int main(void){
	//craete the node of head 
	struct node *head;
	head =  malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("memory allocate is fialed\n");
	}
	head->value = 0;
	head->next = NULL;
	//creatd the node tail
	struct node *tail;
	
	tail = malloc(sizeof(struct node));
	if(tail == NULL)
    {
        printf("memory allocate is fialed\n");
    }
	tail->value = 1;
	tail->next = NULL;
	head->next = tail;
	
	struct node third;
	create
	struct node fourth;
	
	return 0;
}
