#include "../inc/usage.h"

void ft_usage(char *name) {
    fprintf(stderr, "Usage %s TD4 : <expression_arithmetique>\n<expression_arithmetique> doit comporter"
                    " des operateurs ainsi que des chiffres.\nListe des operateurs disponibles  : < + * - / >\n"
                    "Les chiffres vont de 0 a 9\n", name);
    exit(EXIT_FAILURE);
}