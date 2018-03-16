#include<stdio.h>
#include<stdlib.h>

struct foo{
	int a;
	int b;
};
int main(void)
{
	struct foo Fool1 = {
		.a = 1,
		.b = 2,
	};
	struct foo Fool2;
	Fool2.a = 3;
	Fool2.b = 4;

	struct foo Foo3[] = {
		{1,2}, {3,4},
	};
	struct foo Foo4[] = {
		[0] = {
			.a = 1,
			.b = 2,
		},
		[1] = {
			.a = 3,
			.b = 4,
		},
	};
	return 0;
}
