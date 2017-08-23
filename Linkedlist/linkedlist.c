#include <stdio.h>
#include <stdlib.h>

/* It's only defined */
struct node {
	int value;
	struct node *next;
};

struct node *find_tail(struct node *head)
{
	struct node *tail = head;
	
	while( tail->next != NULL ){
		tail = tail->next;
	}
	
	return tail;
}

void list_add(struct node *head, int val)
{
	struct node *tmp;
	
	tmp = malloc(sizeof (struct node));
	if (tmp == NULL){
		printf("malloc failed!\n");
		return;
	}
	/*
		
	*/
	tmp->value = val;
	tmp->next = NULL;
	// to linked it, need to find tail, but how?
	// use loop to check next is pointing to NULL or not
	struct node *tail = find_tail(head);
/*
	struct node *cur;
	cur = head;
	while( cur -> next != NULL)//判斷式對的才會進入迴圈 若是== 都不會進入迴圈
	{
		cur = cur->next;
	}
	printf("now, current point to tail\n");
	//tail->next = tmp;
	cur -> next = tmp;
	
	圖解後把每個細微的步驟分析後,會重複的動作寫成function 方便之後使用 
	這種就算弄一個簡單的api（call function)
*/
	tail->next = tmp;
}

struct node *find_node(struct node *head, int val)//return 一個pointer!!!!!!
{
	struct node *tmp;

	tmp = head;
	while(tmp->next != NULL)//參考上面的 我寫兩個式子太低能
	{
		if (tmp->value == val)
		{
			return tmp;
		}
		tmp = tmp->next; 
	}
	printf("there is no value in the linked list\n");
	//return tmp;如果沒有找到就不要return 東西回去（這是一個判斷的問題非常重要不然debug會很慘）
	retuen NULL;//這個
}

void print_all(struct node *head)
{
	struct node *current;

	current = head;

	if(head == NULL)
		return;
		
	while(current != NULL)
	{
		printf("%d",current->value);
		current = current->next;	
	}
}

int main(void)
{
	struct node *head;//declare 4 byte pointer dynamic 
    
	head = malloc(sizeof(struct node));
	if(head == NULL){
		printf("malloc failed!\n");
		return -1;
	}
	
	head -> value = 1;
	// on tail, the next must point to NULL
	head -> next = NULL;

	list_add(head, 2);
	list_add(head, 3);
	find_node(head, 3);
	struct node *tail;//declare 4 byte pointer dynamic
	tail = malloc(sizeof(struct node));
	if(tail == NULL){
        printf("malloc failed!\n");
        return -1;
    }
	tail -> next = NULL;
	return 0;
}
