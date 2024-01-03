#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hh;
    int mm;
    int ss;
} heure;

int heure2secondes(heure h)
{
    return h.hh * 3600 + h.mm * 60 + h.ss;
}

heure secondes2heure(int s)
{
    heure h;

    h.hh = s / 3600;
    h.mm = (s % 3600) / 60;
    h.ss = (s % 3600) % 60;
    return h;
}

heure add(heure h1, heure h2)
{
    return secondes2heure(heure2secondes(h1) + heure2secondes(h2));
}

int main(void)
{
    heure h1, h2, res;

    printf("Entrez une heure (hh:mm:ss) : ");
    if (scanf("%d:%d:%d", &h1.hh, &h1.mm, &h1.ss) != 3)
    {
        printf("Erreur de saisie\n");
        return EXIT_FAILURE;
    }

    printf("Entrez une heure (hh:mm:ss) : ");
    if (scanf("%d:%d:%d", &h2.hh, &h2.mm, &h2.ss) != 3)
    {
        printf("Erreur de saisie\n");
        return EXIT_FAILURE;
    }

    res = add(h1, h2);
    printf("L'addition des deux heures vaut %d:%d:%d\n", res.hh, res.mm, res.ss);
    exit(EXIT_SUCCESS);
}