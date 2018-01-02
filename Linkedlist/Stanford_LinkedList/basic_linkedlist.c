#include<stdio.h>
#include<stdlib.h>


struct node {
    int value;
    struct node *next;
};

int Length(struct node* head){
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/*

	create the new node and store the data in the linkedlist

*/

struct node *find_tail_node(struct node *head)
{
	struct node *current = head; 
	while(current->next != NULL)
	{
		current = current->next;
	}	
	return current;
}

void add_node_push(struct node *current_head,int data)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("memory allocated is failed\n");
	}
	
	struct node *current_tail;

	current_tail = find_tail_node(current_head);

	current_tail->next = new_node;

	new_node->value = data;
	new_node->next = NULL;
}

int main(void)
{
    struct node *head;

    head = malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory allocated is failed\n");
    }

	
    struct node *tail;
    tail = malloc(sizeof(head));
    if (tail == NULL)
    {
        printf("memory allocated is failed\n");                                 
    }
	head->value = 1;
	head->next = tail;
	tail->value = 0;
	tail->next = NULL;

	add_node_push(head,2);
	
    return 0;
} 
