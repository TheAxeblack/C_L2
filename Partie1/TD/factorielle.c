#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
    int	result;

    result = 1;
    while (nb > 0)
    {
        result = nb * result;
        nb--;
    }
    return (result);
}

int main(void)
{
    int n;
    n = ft_iterative_factorial(10);
    printf("%d\n", n);
    exit(0);
}