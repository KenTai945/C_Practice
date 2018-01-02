#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

static struct node *_new(int val)
{
	struct node *tmp;
	
	tmp = malloc(sizeof(struct node));
	assert(tmp);
	tmp->val = val;
	tmp->next = NULL;

	return tmp;
}

static int ll_get_len(struct node *head)
{
	int len = 0;
	
	while(head){
		head = head->next;
		len++;
	}
		
	return len;
}

static void ll_free_all(struct node *head)
{
	struct node *rm;
	
	while(head){
		rm = head;
		head = head->next;
		free(rm);
	}
}

static void ll_free_node(struct node **head, int targ)
{
	struct node **p = head;

	if(!*p) return;	

	while(*p){
		if((*p)->val == targ){
			free(*p);
			*p = (*p)->next;
		}else{
			p = &((*p)->next);
		}
	}
}

static struct node *ll_find_tail(struct node *head)
{
	if(!head) return head;

	while(head->next)
		head = head->next;
	
	return head;
}

static void ll_display(struct node *head)
{
	while(head){
		printf("%d -> ", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

static void ll_add_node(struct node **head, int val)
{
	struct node *tail;

	// nothing
	if(*head == NULL){
		*head = _new(val);
	}else{
		tail = ll_find_tail(*head);
		tail->next = _new(val);
	}
}

static void ll_add_nth_node(struct node **head, int n, int val)
{
	struct node *tmp;
	struct node **p = head;

	if(!*p) return;

	tmp = _new(val);
	// be new head
	if(n == 1){
		tmp->next = *head;
		*head = tmp;
	}else{
		for(int i = 1; *p; ++i, p = &((*p)->next)){
			if(i == n-1){
				tmp->next = (*p)->next;
				(*p)->next = tmp;
				break;
			}
		}
	}
}

static void ll_free_nth_node(struct node **head, int n)
{
	struct node **p = head;

	if(!*p) return;

	for(int i = 1; *p; ++i, p = &((*p)->next)){
		if(i == n){
			free(*p);
			*p = (*p)->next;
			break;
		}
	}
}

static void ll_reverse(struct node **head)
{
	struct node *prev = NULL, *next;
	
	while(*head){
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
}

#define OPTMSG \
	"1)\tAdd node\n" 		\
	"2)\tRemove node\n" 	\
	"3)\tAdd a node to be n-th\n"\
	"4)\tRemove n-th node\n"\
	"5)\tReverse list\n"	\
	"6)\tGet list length\n"	\
	"7)\tDisplay\n"			\
	"8)\tExit\n"

int main(void)
{
	int opt;
	int val;
	int exit = 0;
	struct node *head = NULL;

	do{
		printf("Options:\n"OPTMSG);
		printf("# ");
		scanf("%d", &opt);
		printf("\n");

		switch(opt){
			case 1:
				printf("Enter the data: ");
				scanf("%d", &val);
				ll_add_node(&head, val);
				break;
			case 2:
				printf("Enter the data: ");
				scanf("%d", &val);
				ll_free_node(&head, val);
				break;
			case 3:
			case 4:
			{
				int nth;
				do{
					printf("Enter the order: ");
					scanf("%d", &nth);
				}while(nth < 1);
				if(opt == 3){
					printf("Enter the data: ");
					scanf("%d", &val);
					ll_add_nth_node(&head, nth, val);
				}else{
					ll_free_nth_node(&head, nth);
				}
				break;
			}
			case 5:
				ll_reverse(&head);
				break;
			case 6:
				printf("Length = %d\n", ll_get_len(head));
				break;
			case 7:
				ll_display(head);
				break;
			case 8:
				printf("bye bye~\n");
				exit = 1;
				break;
			default:
				printf("Unknow options!\n");
				break;
		}
	
		if(exit) break;
		printf("\n");
	}while(1);
	
	ll_free_all(head);

	return 0;
}
