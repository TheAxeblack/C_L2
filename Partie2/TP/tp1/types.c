#include <stdio.h>

int main(void) {
    int i = 2;
    float x;
    x = 5 / i;
    printf("Valeur de x: %d\n", x);
    return 0;
}

/* Si l'on remplace x = 5 / i par
 *      x = 5.0 / i --> Valeur de x: 2.500000
 *      x = 5. / i --> Valeur de x: 2.500000
 *      x = 5 / (float) i --> Valeur de x: 2.500000
 *      x = (float) 5. / i --> Valeur de x: 2.500000
 *
 *
 * Si l'on remplace le dernier printf par :
 *      printf("Valeur de x: %d\n", x); --> On obtient le warning suivant :
 *      types.c: In function ‘main’:
        types.c:7:27: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘double’ [-Wformat=]
        printf("Valeur de x: %d\n", x);
                             ~^     ~
                             %f

 * Et on obtient Valeur de x: 2125822504
 * Si l'on est sûr de nous, on modifie le type de x de float à int
 */