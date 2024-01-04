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
- [tp5_chaines-caracteres](Partie1/TP/tp5_chaines_caracteres/)
- [tp6_Structures-de-donnees-simples](Partie1/TP/tp6_Structures_donnees_simples/)
- [tp7_Programmation-modulaire-et-tris](Partie1/TP/tp7_Modules-et-tris/)
- [tp8_Decouverte-MLV (blibliothèque graphique)](Partie1/TP/tp8_Decouverte-MLV/)

### Partie 2 - Manipulation des pointeurs et TAD (Types Abstraits de Données)

Pour plus de détails sur le langage C, il existe un excellent cours très complet (un peu long cependant) proposé par madame [Anne Canteaut](http://www-rocq.inria.fr/codes/Anne.Canteaut/COURS_C), libre à vous de le consulter (ou pas).

**Remarque** : Rien n'est obligatoire, mais il est fortement conseillé de lire le cours ci-dessus pour mieux comprendre les spécificités du langage C (et ce même si vous avez déjà fait du C auparavant).

#### TD (Travaux Dirigés)

- [TD1](Partie2/TD/TD1/)

#### TP (Travaux Pratiques)

- [tp1](Partie2/TP/tp1/)
- [tp2](Partie2/TP/tp2/)
- [tp3](Partie2/TP/tp3/)
- [tp4](Partie2/TP/tp4/)
