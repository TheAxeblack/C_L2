#include "../inc/mystere.h"

int mystere(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (n + mystere(n / 4));
}