# Équivalence des instruction répétitives

Que fait le programme ci-dessous ?

```c
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i;
    for (i = 0; i < 10; i = i + 1) {
        printf("le carree de %d est : %d\n, i, i * i);
    }
    exit(0);
}
```

Ré-écrire un programme équivalent avec l'instruction *while*, puis avec l'instruction *do $\ldots$ while*.