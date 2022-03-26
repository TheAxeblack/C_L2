#ifndef TP_CALCULATRICE_H
#define TP_CALCULATRICE_H

/* Les fonctions de utilitaire.c */
void ft_usage(char *nom, char **cmd, int nbr);

void ft_kbuffer(void);


/* Les fonctions de fonctions_std.c */
double ft_addition(double x, double y);

double ft_soustraction(double x, double y);

double ft_multiplication(double x, double y);

double ft_division(double x, double y);

double ft_puissance(double x, double y);

double ft_exponentielle(double x);

double ft_ln(double x);

double ft_log(double x);

double ft_sqrt(double x);


/* Les fonctions de fonctions_trigo.c */
double ft_cosinus(double x);

double ft_sinus(double x);

double ft_tangente(double x);


/* Les fonctions de fonctions_non_std.c */
int ft_factorielle(double x);

int ft_fibonacci(double n);

int ft_modulo(int a, int b);

int ft_pgcd(int a, int b);

#endif
