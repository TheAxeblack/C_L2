#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *min_only(char *str) {
    char *res = NULL;
    char *p = NULL;
    int i, taille = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            taille++;

    res = (char *) malloc(taille * sizeof(char));
    assert(res != NULL);
    p = res;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            *p++ = str[i];
        }
    }
    return res;
}

int main(void) {
    char *str = "CHARcharChAr";
    char *res;
    res = min_only(str);
    printf("%s\n", res);
}