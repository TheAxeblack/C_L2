#include <stdio.h>
#include <stdlib.h>

void change(int x)
{
    x = 5;
}

void change2(int *x)
{
    *x = 5;
}

int main(void)
{
    int a = 42;
    change(a);
    printf("a = %d\n", a);
    change2(&a);
    printf("a = %d", a);
    exit(EXIT_SUCCESS);
}