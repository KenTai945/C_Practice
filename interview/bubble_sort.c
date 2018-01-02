#include <stdio.h>
/*
	There are three ways to do the swap function.
	(1) Using tmp
	(2) +,+,-
	(3) "xor"

*/
int data[] = {1, 20, 18, 33, 49, 21, 20, 52, 3, 5, 8, 109, 38};

static inline void swap(void *a, void *b)
{
	int *tmp1 = (int *)a;
	int *tmp2 = (int *)b;

	*tmp1 ^= *tmp2;
	*tmp2 ^= *tmp1;
	*tmp1 ^= *tmp2;
}

int main(void)
{
	printf("Befor sorting: ");
	for(int i = 0; i < sizeof(data)/sizeof(int); ++i)
		printf("%d ", data[i]);
	printf("\n");
	
	for(int i = sizeof(data)/sizeof(int); i > 0; --i){
		for(int j = 0 ; j < i-1; j++){
			if(data[j] > data[j+1])
				swap(&data[j], &data[j+1]);
		}
	}
	
	printf("After sorting: ");
	for(int i = 0; i < sizeof(data)/sizeof(int); ++i)
		printf("%d ", data[i]);
	printf("\n");
	
	return 0;
}
