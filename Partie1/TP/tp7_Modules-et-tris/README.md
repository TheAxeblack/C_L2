# TP7 - Modules et tris

Le but de cet exercice est de trier les informations contenues dans un fichier puis de rechercher les informations particulières. Le fichier considéré contient les 3 éléments suivants sur chaque lignes, séparés par un espace (à vous de créer plusieurs exemples de fichiers) : `un_numero un_nom un_prenom`. On souhaite effectuer des recherches à partir d'un nom et afficher le prénom et le numéro correspondant.

Pour cela vous devez définir les différents modules. Votre programme final doit pouvoir être compilé via la commande `make` (vous devez donc écrire un `Makefile`).

## 1. Module de lecture/affichage des données

Les données doivent être stockées dans un tableau (de taille maximale 400) de structures de données. Chaque structure contient trois champs : `numero`, `nom` et `prenom`.\
Ce module contient les fonctions permettant :

+ de stocker dans le tableau les données issues du fichier,
+ d'afficher le tableau pour en visualiser son contenu (cela permettra de vérifier que la lecture du fichier s'est fait correctement et que le tri est correct).

## 2. Module de tri

Ce module contient toutes les fonctions liées au tri par ordre alphabétique du tableau.\
Le tri s'effectue par rapport au champ `nom` de la structure. Vous devez programmer au moins l'un des deux algorithmes de tri suivant :

1. le tri à bulle ;
2. le tri par insertion.

Vous pouvez également proposer d'autres méthodes de tri.

## 3. Module de recherche

Ce module contient les fonctions liées à la recherche (à partir d'un nom) dans le tableau. Vous devez programmer les deux recherches suivantes :

+ la recherche séquentielle (le tableau n'a pas besoin d'être trié en amont) : il suffit de parcourir le tableau jusqu'à trouver le nom cherché (s'il n'existe pas, afficher un message particulier).
+ la recherche dichotomique : sur un tableau trié, effectuer la recherche par la méthode de dichotomie (n'oubliez pas de traiter le cas où le nom ne se trouve pas dans le tableau).

## 4. Analyse des algorithmes de recherche

Pour évaluer expérimentalement les performances des deux algorithmes de recherche, rajouter dans le programme des compteurs du nombre de comparaisons effectuées pour chacun des algorihmes. Faites afficher ces informations.

Tester sur différents fichiers et comparer les résultats obtenus pour différentes recherches. Conclure.
