#define N 20
#define M 20

typedef struct
{
    short n;
    short m;
    short terrain[N][M];
} tablette;

typedef enum joueur
{
    J1,
    J2
} joueur;

typedef struct
{
    tablette tab[N][M];
    joueur j;
} configuration;

typedef struct
{
    short c;
    short y;
} coup;
