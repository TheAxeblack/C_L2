#include <stdio.h>

int ackermann_aux(int m, int n) {
    if (m == 0)
        return (n + 1);
    else if (m > 0 && n == 0)
        return (ackermann_aux(m - 1, 1));
    else if (m > 0 && n > 0)
        return (ackermann_aux(m - 1, ackermann_aux(m, n - 1)));
    else
        return 1;
}

int ackermann(int m, int n) {
    return ackermann_aux(m, n);
}
/* Valeur maximale pour m : 5 et valeur maximale pour n (si m vaut 5) : 0 */

int main(void) {
    printf("%d\n",ackermann(0, 1));
    printf("%d\n",ackermann(2, 0));
    printf("%d\n",ackermann(4, 2));
    printf("%d\n",ackermann(2, 3));
    return 0;
}