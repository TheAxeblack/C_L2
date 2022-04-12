/*
 *Exemple d'implementation de pile avec un tableau
 *
 *pour plus de g�n�ricit� et de portabilit�, la pile
 *est mise dans une structure
 *
 *une solution plus simple serait de d�clarer une pile
 *comme un tableau global, il faudrait alors d�clarer
 *un sommet global et la taille max (au moins sous forme
 *de constante), mais c'est un peu moins facile � r�utiliser
 *
 *Ce fichier peut ensuite �tre compl�t� avec un fichier
 *pile.h o� l'on pourrait trouver les d�clarations de fonction
 *ainsi que la d�finition de la pile
 *
 *
 *hist A. Habrard, le 24/03/2014
 *   modification le 25/03/2015
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------ */

/*on defini le type des objets dans la pile, des entiers >0 par exemple*/
typedef int objet;

/*structure d�finissant  la pile*/
typedef struct struct_pile {
    int dimension_pile;
    objet *tab;
    int sommet;
} pile_struct;
typedef pile_struct *pile;

/* ------------------------------ */


/* creation d'une pile*/
pile creer_pile(int dim) {
    pile p = (pile) malloc(1 * sizeof(pile_struct));

    if (p == NULL) {
        fprintf(stderr, "Erreur creation pile\n");
        exit(EXIT_FAILURE);
    }

    p->tab = (objet *) calloc(dim, sizeof(objet));
    if (p->tab == NULL) {
        fprintf(stderr, "Erreur creation pile\n");
        exit(EXIT_FAILURE);
    }

    p->dimension_pile = dim;
    p->sommet = 0;

    return p;
}


/*test de pile vide */
int est_pile_vide(pile p) {
    if (p->sommet == 0)
        return 1;
    return 0;
}

/*test de piles pleine */
int est_pile_pleine(pile p) {
    if (p->sommet >= p->dimension_pile)
        return 1;
    return 0;
}

/* taille pile */
int taille(pile p) {
    return p->sommet;
}

/*test de pile */
int tete_pile(pile p) {
    if (!est_pile_vide(p))
        return p->tab[p->sommet - 1];
    return -1; /* ou faire une erreur*/
}

/* empiler un element,
   retourne 1 si pas d'erreur (donc il restait de la place dans la pile) */
int empiler(pile p, objet x) {
    if (!est_pile_pleine(p)) {
        p->tab[p->sommet] = x;
        p->sommet++;
        return (1);
    }

    fprintf(stderr, "Pile saturee\n");
    return (0);
}

/* depilement d'un objet */
objet depiler(pile p) {
    if (!est_pile_vide(p)) {
        objet x = p->tab[p->sommet - 1];
        p->sommet--;
        return (x);
    }

    fprintf(stderr, "Pile vide\n");
    return (-1);
}

/* exemple de main, vous pouvez afficher plus de messages pour voir ce qui se passe */

int main() {
    objet x;
    pile p = creer_pile(3);

    empiler(p, 1);
    empiler(p, 2);
    empiler(p, 3);
    empiler(p, 4);

    x = depiler(p);
    printf("%d\n", x);
    empiler(p, 5);
    x = depiler(p);
    printf("%d\n", x);
    x = depiler(p);
    printf("%d\n", x);
    x = depiler(p);
    printf("%d\n", x);
    x = depiler(p);
    printf("%d\n", x);

    return EXIT_SUCCESS;
}

