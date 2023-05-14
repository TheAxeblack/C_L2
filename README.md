# C_L2

Ce repository a pour but de conserver toutes les activités réalisées lors de ma deuxième année de licence dans l'UE **Programmation impérative**.

## Partie 1 - Découverte du langage C

Cette partie contient principalement du code en langage C de niveau débutant, ce qui est normal puisqu'il s'agit d'une introduction à ce langage.

### TD (Travaux Dirigés)

Dans ce dossier, vous trouverez des fichiers README.md décrivant ce que chaque fichier .c associé est censé faire.

Pour compiler les différents codes présents dans ce dossier, vous pouvez utiliser la commande suivante :

```bash
gcc -W -Wall -std=c89 -pedantic -O3 <nom_fichier.c> -o <nom_executable>
```

**_Attention !_** Certains codes utilisent la bibliothèque **math.h**, que l'on inclut de cette manière :

```c
#include <math.h>
```

dans ce cas la commande à utiliser est la suivante :

```bash
gcc -W -Wall -std=c89 -pedantic -O3 <nom_fichier.c> -o <nom_executable> -lm
```

### TP (Travaux Pratiques)

Dans chacun des répertoires d'exercices, vous trouverez un README vous indiquant ce que le fichier .c associé doit faire.

## Partie 2 - Manipulation des pointeurs et TAD (Types Abstraits de Données)

Au programme : des pointeurs, encore des pointeurs et... encore des pointeurs ! Vous êtes prêt à vous plonger dedans !
