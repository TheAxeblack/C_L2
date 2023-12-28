# Manipulation de tableaux avec des fonctions

On désire écrire un programme qui :
+ définit une pseudo-constante $N = 25$
+ remplit un tableau `t1` de $N$ nombres entiers aléatoires pris dans $[-15,15]$
+ affiche le contenu de `t1`
+ calcule et affiche le minimum, le maximum et la moyenne des éléments de `t1`
+ remplit un tableau `t2` avec les éléments de `t1` pris dans l'ordre inverse
+ affiche le contenu de `t2`
+ remplit un tableau `t3` de la façon suivante : pour chaque `i`, `t3[i]` est le reste de la division entière de `t2[i]` par $4$
+ affiche le contenu de `t3`
+ compte et affiche le nombre d'occurences de $0$ dans `t3`
+ remplit un tableau `t_pair` avec les éléments de `t3` qui ont une valeur de paire
+ affiche le contenu de `t_pair`

Pour cela, définir les fonctions suivantes (vous pouvez définir d'autres fonctions) :
+ `void remplir_tab_alea(in t[], int n)` : remplit le tableau `t` de taille $n$ avec des entiers aléatoires de $[-15,15]$
+ `void afficher_tab(int t[], int n)` : affiche sur une ligne les $n$ premiers éléments de `t`
+ `double moyenne(int t[], int n)` : renvoie la moyenne des $n$ premiers éléments de `t`
+ `int main(void)` : orchestre l'ensemble du programme.