# L2_prog_imp

Ce dépot à pour but de conserver toutes les activitées réalisées lors de ma deuxieme annee de licence.

## Partie 1

### TD

Vous trouverez dans le dossier les fichiers .txt décrivant ce qu'est censé faire le fichier .c associé.

Pour lancer les compilations des différents codes présent dans ce dossier, on utilisera la commande suivante.

```bash
gcc -W -Wall -std=c89 -pedantic -O3 <nom_ficher.c> -o <nom_exe>
```

**_Attention !_** Certains codes utilisent la bibliothèque **math.h** que l'on inclus de cette facon

```c
#include <math.h>
```

dans ce cas la commande à utilisée est la
suivante :

```bash
gcc -W -Wall -std=c89 -pedantic -O3 <nom_ficher.c> -o <nom_exe> -lm
```

### TP
