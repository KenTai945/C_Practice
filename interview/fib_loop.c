#include <stdio.h>
#include <stdlib.h>

static inline void fifo_init(int *fifo, int len)
{
	for(int i = 0; i < len; ++i)
		fifo[i] = 0;
}

static inline void fifo_update(int *fifo, int len, int val)
{
	// shift
	for(int i = 0; i < len-1; ++i)
		fifo[i] = fifo[i+1];
	// add new value
	fifo[len-1] = val;
}

static inline int fifo_sum(int *fifo, int len)
{
	int sum = 0;

	for(int i = 0; i < len; ++i)
		sum += fifo[i];

	return sum;
}

int main(int argc, char **argv)
{
	int tmp[2];

	if(argc < 2){
		printf("%s [n-element]\n", argv[0]);
		return -1;
	}

	fifo_init(tmp , 2);

	for(int i = 0; i < atoi(argv[1]); ++i){
		if(i == 0){
			printf("%d ", i);
			continue;
		}
		if(i == 1){
			printf("%d ", i);
			fifo_update(tmp, 2, 1);
			continue;
		}
		int num = fifo_sum(tmp, 2);
		printf("%d ", num);
		fifo_update(tmp, 2, num);
	}
	printf("\n");	

	return 0;
}
	
