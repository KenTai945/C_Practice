#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXSIZE	128 

struct Qinfo {
	int32_t *const buffer;
	int front;
	int rear;
	int flag;
	const int max;
	void (*push) (struct Qinfo *self, int32_t data);
	int32_t (*pop) (struct Qinfo *self);
	int (*isFull) (struct Qinfo *self);
	int (*isEmpty) (struct Qinfo *self);
	void (*display) (struct Qinfo *self);
};

static void rb_push(struct Qinfo *self, int32_t data)
{
	if(self->isFull(self)){
		printf("ERROR: The ring buffer is FULL!\n");
		return;
	}

	// add in rear
	self->rear = (self->rear+1)%(self->max);
	self->buffer[self->rear] = data;
	// update flag
	if(self->rear == self->front) self->flag = 1;
}

static int32_t rb_pop(struct Qinfo *self)
{
	int32_t val;

	if(self->isEmpty(self)){
		printf("ERROR: The ring buffer is Empty!\n");
		return 0;
	}

	self->front = (self->front+1)%self->max;
	val = self->buffer[self->front];
	// update flag
	if(self->rear == self->front) self->flag = 0;
	
	return val;
}

static int rb_isFull(struct Qinfo *self)
{
	return ((self->rear % self->max == self->front && self->flag) || 
			((self->rear == self->max-1 && self->front == -1)));
}

static int rb_isEmpty(struct Qinfo *self)
{
	return (self->front == self->rear);
}

static void rb_display(struct Qinfo *self)
{
	printf("Front(%d), Rear(%d), flag(%d), Buffer: ", 
			self->front, self->rear, self->flag);
	for(int i = 0; i < self->max; ++i)
		printf("%d ", self->buffer[i]);
	printf("\n");
}

#define RINGBUF_DEF(name, size)	\
	int32_t name##_pool[size] = {0}; \
	struct Qinfo name = {			\
		.buffer = name##_pool,	\
		.front = -1,			\
		.rear = -1,				\
		.max = size,			\
		.push = rb_push,		\
		.pop = rb_pop,			\
		.isFull = rb_isFull,	\
		.isEmpty = rb_isEmpty,	\
		.display = rb_display,	\
	};							

int main(int argc, char **argv)
{
	int opt;
	int32_t data;

	RINGBUF_DEF(rb, 16);
	
	do{
		printf("Options:\n"
				"1)\tPush data\n"
				"2)\tPop data\n"
				"3)\tDisplay\n"
				"4)\tExit\n");
		scanf("%d", &opt);
	
		switch(opt){
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				rb.push(&rb, data);
				break;
			case 2:
				data = rb.pop(&rb);
				printf("Pop data: %x\n", data);
				break;
			case 3:
				rb.display(&rb);
				break;
			case 4:
				printf("Bye Bye\n");
				return 0;
			default:
				printf("Unkonw options!\n");
		}
	}while(1);
	
	return 0;
}
