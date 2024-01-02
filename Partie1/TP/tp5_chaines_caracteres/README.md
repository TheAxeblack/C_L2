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
5. Définir une fonction `strsubs()` qui substitue une chaîne de caractères dans une autre chaîne. La fonction retourne le nombre de caractères qu'elle a substitués. Cette fonction prend les quatres paramètres suivants : une chaîne `str` à l'intérieur de laquelle s'effectue la substitution. Une chaîne `motif` qui remplace une partie de la chaîne `str`. Une position `pos` dans la chaîne
