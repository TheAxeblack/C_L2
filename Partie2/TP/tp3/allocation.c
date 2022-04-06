#include "tp3.h"

void libere_mem(void *pt) {
    void **adr_pt = (void **) pt;
    if ((*adr_pt) != NULL)
        free(*adr_pt);
    *adr_pt = NULL;
}