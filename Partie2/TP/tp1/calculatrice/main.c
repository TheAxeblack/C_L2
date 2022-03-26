/* Contenu : Fonction principale lançant les appels aux différentes fonctions
 * Date de creation : 16 February 2022
 * Author : Mathis Lecuyer
*/

/* Réponses aux questions posées :
 * On souhaite également ajouter de nouveaux opérateurs comme modulo et pgcd. Que faut-il faire ?
 * Réponse : il faut convertir les réels en entiers afin de pouvoir calculer avec ces opérateurs.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculatrice.h"

#define TAILLE_MAX 1024


/* Version en ligne de commande */
int main(int argc, char **argv) {
    double x, y;
    int a, b;
    char fun[TAILLE_MAX];


    if (argc < 3) {
        ft_usage(argv[0], argv, argc);
        exit(EXIT_FAILURE);
    } else if (argc == 3) {
        x = atof(argv[2]);
        strcpy(fun, argv[1]);
        if (strcmp(fun, "cos") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_cosinus(x));
        else if (strcmp(fun, "sin") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_sinus(x));
        else if (strcmp(fun, "tan") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_tangente(x));
        else if (strcmp(fun, "exp") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_exponentielle(x));
        else if (strcmp(fun, "ln") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_ln(x));
        else if (strcmp(fun, "log") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_log(x));
        else if (strcmp(fun, "sqrt") == 0)
            fprintf(stdout, "%s(%f) = %f\n", fun, x, ft_sqrt(x));
        else if (strcmp(fun, "factorielle") == 0)
            fprintf(stdout, "%f! = %d\n", x, ft_factorielle(x));
        else if (strcmp(fun, "fibonacci") == 0)
            fprintf(stdout, "F%f = %d\n", x, ft_fibonacci(x));
        else {
            ft_usage(argv[0], argv, argc);
            exit(EXIT_FAILURE);
        }

    } else {
        x = atof(argv[1]);
        y = atof(argv[3]);
        strcpy(fun, argv[2]);
        switch (fun[0]) {
            case '+':
                fprintf(stdout, "%f + %f  = %f\n", x, y, ft_addition(x, y));
                break;
            case '-':
                fprintf(stdout, "%f - %f  = %f\n", x, y, ft_soustraction(x, y));
                break;
            case '*':
                fprintf(stdout, "%f * %f  = %f\n", x, y, ft_multiplication(x, y));
                break;
            case '/':
                if (y == 0.) {
                    fprintf(stderr, "ERREUR\nDivision par 0");
                    exit(EXIT_FAILURE);
                }
                fprintf(stdout, "%f / %f  = %f\n", x, y, ft_division(x, y));
                break;
            case '^':
                fprintf(stdout, "%f ^ %f  = %f\n", x, y, ft_puissance(x, y));
                break;
            case 'm':
                a = (int) x;
                b = (int) y;
                fprintf(stdout, "%d modulo %d  = %d\n", a, b, ft_modulo(a, b));
                break;
            case 'p':
                a = (int) x;
                b = (int) y;
                fprintf(stdout, "PGCD(%d, %d)  = %d\n", a, b, ft_pgcd(a, b));
                break;
            default:
                ft_usage(argv[0], argv, argc);
                exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}