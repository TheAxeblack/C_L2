#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *str) {
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int mystrcmp(char *str1, char *str2) {
    int i;

    i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0') {
        i++;
        if (str1[i] == '\0' && str2[i] == '\0')
            return (0);
        if (str1[i] < str2[i])
            return (-1);
        if (str2[i] < str1[i])
            return (1);
    }
    return (0);
}

void    delspace(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = str[i + 1];
        i++;
    }
    str[i] = '\0';
}

int strsubs(char *str, char  *motif, int pos, int len)
{
    int i;
    int j;

    for (i = pos, j = 0; j < len && str[i] != '\0' && motif[j] != '\0'; i++, j++)
        str[i] = motif[j];
    return (j);
}

void min2maj(char *str) {
    int i;
    int diff;

    diff = 'A' - 'a';
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += diff;
}

int main(void)
{
    char s[] = "bonjour a tous";
    delspace(s);
    printf("s = \"%s\"\n", s);
    exit(EXIT_SUCCESS);
}