#define NB_MAX 400

typedef struct
{
    int numero;
    char nom[NB_MAX];
    char prenom[NB_MAX];
} personne;

typedef personne tab[NB_MAX];

int stockage(tab t);

void afficher_tab(int i, tab t);

void tri_a_bulles(int nb, tab t);

int recherche_sequentielle(char *nom, int nb, tab t);

int recherche_dichotomique(char *nom, int nb, tab t);