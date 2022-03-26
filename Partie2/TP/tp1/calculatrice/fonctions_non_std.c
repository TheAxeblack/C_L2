/* Contenu : Fonctions mathématiques standard
 * Date de creation : 02 March 2022
 * Author : Mathis Lecuyer
 */

#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "calculatrice.h"

/* fonction renvoyant la factorielle d'un entier n */
int ft_factorielle(double n) {
    if (n < 0)
        return 1;
    return n * ft_factorielle(n - 1);
}


/* fonction renvoyant la suite de Fibonacci jusqu'a un entier n */
int ft_fibonacci(double n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return ft_fibonacci(n - 1) + ft_fibonacci(n - 2);
}

/* fonction renvoyant le reste de la division entière entre deux entiers */
int ft_modulo(int a, int b) {
    return (a % b);
}

/* fonction renvoyant le pgcd de deux entier naturels */
int ft_pgcd(int a, int b) {
    assert(a >= 0);
    assert(b >= 0);
    if (a == b)
        return a;
    else if (a > b)
        return ft_pgcd(a - b, b);
    else
        return ft_pgcd(a, b - a);
}