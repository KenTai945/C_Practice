#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};
struct node *findtail(struct node *head)
{
    struct node *current_tail;
    
	current_tail = head;
    while(current_tail->next != NULL){
        current_tail = current_tail->next;
    }
	//printf("the last node's value is %d\n",current_tail->value);                    
	return current_tail;
}  
struct node *find_the_node_before_tail(struct node *head){
	struct node *current;
	struct node *pre_tail;
    
    current = head;
    while(current->next != NULL){
		pre_tail = current;
        current = current->next;
    }
    
	//printf("the node before the last node's value is %d\n",pre_tail->value);                    
	return pre_tail;
}
void create_new_node(struct node *head,int val){
	struct node *tmp;
	
	struct node *tail;
	
	tmp = malloc(sizeof(struct node));
	tmp->value = val;
	tail = findtail(head);
	//traserval to find tail;
	/*
	findtail(head);
	struct node *current_tail;
	current_tail = head;
	while(current_tail->next != NULL){
		current_tail = current_tail->next;
	}
	*/
	tail->next = tmp;
	tmp->next = NULL;
}
struct node *remove_head_node(struct node *head){
	struct node *current;
	
	current = head->next; 
	free(head);
	PrintALL(current);
	return current;
}
struct node *remove_tail_node(struct node *head){
	struct node *current;
	
	struct node *precurrent;
	
	precurrent = head;
	current = findtail(head);
	precurrent = find_the_node_before_tail(head);
	precurrent->next = NULL;
	return current; 
}
/*
struct node *find_node(struct node *head,val){
	struct node *current
	

}
*/
//struct node *remove_middle_node()
void PrintALL(struct node *head){

	struct node *current;
	current = head;
	while(current != NULL){/*(bug) current->next != NULL*/
		printf("the value in the node is %d\n",current->value);
		current = current->next;
	}
	printf("We have print out all all the node\n");
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
	create_new_node(head,2);
	create_new_node(head,3);
	create_new_node(head,4);
	printf("print out all of the node\n");	
    PrintALL(head);
	printf("after delete head\n");
	remove_head_node(head);
	PrintALL(head);
	printf("after delete tail\n");
	remove_tail_node(head);
	PrintALL(head);
	return 0;
}
