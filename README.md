# C_L2

Ce repository conserve les activités réalisées lors de ma deuxième année de licence dans l'UE **Programmation impérative**.

## Objectif

Ce projet vise à consolider les compétences en langage C acquises au cours de cette année. Vous trouverez dans ce repository différents TP regroupés par thématique.

## Compilation

Pour compiler les différents codes présents dans ce dossier, vous pouvez utiliser la commande suivante :

```bash
gcc -W -Wall -std=c89 -pedantic -O3 <nom_fichier.c> -o <nom_executable>
```

Certains codes utilisent la bibliothèque **math.h**, incluse de cette manière :

```c
#include <math.h>
```

Pour les compiler, utilisez :

```bash
gcc -W -Wall -std=c89 -pedantic -O3 <nom_fichier.c> -o <nom_executable> -lm
```

## Structure du Projet

### Partie 1 - Découverte du langage C

#### TP (Travaux Pratiques)

- [tp1_Premiers_programmes](Partie1/TP/tp1_Premiers_programmes)
- [tp2_Boucles](Partie1/TP/tp2_Boucles)
- [tp3_Nbre_mystere](Partie1/TP/tp3_Nbre_mystere)
- [tp4_Tableaux_et_fonctions](Partie1/TP/tp4_Tableaux_et_fonctions)
- [tp5](Partie1/TP/tp5)
- [tp6](Partie1/TP/tp6)
- [tp7](Partie1/TP/tp7)
- [tp8](Partie1/TP/tp8)

### Partie 2 - Manipulation des pointeurs et TAD (Types Abstraits de Données)

#### TD (Travaux Dirigés)

#### TP (Travaux Pratiques)
