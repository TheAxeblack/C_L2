# Le nombre mystère

## 1. À vous de trouver le nombre $\ldots$

Le programme à écrire doit vous permettre de trouver, en plusieurs étapes, la valeur d'un nombre qui a été choisi aléatoirement par la machine et que vous ne connaissez pas. L'exécution du programme doit se dérouler de la façon suivante :

1. La machine choisit aléatoirement un nombre entier $N$ entre $0$ et $100$
2. Vous proposez un nombre entier entre $0$ et $100$, et la machine vous dit s'il est inférieur, supérieur ou égal à $N$
3. S'il est inférieur à $N$, l'exécution reprend au point 2.
4. S'il est supérieur à $N$, l'exécution reprend au point 2.
5. S'il est égale à $N$ vous avez gagné et le jeu est fini.

À la fin du jeu, la machine doit vous indiquer en combien d'étapes vous avez trouvé $N$.\
Ensuite, votre programme doit vous demander si vous voulez recommencer (retour au point 1.), ce qui permet de jouer plusieurs fois de suite pendant la même exécution du programme.

Exemple d'exécution du programme

```text
>mystere
La machine a choisi un nombre mystère entre 0 et 100, à vous de le trouver
Votre proposition ?
7
C'est faux, le nombre mystère est supérieur à 7
Votre proposition ?
60
C'est faux, le nombre mystère est inférieur à 60
Votre proposition ?
43
C'est juste vous avez trouvé le nombre mystère (43) en 3 étapes

Voulez-vous recommencer ? (oui:1 / non:0) 0
>
```

## 2. Au tour de la machine

Maintenant, c'est vous qui choisissez un nombre et la machine le cherche
