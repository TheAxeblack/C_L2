# D'autres matrices

Une matrice $n \times m$ est un tableau à $n$ lignes et $m$ colonnes, ici contenant des entiers (prévoir une taille maximale).\
1. Définir une fonction `affichage_matrice(int matrice[][], int n, int m)`
2. Définir une fonction `remplir_matrice(int matrice[][], int n, int m)` qui permet de remplir une matrice avec des entiers aléatoires de l'intervalle $[-100,100]$
3. Définir une fonction permettant de faire les opérations suivantes sur les matrices (rappeler la définition mathématiques des opérations demandées)\
    1. Addition de deux matrices :\
    `addition(int A[][], int B[][], int C[][], int n, int m)`.\
    La fonction calcule le résultat de l'opération et le stocke dans la matrice $A$
    2. Multiplication de deux matrices :\
    `multiplication(int A[][], int B[][], int C[][], int n, int m)`.\
    La fonction calcul le résultat de l'opération et le stocke dans la matrice $A$
    3. Transposition de matrice :\
    `transpose(int A_tr[][], int A[][], int n, int m)`.
    La fonction calcul le résultat de l'opération et le stocke dans `A_tr`
4. Définir la fonction `main()` vous permettant de tester ces différentes fonctions.