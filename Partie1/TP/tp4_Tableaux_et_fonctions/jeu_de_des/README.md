# Jeu de dés

On va simuler la distribution de probabilité de la somme obtenue e, lançant des dés à $6$ faces. Pour cela, vous devez écrire un programme qui prend en paramètre deux entiers : le premier strictement positif est le nombre de dés, le second strictement positif est le nombre de lancers. Le programme doit afficher la distribution obtenue comme suit : sur chaque ligne, le nombre d'étoiles correspond au nombre de fois où la somme indiquée à gauche a été obtenue. Par exemple, pour 50 lancer de 2 dés :
```
>./jeu 2 50
2 **
3 ****
4 ***
5 *****
6 **********
7 **********
8 *******
9 ***
10 **
11 ***
12 *
```

**Indications :** Définir deux fonctions
+ `void lancer(int nb_des, int nb_lancers, int tab_occ[])` qui simule `nb_lancer` lancers de `nb_des` dés, stocke les occurences des sommes dans le tableau `tab_occ`.\
L'appel de `lancer()` s'effectue avec des valeurs valides pour `nb_des` et `nb_lancers`.
+  `void afficher(int nb_des, int tab_occ[])` qui effectue l'affichage de la distribution issue du tableau `tab_occ`. Définir une constante pour la taille du tableau `#define NB_MAX 601` (NB : la valeur $601$ permet de jjouer avec au maximum $100$ dés, demandez-vous pourquoi ?)