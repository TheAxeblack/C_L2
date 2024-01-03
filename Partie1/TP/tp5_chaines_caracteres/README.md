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

## 2. Analyse d'un fichier de texte

Écrire un programme qui détermine dans un fichier un texte dont le nom (chemin) est passé en argument du programme.

+ le nombre de caractères qu'il contient,
+ le nombre de chacune des lettres de l'alphabet (sans distinction entre majuscules et minuscules),
+ le nombre de mots,
+ le nombre de paragraphes (c'est-à-dire le nombre de retour à la ligne).
+ Les retours à la ligne ne devront pas être comptabilisés comme des caractères.
On admettra que deux mots sont toujours séparés par un ou plusieurs caractères suivants :
+ fin de lignes
+ espace
+ ponctuation : `.:,;?!`
+ parenthèses : `()`
+ guillemets : `"`
+ apostrophe : `'`
**Conseil** : Définir une fonction `est_separateur(char c)` qui teste si le caractère `c` est l'un des séparateurs mentionnés ci-dessus.

## 3. Le jeu du pendu

Ce jeu est initialisé par le choix d'un mot formé de caractères alphabétiques minuscules (au plus 10), enregistré mais gardé secret. Le joueur doit deviner ce mot.

Le joueur dispose d'un tableau qui est initialement vide. Il propose successivement des lettres qui seront placées dans ce tableau si elles correspondent à des lettres du mot secret. À tout moment, s'il pense avoir deviné le mot secret, le joueur peut proposer un mot. S'il a trouvé le mot secret, il a gagné. Le joueur peut perdre de deux façons : soit il a proposé un mot qui n'est pas le bon, soit il a proposé 10 lettres et n'a toujours pas trouvé le mot.

Nous allons organiser le programme de la façopn suivante :
1. Le mot secret est stocké dans un tableau `mot_secret` de $N$ caractères. Le joueur dispose du tableau `tab` de $N$ caractères, initialement rempli de '_'.
2. Le joueur propose une lettre. Si elle est présente dans une ou plusieurs cases de `mot_secret`, elle est placée aux mêmes places dans `tab`.
3. Le joueur choisit de proposer :
    + Soit un mot eniter ; si c'est le mot secret, le joueur a gagné, sinon il a perdu.
    + Soit une lettre (retour au point 2).
4. Les étapes 2 et 3 sont répétées jusqu'à ce que le joueur gagne ou perde.

Voici un exemple d'exécution du programme :

```text

```