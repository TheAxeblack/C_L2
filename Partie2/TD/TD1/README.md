# TD1

## Exercice 1

Écrire un programme qui affiche la différence entre la moyenne arithmétique $A = \frac{a + b}{2}$ et la moyenne géométrique $G = \sqrt{a \times b}$ de deux nombres $a$ et $b$ dans les trois cas suivants :

1. les nombre sosnt fixes dans le programme.
2. les nombres sont lus sur la ligne de commande.
3. les nombres sont lus au clavier.

## Exercice 2

Voic un programme dans lequel il manque un bout de code.

```c
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int x = 0;
    int y = 0;

    while (x < 5) {
        ### EMPLACEMENT DU BLOC ###

        printf("%d%d ", x, y);
        x = x + 1;
    }
    printf("\n");

    return EXIT_SUCCESS;
}
```

Essayer de faire correspondre le bloc de code candidat dans la partie gauche
avec le résultat dans la partie droite que vous verriez si le bloc était inséré.

```c
// Bloc 1
y = x - y;
```

```c
// Bloc 2
y = y + x;
```

```c
// Bloc 3
y = y + 2;
if (y > 4) {
    y = y - 1;
}
```

```c
// Bloc 4
x = x + 1;
y = y + x;
```

```c
// Bloc 5
if (y < 5) {
    x = x + 1;
    if (y < 3) {
        x = x - 1;
    }
}
y = y + 2;
```

Résultats possibles :

1. `22 46`
2. `11 34 59`
3. `02 14 26 38`
4. `02 14 36 48`
5. `00 11 21 32 42`
6. `11 21 32 42 53`
7. `00 11 23 36 410`
8. `02 14 25 36 47`

## Exercice 3 - Rendu de monnaie

Écrire un programme qui prend en entrée une somme en euro (sans centimes) et qui affiche le nombre minimal de billets et de pièces nécessaires pour la composer.\
On prendra en compte des billets de 500, 200, 100, 50, 20, 10, 5 euros et des pièces de 2 et 1 euro.\
Exemple :
$$ 1949 = 3 \times 500 + 2 \times 200 + 2 \times 20 + 1 \times 5 + 2 \times 2 $$

## Exercice 5

Écrire un programme qui lit une chaîne de caractères au clavier pouvant contenir au plus 2 caractères représentant les valeurs d'une carte à jouer. Les valeurs possibles des cartes sont $A$, $K$, $Q$, $J$ ou les nombres de 1 à 10. Le porgramme devra afficher la valeur de la carte : 11 pour un as, 10 pour les figures et la valeur de la carte sinon.

Comment faire pour écrire un programme qui permette à l'utilisateur d'effectuer la même opération plusieurs fois pour connaître la valeur d'une ensemble de cartes ?
