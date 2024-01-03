# Chaînes de caractères

Ordre des exercices :

1. [Je crée mes propres fonctions sur les chaînes de caractères](mes_fonctions/)
2. [Analyse fichier texte](analyse_fic_txt/)
3. [Le jeu du pendu](jeu_pendu/)
4. [Chiffres en caractères](chiffres_en_caracteres/)


## L'instruction `switch`

Afin d'éviter les imbrications d'instruction `if`, il existe une instruction pour traiter plusieurs cas "en même temps" : le `switch ... case`. La syntaxe est la suivante :

```c
switch (expression) {
    case valeur1:
        // instructions
        break;
    case valeur2:
        // instructions
        break;
    case valeur3:
        // instructions
        break;
    default:
        // instruction par défaut si aucune des valeurs précédentes n'est vérifiée
        break;
}
```

Ce qui est équivalent à :

```c
if (expression == valeur1) {
    // instructions
} else{
    if (expression == valeur2) {
        // instructions
    } else {
        if (expression == valeur3) {
            // instructions
        } else {
            // instruction par défaut si aucune des valeurs précédentes n'est vérifiée
        }
    }
}
```

**ATTENTION** : Une fois l'exécution des instructions commencées à partir d'un `case`, les autres instructions sont exécutées séquentiellement y compris celles des autres `case` jusqu'à rencontrer un `break`. Il est donc important de mettre un `break` à la fin de chaque `case` pour éviter ce comportement.
