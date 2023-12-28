# Décodons, Décodons

Un programme C (appelons-le `prog`) doit prendre en argument : un entier $\min$, un entier $\max$, un entier $n$, représentant le nombre d'arguments restant sur la ligne, enfin $n$ entiers, qui doivent être compris entre $\min$ (inclus) et $\max$ (inclus). Par exemple l'appel
```
> prog 0 20 3 10 12 6
```
est correct ($n = 3$ entiers suivent sur la ligne de commande, tous les trois compris entre $\min = 0$ et $\max = 20$), alors que les appels
```
> prog 0 20 3 15 2
```
et 
```
> prog 0 20 3 15 2
```
ne le sont pas.

Écrire la partie de la fonction `main` qui teste et qui contrôle les arguments, puis l'intégrer dans un programme simple pour tester son fonctionnement.