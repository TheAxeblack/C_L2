# Le jeu du pendu

Ce jeu est initialisé par le choix d'un mot formé de caractères alphabétiques minuscules (au plus 10), enregistré mais gardé secret. Le joueur doit deviner ce mot.

Le joueur dispose d'un tableau qui est initialement vide. Il propose successivement des lettres qui seront placées dans ce tableau si elles correspondent à des lettres du mot secret. À tout moment, s'il pense avoir deviné le mot secret, le joueur peut proposer un mot. S'il a trouvé le mot secret, il a gagné. Le joueur peut perdre de deux façons : soit il a proposé un mot qui n'est pas le bon, soit il a proposé 10 lettres et n'a toujours pas trouvé le mot.

Nous allons organiser le programme de la façopn suivante :

1. Le mot secret est stocké dans un tableau `mot_secret` de $N$ caractères. Le joueur dispose du tableau `tab` de $N$ caractères, initialement rempli de '_'.
2. Le joueur propose une lettre. Si elle est présente dans une ou plusieurs cases de `mot_secret`, elle est placée aux mêmes places dans `tab`.
3. Le joueur choisit de proposer :
    + Soit un mot eniter ; si c'est le mot secret, le joueur a gagné, sinon il a perdu.
    + Soit une lettre (retour au point 2).
4. Les étapes 2 et 3 sont répétées jusqu'à ce que le joueur gagne ou perde.

Voici un exemple d'exécution du programme, le mot secret est `couvrir` :

```text
le mot secret a 7 lettres
contenu du tableau : _ _ _ _ _ _ _
que voulez-vous proposer : 1 un mot 2 une lettre
votre réponse : 2
votre lettre : e
lettre absente !
que voulez-vous proposer : 1 un mot 2 une lettre
votre réponse : 2
votre lettre : r
contenu du tableau : _ _ _ _ r _ r
que voulez-vous proposer : 1 un mot 2 une lettre
votre réponse : 2
votre lettre : o
contenu du tableau : _ o _ _ r _ r
que voulez-vous proposer : 1 un mot 2 une lettre
votre réponse : 1
votre mot : couvrir
BRAVO, vous avez trouvé le mot secret !
```

On vous donne ci-dessous la fonction `int enreg_secr(char mot_secret[ ])`, qui est exécutée au début du programme : cette fonction permet d'enregistrer le mot secret, et renvoie le nombre de lettres de ce mot.

```c
int enreg_secr(char mot_secret[ ]) {
    int lg;
    printf("donner le mot secret : ");
    if (fgets(mot_secret, N, stdin) != NULL) {
        lg = strlen(mot_secret);
        return (lg - 1);
    }
    else return -1;
}
```

**Remarque** : la longueur réelle du texte saisi est `lg - 1` car la fonction `fgets()` enregistre également dans `t` le caractère "retour à la ligne" qui termine le texte saisi au clavier.

1. Définir la fonction `void aff_tab(char t[], int n)` qui affiche sur une même ligne les `n` éléments du tableau `t` séparé par un espace. Cette fonction servira à l'affichage du contenu de `tab`.
2. Définir la fonction `void poser_lettre(char c, char mot_secret[], int lg, char tab[])` qui parcourt les `lg` cases du tableau `mot_secret`, et qui, pour chaque case de `mot_secret` qui contient le caractère `c`, écrit `c` dans la case correspondante de `tab`. Cette fonction affiche ensuite le contenu de `tab`. Si la lettre n'a pas d'occurrence dans `mot_secret`, la fonction affiche la réponse `lettre absente !` à l'écran.
3. Définir la fonction `void essai_mot(char mot_secret[])` qui demande à l'utilisateur de proposer un mot et qui donne la réponse à cette proposition : soit "BRAVO, vous avez trouvé le mot secret !", soit "perdu !". Pour cela utiliser la fonction `fgets()` comme dans la fonction `enreg_secr()`, et la fonction `strcmp()`.
   **Rappel** : Si `x` et `y` sont des chaînes de caractères, l'instruction `g = strcmp(x, y)` donne à `g` la valeur $0$ si `x` et `y` sont identiques, et une valeur non nulle sinon.
4. Définir la fonction `void essai_lettre(char mot_secret[], int lg, char tab[])` qui demande à l'utilisateur de proposer une lettre, puis appelle la fonction `poser_lettre()`.
5. Définir la fonction `main` qui orchestre le tout. Cette fonction :
   + appelle la fonction `enreg_secr()`
   + affiche le nombre de lettres du mot secret, initialise `tab` et affiche le contenu de `tab` ;
   + demande l'utilisateur ce qu'il veut proposer (un mot ou une lettre) ;
   + selon la réponse de l'utilisateur, appelle `essai_mot()` ou `essai_lettre()`, puis reviens au point 3 si la partie n'est pas terminée
   + affiche à l'écran le résultat de la partie avec le message approprié.
6. On dispose maintenant du fichier `fic-mots-secrets.txt`. Chaque ligne du fichier contient un mot composé de 6 à 10 lettres, et on change la procédure de démarrage du jeu : on tire au hasard un entier $k$ entre 1 et le nombre de mots que contient le fichier, et le mot à deviner est celui qui se trouve sur la $k$-ième ligne du fichier.\
   Définir la fonction `int enreg_secr_bis(char mot_secret[])` qui correspond à cette nouvelle procédure de démarrage. Puis modifier la fonction `main`.
7. Enfin, modifier votre code de tel sorte que, lorsque le programme se lance ou lorsque la partie est terminée, un menu s'affiche laissant le choix à l'utilisateur de :
    1. démarrer une partie
    2. rajouter des NOUVEAUX mots (de 6 à 10 lettres) dans le fichier `fic-mots-secrets.txt`
    3. quitter le jeu.