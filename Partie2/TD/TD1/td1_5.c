/**
 * Programme calculant les valeurs d'une carte � joueur
 * 
 * fonction erreur laiss�e "au cas o�", on voit ici l'interet de la
 * compilation separee
 *
 * historique: 
 *  creation le 22/01/2017 - A. Habrard
 *  MAJ      le 22/01/2018 - A. Habrard - comparaison chaines
 *  MAJ      le 20/01/2020 - A. Habrard - ajout d'une methode basee uniquement sur des caracteres+gestion boucle
 *  MAJ      le 10/02/2021 - A. Habrard - correction de la d�tection d'erreur dans la 2eme fonction (card_name[1]!='\0')
 *  MAJ      le 28/01/2022 - A. Habrard - ajout de verification de saisie de scanf et de la fonction vider_buffer()
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


/*declaration des fonctions*/
void mon_erreur(char *format, ...);

int calculer_valeur_carte(char card_name[]);

int calculer_carte_avec_caracteres_uniquement(char *card_name);

void vider_buffer();


/*definitions fonctions*/

/*----
 * fonction definissant un message d'erreur,et affiche 'format',
 * peut prendre plusieurs args pour l'affichage de format
 */

void mon_erreur(char *format, ...) {
    va_list arg;

    va_start(arg, format);

    fprintf(stderr, "Erreur - ");

    vfprintf(stderr, format, arg);/*affichage de la chaine format*/

    va_end(arg);

    exit(EXIT_FAILURE);/*on sort de l'application, on utilise exit ici*/
}


/* ---- 
 * Fonction de calcul de valeur de carte
 * Note: on pourrait utiliser un switch
 */
int calculer_valeur_carte(char card_name[]) {
    int val = -1;

    if (strcmp(card_name, "K") == 0) {
        val = 10;
    } else if (strcmp(card_name, "Q") == 0) {
        val = 10;
    } else if (strcmp(card_name, "J") == 0) {
        val = 10;
    } else if (strcmp(card_name, "A") == 0) {
        val = 11;
    } else {
        val = atoi(card_name);

        if (val < 1 || val > 10)
            mon_erreur("La valeur de la carte est incorrecte: %s -> %d\n", card_name, val);
    }

    return val;
}

/* ---- 
 * Fonction de calcul de valeur de carte
 * utilisant uniquement des caract�res
 */
int calculer_carte_avec_caracteres_uniquement(char *card_name) {
    int val = -1;
    if (card_name[0] == 'K' || card_name[0] == 'Q' || card_name[0] == 'J' ||
        (card_name[0] == '1' && card_name[1] == '0')) {
        val = 10;
    } else if (card_name[0] == 'A') {
        val = 11;
    } else {
        val = card_name[0] - '0';

        /* test pour savoir si le contenu de card_name est bien conforme aux attentes                  */
        /* en particulier le test card_name[1]!='\0' permet de d�tecter les mauvaises entr�es comme 17 */
        if (val < 1 || val > 10 || card_name[1] != '\0')
            mon_erreur("La valeur de la carte est incorrecte: %c%c -- %d\n", card_name[0], card_name[1], val);
    }

    return val;
}

/*fonction main*/
int main() {
    char card_name[3];
    int valeur = 0;  /*valeur obtenue pour la lecture par chaine */
    int valeur_2emeversion = 0; /*valeur obtenue pour la lecture par caracteres */
    short on_continue = 1; /*variable booleene pour continuer la lecture des cartes */
    int retour_scanf = 0; /*variable de v�rification du retour du scanf */

    do {
        /*r�cup�ration de la carte */
        puts("Entrez le nom de la carte a jouer - tapez 'N' pour terminer :");
        retour_scanf = scanf("%2s", card_name);

        if (retour_scanf == 0) {
            mon_erreur("Probleme de saisie scanf\n");
        }

        if (strcmp(card_name,
                   "N")) /* si c'est != 0, les 2 chaines sont differentes, on peut aussi utiliser card_name[0]!='N' */
        {
            /*calcul de la valeur*/
            valeur = calculer_valeur_carte(card_name);
            /* affichage de la valeur */
            printf("The card value is: %d\nLa chaine rentree est %s \n\n", valeur, card_name);

            /*autre methode */
            valeur_2emeversion = calculer_carte_avec_caracteres_uniquement(card_name);
            /* affichage de la valeur de cette version */
            printf("For the second version with char values only:\nThe card value is: %d\nLa chaine rentree est %s \n\n",
                   valeur_2emeversion, card_name);
        } else on_continue = 0;

        vider_buffer(); /* on vide le buffer pour la prochaine saisie */

    } while (on_continue);

    return EXIT_SUCCESS;
}

/* Note : dans le code ci-dessus, la fonction d'erreur arr�te le programme d�s qu'une entr�e n'est pas correcte    */
/*        si vous voulez n�anmoins v�rifier les affichages des deux fonctions, vous pouvez commenter les fonctions */
/*        d'erreur  mon_erreur et les remplacer par exemple par quelque chose du genre :                           */
/*         fprintf(stderr,"---\nERREUR carte fausse: %d\n----\n",val);                                             */


/* Fonction permettant de vider le buffer */
void vider_buffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}
