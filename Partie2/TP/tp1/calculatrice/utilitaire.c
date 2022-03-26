/* Contenu : Fonction d'usage
 * Date de creation : 16 February 2022
 * Author : Mathis Lecuyer
*/

#include <stdio.h>
#include "calculatrice.h"


/* Fonction indiquant l'usage de la fonction */
void ft_usage(char *nom, char **cmd, int nbr) {
    int i;
    fprintf(stderr, "Usage %s : <reel1> <operateur> <reel2> ou <fonction> <reel>\n"
                    "Les operateurs sont : '+', '-', '*', '/', '^', \"pgcd\" et \"mod\".\n"
                    "Les fonctions standards sont : \"exp\" \"ln\" \"log\" et \"sqrt\".\n"
                    "Les fonctions trigonometriques sont : \"cos\" \"sin\" et \"tan\".\n"
                    "Les fonctions non standards sont : \"factorielle\" et \"fibonacci\"\n"
                    "Ligne initiale : ", nom);
    for (i = 0; i < nbr; i++) {
        fprintf(stderr, "%s ", cmd[i]);
    }
    fprintf(stderr, "\n");
}


/* Fonction permettant de vider le buffer */
void ft_kbuffer(void) {
    int x;

    x = 0;
    while (x != '\n' && x != EOF)
        x = getchar();
}