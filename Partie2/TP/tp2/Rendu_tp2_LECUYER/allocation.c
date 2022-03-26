#include <stdio.h>
#include <stdlib.h>
#include "erreur.h"
#include "allocation.h"

void *allocation_mem(size_t nbitems, size_t taille) {
    void *pt;

    pt = malloc(nbitems * taille);

    if (pt == NULL)
        mon_erreur("Impossible d'allouer la memoire %d %d\n", nbitems, taille);

    return (pt);
}

void *allocation_mem_init0(size_t nbitems, size_t taille) {
    void *pt;

    pt = calloc(nbitems, taille);

    if (pt == NULL)
        mon_erreur("Impossible d'allouer la memoire %d * %d\n", nbitems, taille);

    return (pt);
}

void *reallocation_mem(void *pt, size_t nbitems, size_t taille) {
    void *pt_realloc = realloc(pt, nbitems * taille);
    if (pt_realloc == NULL)
        mon_erreur("Impossible de reallouer la memoire %d * %d a l'adresse %p\n", nbitems, taille, pt);
    return pt_realloc;
}

void *reallocation_mem_peda(void **pt, size_t nbitems, size_t taille) {
    void *pt_realloc = realloc(*pt, nbitems * taille);
    if (pt_realloc != NULL)
        *pt = pt_realloc;
    else
        mon_erreur("Impossible de reallouer la memoire %d * %d a l'adresse %p\n", nbitems, taille, *pt);

    return pt_realloc;
}

void libere_mem(void *pt) {
    void **adr_pt = (void **) pt;
    if ((*adr_pt) != NULL)
        free(*adr_pt);
    *adr_pt = NULL;
}

void libere_mem_peda(void **pt) {
    if ((*pt) != NULL)
        free(*pt);
    *pt = NULL;
}

void libere(void *pt) {
    free(pt);
}
