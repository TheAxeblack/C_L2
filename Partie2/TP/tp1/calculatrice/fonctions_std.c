/* Contenu : Fonctions mathématiques standard
 * Date de creation : 16 February 2022
 * Author : Mathis Lecuyer
 */

#include <math.h>
#include <assert.h>
#include "calculatrice.h"

/* Fonction permettant de tester sur le réel entré en paramètre est STRICTEMENT positif */
float test(float x) {
    assert(x > 0);
    return x;
}

/* Fonction renvoyant la somme de x et y */
double ft_addition(double x, double y) {
    return (x + y);
}

/* Fonction renvoyant la différence entre x et y */
double ft_soustraction(double x, double y) {
    return (x - y);
}

/* Fonction renvoyant le produit entre x et y */
double ft_multiplication(double x, double y) {
    return (x * y);
}

/* Fonction renvoyant le quotient entre x et y */
double ft_division(double x, double y) {
    return (x / y);
}

/* fonction renvoyant un réel à une puissance choisie */
double ft_puissance(double x, double y) {
    return (pow(x, y));
}

/* Fonction renvoyant l'exponentielle du réel entré en paramètre */
double ft_exponentielle(double x) {
    return exp(x);
}

/* Fonction renvoyant le logarithme népérien (ln) du réel entré en paramètre */
double ft_ln(double x) {
    test(x);
    return log(x);
}

/* Fonction renvoyant le logarithme décimal (log) du réel entré en paramètre */
double ft_log(double x) {
    test(x);
    return log10(x);
}

/* Fonction renvoyant la racine carrée du réel entré en paramètre */
double ft_sqrt(double x) {
    return sqrt(x);
}