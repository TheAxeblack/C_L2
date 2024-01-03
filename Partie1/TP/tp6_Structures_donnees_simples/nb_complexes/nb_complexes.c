#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float p_reelle;
    float p_imaginaire;
} complexe;

complexe conjugue(complexe c)
{
    complexe res;

    res.p_reelle = c.p_reelle;
    res.p_imaginaire = 0 - c.p_imaginaire;
    return res;
}

complexe somme(complexe c1, complexe c2)
{
    complexe res;

    res.p_reelle = c1.p_reelle + c2.p_reelle;
    res.p_imaginaire = c1.p_imaginaire + c2.p_imaginaire;
    return res;
}

complexe difference(complexe c1, complexe c2)
{
    complexe res;

    res.p_reelle = c1.p_reelle - c2.p_reelle;
    res.p_imaginaire = c1.p_imaginaire - c2.p_imaginaire;
    return res;
}

complexe produit(complexe c1, complexe c2)
{
    complexe res;

    res.p_reelle = c1.p_reelle * c2.p_reelle - c1.p_imaginaire * c2.p_imaginaire;
    res.p_imaginaire = c1.p_reelle * c2.p_imaginaire + c1.p_imaginaire * c2.p_reelle;
    return res;
}

complexe division(complexe c1, complexe c2)
{
    complexe res;

    res.p_reelle = (c1.p_reelle * c2.p_reelle + c1.p_imaginaire * c2.p_imaginaire) / (c2.p_reelle * c2.p_reelle + c2.p_imaginaire * c2.p_imaginaire);
    res.p_imaginaire = (c1.p_imaginaire * c2.p_reelle - c1.p_reelle * c2.p_imaginaire) / (c2.p_reelle * c2.p_reelle + c2.p_imaginaire * c2.p_imaginaire);
    return res;
}

int main(void)
{
    complexe c1, c2, res;

    printf("Entrez un nombre complexe (reelle+imaginaire) : ");
    if (scanf("%f+%fi", &c1.p_reelle, &c1.p_imaginaire) != 2)
    {
        printf("Erreur de saisie\n");
        return EXIT_FAILURE;
    }

    printf("Entrez un nombre complexe (reelle+imaginaire) : ");
    if (scanf("%f+%fi", &c2.p_reelle, &c2.p_imaginaire) != 2)
    {
        printf("Erreur de saisie\n");
        return EXIT_FAILURE;
    }

    res = conjugue(c1);
    printf("Le conjugué de %f+%fi vaut %f+%fi\n", c1.p_reelle, c1.p_imaginaire, res.p_reelle, res.p_imaginaire);

    res = somme(c1, c2);
    printf("La somme de %f+%fi et %f+%fi vaut %f+%fi\n", c1.p_reelle, c1.p_imaginaire, c2.p_reelle, c2.p_imaginaire, res.p_reelle, res.p_imaginaire);

    res = difference(c1, c2);
    printf("La différence de %f+%fi et %f+%fi vaut %f+%fi\n", c1.p_reelle, c1.p_imaginaire, c2.p_reelle, c2.p_imaginaire, res.p_reelle, res.p_imaginaire);

    res = produit(c1, c2);
    printf("Le produit de %f+%fi et %f+%fi vaut %f+%fi\n", c1.p_reelle, c1.p_imaginaire, c2.p_reelle, c2.p_imaginaire, res.p_reelle, res.p_imaginaire);

    res = division(c1, c2);
    printf("La division de %f+%fi et %f+%fi vaut %f+%fi\n", c1.p_reelle, c1.p_imaginaire, c2.p_reelle, c2.p_imaginaire, res.p_reelle, res.p_imaginaire);

    exit(EXIT_SUCCESS);
}