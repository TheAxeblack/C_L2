# Le jeu de chomp

L'objectif de cet exercice est d'implanter le jeu de Chomp, un jue mathématique à 2 joueurs inventé par David Gales. Les
règles sont les suivantes. Deux joueurs se disputent une tablette de chocolat de dimension *n.m* où *n* et *m* sont des
entiers supérieurs à 1. Chaque joueur choisit alternativement un carré de chocolat, le mange et mange aussi tous les carrés
qui se trouvaient en bas à sa droite. La partie s'arrête lorsque l'un des joueurs mange le carré de chocolat en haut à gauche (i.e. en position (0,0)) : ce carré est empoisonné, le joueur qui mange ce carré perd donc la partie. Pour plus de
détails sur le jeu RDV sur la [page Wikipédia du jeu de Chomp](https://fr.wikipedia.org/wiki/Chomp_(jeu)).  
**INDICATION :** n'oubliez pas de tester au fur et à mesure vos fonctions.

## Définitions des types

Dans un fichier `types.h`, définir les types suivants :

* `tablette` : représente une tablette de chocolat de dimension *n.m*, autrement qui modélise le plateau de jeu. Utiliser tableau d'entiers (short) de dimension *n.m*. Une case à 1 signifie que la carré de chocolat n'a pas encore été mangé, une case de 0 indique qu'il a été mangé. Toute variable de type `tablette` connait sa dimension, c-à-d les entiers *n* et *m*.
* `joueur` : modélise les deux joueurs (utiliser un type énumération)
* `configuration` : représente une configuration du jeu de Chomp. Une configuration est déterminée par une tablette de chocolat et le joueur dont c'est le tour.
* `coup` : modélise un coup joué. Un coup est entièrment spécifié par les coordonnées `c` et `y` du carré de chocolat que le joueur souhaite manger.

## Manipulation des objets

Afin de manipuler les objets utiles au jeu, vous devez programmer les fonctions :

* `tablette creer_tablette(int n, int m)` : crée et retourne une variable de type `tablette` de dimension *n.m*. La tablette retournée possède tous ses carrés.
* `void manger(tablette *t, int x, int y)` : modifie la tablette pointée par `t` : on mange le carré à la position `(x,y)`
ainsi que tous ceux en dessous de lui et à sa droite (**RAPPEL** : Lorsque l'on effectue un passage par adresse d'une structure de données, l'accès aux champs s'effectue avec "une flèche" `->` et non un point `.`).
* `int est_legal(configuration *config, coup *cp)` : retourne 1 si le coup `cp` est légal dans la configuration `config`.
Un coup est légal s'il ordonne de manger un carré de chocolat qui existe encore.
* `int est_finie(configuration *config, joueur *gagnant)` : retourne 1 si la partie `config` est terminée, 0 sinon.
Dans le cas où la partie est terminée, la fonction affecte à la variable pointée par `gagnant` le joueur qui gagne la partie. La partie est terminée lorsque le carré de chocolat empoisonné vient d'être mangé. Dans ce cas là, le joueur qui vient de jouer à perdu.
* `void jouer_coup(configuration *config, coup *cp)` : joue le coup `cp` dans la configuration `config`. Il ne faut pas oublier de modifier le champ qui contient le joueur dont c'est le tour de jouer.

## Assemblage du jeu

* Écrire une fonction `void afficher_configuration(configuration *config)` : affiche l'état de la partie en utilisant [la bibliothèque MLV](http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html).
* Écrire une fonction `lire_coup(configuration *config)` : attend un clic de l'utilisateur sur la tablette de chocolat dans la fenêtre graphique, calcule et retourne le coup spécifié par l'utilisateur. Si l'utilisateur ne clique pas sur la tablette, ou clique sur un carré déjà mangé, la fonction ne fait rien et attend de traiter le prochain clic.
* Utiliser les fonction précédentes pour construire le programme `chomp.c` qui permet de jouer au Chomp. Utiliser pour cela l'algorithme suivant :
  1. lire la dimension de la tablette de chocolat sur laquelle le jeu va se dérouler (passée en argument au programme)
  2. initialiser la configuration `config`
  3. tant que la position config ne représente pas une partie terminée :
     * afficher `config` sur la fenêtre graphique
     * lire un coup `c` sur la fenêtre graphique
     * jouer le coup `c` dans la `config`
     * afficher le numéro du joueur gagnant
