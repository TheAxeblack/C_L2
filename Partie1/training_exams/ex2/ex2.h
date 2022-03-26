#define NB_MAX 1024
#define ETU_MAX 50

typedef struct {
    int id;
    char nom[NB_MAX];
    char prenom[NB_MAX];
} etudiant;

typedef struct {
    etudiant tab[ETU_MAX];
    int nb_etudiants;
} promo;