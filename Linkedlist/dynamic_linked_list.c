
#include<stdlib.h>


struct node{
	int value;
	struct node *next;
	/*
		指標可以指向c語言提供的資料型態,同樣的指表可以指向結構
		
		結構指標也是指標的一種,（指像結構的指標）
	*/
};
/*
global 少用
*/

/* build up the node*/

void Add_Node(struct node *head_ptr,struct node *new_ptr_address,int val){
	
	//struct node *tmp_new;//宣告要空一行
	
	new_ptr_address = malloc(sizeof(struct node));//intialize
	new_ptr_address -> value = val;
	if(new_ptr_address == NULL){
        printf("malloc failed!\n");
        return -1;
    }
	struct node *tail = head_ptr;
	while( tail->next != NULL ){                                                                                                                                       
        tail = tail->next;
    }   
	tail->next = new_ptr_address;
	new_ptr_address->next = NULL;
	print_all(head_ptr);  
}

// find tail
/*
struct node *Find_Tail(struct node *head)
{
    struct node *tail = head;
    
    while( tail->next != NULL ){                                                                                                                                       
        tail = tail->next;
    }
    printf("the value of the last node is %d\n",tail->value);
    return Find_Tail;
}
*/

/*
	尋訪
*/

void print_all(struct node *head)
{
    struct node *current;

    current = head;

    if(head == NULL)
        return;

    while(current != NULL)
    {
        printf("the value of the node is%d\n",current->value);
        current = current->next;    
    }
}


int main(void)
{
	struct node *head;// declare a pointer *head point to "structure node"（型態）
	head = malloc(sizeof(struct node));// intialize (實體) struct node head(分配一段動態記憶體給他,他才會存在）
    if(head == NULL){
        printf("malloc failed!\n");
        return -1;
    }
    
    head->value = 1;
    head->next = NULL;
    struct node *tail;//declare 4 byte pointer dynamic
    tail = malloc(sizeof(struct node));
    if(tail == NULL){
        printf("malloc failed!\n");
        return -1;
    }
	tail->value = 2;
    tail->next = NULL;
	
	head->next = tail;//link the struct node to the struct tail

	 //開新的點
    struct node *new_node; 
    new_node = malloc(sizeof(struct node));
    new_node->value = 3;
    new_node->next = NULL;

	/*找到tail加進去
	struct node *find_tail = head;
	
	while(find_tail->next != NULL)
	{
		find_tail = find_tail->next;
	}
	*/
	tail->next = new_node;
 	 //開第二個新的點
    struct node *new_node2; 
    new_node2 = malloc(sizeof(struct node));
    new_node2->value = 4;
    new_node2->next = NULL;

    /*找到tail加進去

    
    while(find_tail->next != NULL)
    {
        find_tail = find_tail->next;
    }
	*/
    new_node->next = new_node2;
	struct node *node5;
	Add_Node(head,node5,5);
}
