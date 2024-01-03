# Chaînes de caractères

## 1. Je crée mes propres fonctions sur les chaînes de caractères

Le but de cet exercice est de mettre en évidence qu'un chaîne de caractère est un tableau de caractères (avec la gestion du  `\0`, caractère de fin de chaîne). Vous devez écrire des fonctions qui existent déjà dans la bibliothèque `string.h` dans laquelle vous trouverez de nombreuses fonctions de manipulation des chaînes de caractères.

1. Définir une fonction `mystrlen()` qui calcule la longueur d'une chaîne de caractères (comme la fonction `strlen()` de la bibliothèque standard).
2. Définir une fonction ``mystrcmp()`` qui compare deux chaînes de caractères pour l'ordre lexicographique. Cette fonction doit renvoyer $-1$, $0$ ou $1$ comme le fait la fonction `strcmp()` de la bibliothèque standard.
3. Définir une fonction `concat()` qui concatène deux chaînes de caractères dans une troisième.

   Le morceau de code

    ```c
    char c1[ ] = "bonjour à";
    char c2[ ] = " tous";
    char c3[TAILLE_MAX];
    concat(c1, c2, c3);
    printf("c3 = \"%s\"\n", c3);
    ```

    doit afficher : `c3 = "bonjour à tous"`.
4. Définir une fonction `delspace()` qui supprime les espaces et tabulations d'une chaîne de caractères. Cette fonction ne doit pas utiliser de tableau intermédiaire.

   Le morceau de code

    ```c
    char s[] = "bonjour à tous";
    delspace(s);
    printf("s = \"%s\"\n", c1);
    ```

    doit afficher : `s = "bonjouràtous"`.
5. Définir une fonction `strsubs()` qui substitue une chaîne de caractères dans une autre chaîne. La fonction retourne le nombre de caractères qu'elle a substitués. Cette fonction prend les quatres paramètres suivants : une chaîne `str` à l'intérieur de laquelle s'effectue la substitution. Une chaîne `motif` qui remplace une partie de la chaîne `str`. Une position `pos` dans la chaîne `str` à partir de laquelle on commence à remplacer les caractère de `str` par ceux de `motif`. Un nombre `len` qui donne le nombre maximal de caractères à substituer. La fonction en substitue moins si les fins des chaînes `str` ou `motif` sont atteintes avant.

   Le morceau de code

   ```c
   char s[] = "bonjour à tous";
   strsubs(s, "soir", 3, 4);
    printf("s = \"%s\"\n", s);
   ```

    doit afficher : `s = "bonsoir à tous"`.

6. Définir une fonction `min2maj()` qui transforme toutes les lettres minuscules d'une chaîne de caractères en majuscule.
7. Définir la fonction symétrique `maj2min()` qui transforme toutes les lettres majuscules en minuscule.
   Le morceau de code

   ```c
    char s1[] = "Bonjour à Tous !";
    char s2[] = "Au revoir à Tous !";
    min2maj(s1);
    printf("s1 = \"%s\"\n", s1);
    maj2min(s2);
    printf("s2 = \"%s\"\n", s2);
    ```

    doit afficher : `s1 = "BONJOUR À TOUS !"`, `s2 = "au revoir à tous !"`.

    **PENSEZ À METTRE EN PLACE UNE FONCTION MAIN POUR VOUS PERMETTRE DE TESTER VOS FONCTIONS ET DE COMPARER LEUR RÉSULTAT AVEC CELUI DES FONCTIONS DE LA BIBLIOTHÈQUE STANDARD.**



