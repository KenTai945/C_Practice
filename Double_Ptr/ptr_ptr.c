#include <stdio.h>

int main()
{
    int p = 10;
    int *ptr1 = &p;
    int **ptr2 = &ptr1;

    printf("p的值：%d\n", p);
    printf("p的記憶體位置: %p\n", &p);
    printf("\n");

    printf("*ptr1 = %d\n", *ptr1);
    printf("ptr1 = %p\n", ptr1);
    printf("ptr1的記憶體位置: %p\n", &ptr1);
    printf("\n");

    printf("**ptr2 = %d\n", **ptr2);
    printf("*ptr2 = %p\n", *ptr2);
    printf("ptr2 = %p\n", ptr2);
    printf("\n");

    printf("整理：\n");
    printf("&p = %p\n", &p);
    printf("ptr1 = %p\n", ptr1);
    printf("&ptr1 = %p\n", &ptr1);
    printf("ptr2 = %p\n", ptr2);

    return 0;
}
