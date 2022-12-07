#include "ex2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficheEtudiant(etudiant e)
{
    fprintf(stdout, "%d %s %s\n", e.id, e.nom, e.prenom);
}

void affichePromo(promo p)
{
    int i;
    for (i = 0; i < p.nb_etudiants; i++)
    {
        afficheEtudiant(p.tab[i]);
    }
}

void lecturePromo(FILE *f, promo *p)
{
    int i = 0;
    while (fscanf(f, "%s; %s; %d\n", p->tab[i].nom, p->tab[i].prenom, &p->tab[i].id) == 3)
        i++;
    p->nb_etudiants = i;
}

void triPromo(promo *p)
{
    int i;
    int j;
    etudiant tmp;
    for (i = (p->nb_etudiants - 1); i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (p->tab[j + 1].id < p->tab[j].id)
            {
                tmp.id = p->tab[j].id;
                strcpy(tmp.prenom, p->tab[j].prenom);
                strcpy(tmp.nom, p->tab[j].nom);
                p->tab[j].id = p->tab[j + 1].id;
                strcpy(p->tab[j].prenom, p->tab[j + 1].prenom);
                strcpy(p->tab[j].nom, p->tab[j + 1].nom);
                p->tab[j + 1].id = tmp.id;
                strcpy(p->tab[j + 1].prenom, tmp.prenom);
                strcpy(p->tab[j + 1].nom, tmp.nom);
            }
        }
    }
}

int main(void)
{
    FILE *fichier = NULL;
    promo p;
    fichier = fopen("promo.txt", "r");
    if (fichier == NULL)
    {
        printf("Vous tentez d'ouvrir un fichier inexistant\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        lecturePromo(fichier, &p);
        triPromo(&p);
        affichePromo(p);
        fclose(fichier);
    }
    exit(EXIT_SUCCESS);
}