#ifndef C_HIERCH_H
#define C_HIERCH_H

typedef struct hierch {
    int *index;
    int num;
    char *dynamic_ic;
    struct hierch *h1;
    struct hierch *h2;
} Hierch;

typedef Hierch *Pref;

#endif
