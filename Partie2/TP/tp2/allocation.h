#include <stddef.h>

#ifndef TP_ALLOCATION_H
#define TP_ALLOCATION_H

void *allocation_mem(size_t nbitems, size_t taille);

void *allocation_mem_init0(size_t nbitems, size_t taille);

void *reallocation_mem(void *pt, size_t nbitems, size_t taille);

void *reallocation_mem_peda(void **pt, size_t nbitems, size_t taille);

void libere_mem(void *pt);

void libere_mem_peda(void **pt);

void libere(void *pt);

#endif
