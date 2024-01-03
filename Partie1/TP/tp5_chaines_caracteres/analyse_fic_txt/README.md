# Analyse d'un fichier de texte

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
