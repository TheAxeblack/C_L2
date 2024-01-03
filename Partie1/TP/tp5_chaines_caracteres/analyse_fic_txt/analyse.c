#include <stdio.h>
#include <stdlib.h>

void usage(char *nom)
{
    fprintf(stderr, "Usage %s : <chemin_fichier.txt>\n", nom);
}

int est_separateur(char c)
{
    switch (c)
    {
    case '\n':
        return 1;
    case ' ':
        return 1;
    case '.':
        return 1;
    case ':':
        return 1;
    case ';':
        return 1;
    case ',':
        return 1;
    case '?':
        return 1;
    case '!':
        return 1;
    case '(':
        return 1;
    case ')':
        return 1;
    case '\"':
        return 1;
    case '\'':
        return 1;
    default:
        return 0;
    }
    return (0);
}

int main(int argc, char **argv)
{
    FILE *fic = NULL;
    char c;
    int n_c = 0, n_m = 0, n_p = 0, alpha[26];
    for (int i = 0; i < 26; i++)
    {
        alpha[i] = 0;
    }

    if (argc < 2)
    {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    fic = fopen(argv[1], "r");
    if (fic == NULL)
    {
        fprintf(stderr, "Erreur ouverture fichier %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fic)) != EOF)
    {
        n_c++;
        if (est_separateur(c))
        {
            n_m++;
            if (c == '\n')
            {
                n_p++;
                n_c++;
            }
        }
        else if (c >= 'a' && c <= 'z')
        {
            alpha[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            alpha[c - 'A']++;
        }
    }

    printf("Nombre de caractères : %d\n", n_c);
    printf("Nombre de mots : %d\n", n_m);
    printf("Nombre de paragraphes : %d\n", n_p);
    for (int i = 0; i < 26; i++)
    {
        printf("%c : %d\n", 'a' + i, alpha[i]);
    }

    fclose(fic);
    exit(EXIT_SUCCESS);
}