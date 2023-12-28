#include <stdio.h>
#include <stdlib.h>

void ft_valeurs(void) {
    int a, b, c, d;

    a = 5;
    b = -4;
    c = 3;
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);
    d = a + b;
    printf("d = %d\n", d);
    b = d;
    printf("b = %d\n", b);
    d = a + b;
    printf("a = %d, b = %d, c = %d et d = %d\n", a, b, c, d);
}

int main(void) {
    ft_valeurs();
    exit(EXIT_SUCCESS);
}
