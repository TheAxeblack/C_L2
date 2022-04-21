#include "../inc/usage.h"
#include "../inc/postfixe_inversee.h"
#include "../inc/dictionnaire.h"

int main(int argc, char **argv) {

    int acc = 0;
    int *position = &acc; 

    int res = 0;

    arbre a, b, c, d, e, f, g, h, i, j;
    dictionnaire dico;
    a = b = c = d = e = f = g = h = i = j = creer_arbre_vide();

    if (argc != 2)
        ft_usage(argv[0]);


    printf("--------- Test du module arbre_binaire.c ---------\n");

    d = creer_noeud(2 + '0');
    e = creer_noeud(5 + '0');
    g = creer_noeud(3 + '0');
    h = creer_noeud(7 + '0');
    i = creer_noeud(1 + '0');

    f = creer_arbre('*', h, i);
    c = creer_arbre('-', f, g);
    b = creer_arbre('+', d, e);
    a = creer_arbre('*', b, c);

    afficher_arbre_prefixe(a);
    printf("\n");

    
    MLV_create_window( "Arbre graphique", "tp4", 640, 480 );
    afficher_arbre_graphique(a);
    MLV_actualise_window();
    MLV_wait_seconds(2);
    MLV_free_window();
    printf("\n\n--------- Test du module postfixe_inversee.c ---------\n"
           "Expression d'origine : %s\nArbre obtenu : ", argv[1]);
    j = creer_arbre_expression(argv[1], position);
    afficher_arbre_prefixe(j);
    printf("\n");
    res = eval(a);
    printf("Résultat de l'evaluation de l'arbre ");
    afficher_arbre_prefixe(a);
    printf(" = %d\n", res);
    res = 0;
    res = eval(j);
    printf("Résultat de l'evaluation de l'arbre ");
    afficher_arbre_prefixe(j);
    printf(" = %d\n", res);
    printf("\n--------- Test du module dictionnaire.c ---------\n");

    /* Creation arbre dico de l'exemple */
    a = creer_noeud('0'); /* noeud '\0' */

    b = creer_arbre('s', a, NULL);
    b = creer_arbre('n', a, b);

    c = creer_arbre('e', a, NULL);
    c = creer_arbre('0', NULL, c);
    c = creer_arbre('l', c, NULL);

    b = creer_arbre('i', b, c);

    d = creer_arbre('n', a, NULL);
    d = creer_arbre('o', d, NULL);

    b = creer_arbre('a', b, d);

    e = creer_arbre('t', a, NULL);
    e = creer_arbre('s', a, e);
    e = creer_arbre('o', a, e);
    e = creer_arbre('0', NULL, e);
    e = creer_arbre('n', e, NULL);
    e = creer_arbre('o', e, NULL);
    e = creer_arbre('s', e, NULL);
    b = creer_arbre('m', b, e);
    b = creer_arbre('_', b, NULL);
    dico = b;
    printf("%d\n", existe(dico, "main"));
    printf("%d\n", existe(dico, "sona"));
    printf("%d\n", existe(dico, "mal"));
    printf("%d\n", existe(dico, "sont"));
    printf("%d\n", existe(dico, "sort"));
    printf("%d\n", existe(dico, "mate"));
    exit(EXIT_SUCCESS);
}