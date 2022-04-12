/**
 *fichier d'implementation du module TAD matrice creuse
 *
 *
 *hist A. Habrard
 * creation le 20/03/2019
 */

#include <stdio.h>
#include "matrice_creuse.h"


/*creation de matrice*/
matrice cree_matrice(int nb_lignes, int nb_colonnes) {
    matrice mnew = (matrice) allocation_mem(1, sizeof(struct_mat));
    mnew->nb_lignes = nb_lignes;
    mnew->nb_colonnes = nb_colonnes;
    mnew->liste_valeur = NULL;
    return mnew;
}

/* Ajouter une valeur à une matrice */
void ajoute_valeur(matrice m, int i, int j, value val) {
    element e;
    e.ligne = i;
    e.colonne = j;
    e.valeur = val;
    m->liste_valeur = insere_liste_ordonnee(m->liste_valeur, e);
}


/*  recupere la valeur de la matrice m à la position i,j*/
value recupere_valeur(matrice m, int i, int j) {
    liste courant = m->liste_valeur;
    element e;

    e.ligne = i;
    e.colonne = j;

    while (!est_liste_vide(courant) && est_avant(courant->objet, e)) {
        courant = renvoie_suivant_liste(courant);
    }
    if (est_liste_vide(courant) || courant->objet.ligne != i || courant->objet.colonne != j) {
        return 0;
    }
    return courant->objet.valeur;
}

/*produit scalaire */
matrice produit_par_scalaire(matrice m, value scalaire) {
    matrice new = cree_matrice(m->nb_lignes, m->nb_colonnes);

    liste courant = m->liste_valeur;

    while (!est_liste_vide(courant)) {
        element e;
        e.ligne = courant->objet.ligne;
        e.colonne = courant->objet.colonne;
        e.valeur = courant->objet.valeur * scalaire;
        new->liste_valeur = insere_liste_ordonnee(new->liste_valeur, e);
        courant = renvoie_suivant_liste(courant);
    }

    return new;
}

/* somme de matrice optimisée */
matrice somme_matrices(matrice m1, matrice m2) {
    matrice new = cree_matrice(m1->nb_lignes, m1->nb_colonnes); /* matrice resultat*/

    liste courant1 = m1->liste_valeur; /*liste des valeurs de la matrice 1*/
    liste courant2 = m2->liste_valeur; /*liste des valeurs de la matrice 2*/

    element e; /*element d'aide pour construire de nouvelles valeurs a inserer dans la matrice resultat*/

    /*on parcourt les listes des 2 matrices en parallèle pour trouver les correspondances entre matrice */
    /*on tire partie du fait que les 2 listes sont triees */
    while (!est_liste_vide(courant1) && !est_liste_vide(courant2)) {
        /* les 2 matrices ont une valeur à la même position, on fait la somme et on ajoute a la liste resultat */
        if (courant1->objet.ligne == courant2->objet.ligne && courant1->objet.colonne == courant2->objet.colonne) {
            e.ligne = courant1->objet.ligne;
            e.colonne = courant1->objet.colonne;
            e.valeur = courant1->objet.valeur + courant2->objet.valeur;
            new->liste_valeur = insere_liste_ordonnee(new->liste_valeur, e);

            /* les 2 listes sont mises à jour en même temps */
            courant1 = renvoie_suivant_liste(courant1);
            courant2 = renvoie_suivant_liste(courant2);
        } else if (est_avant(courant1->objet,
                             courant2->objet)) { /*element de courant1 sans correspondance dans courant2, on le rajoute a la liste resultat */
            e.ligne = courant1->objet.ligne;
            e.colonne = courant1->objet.colonne;
            e.valeur = courant1->objet.valeur;

            new->liste_valeur = insere_liste_ordonnee(new->liste_valeur, e);

            courant1 = renvoie_suivant_liste(courant1);
        } else {/*element de courant2 sans correspondance dans courant1, on le rajoute a la liste resultat */
            e.ligne = courant2->objet.ligne;
            e.colonne = courant2->objet.colonne;
            e.valeur = courant2->objet.valeur;

            new->liste_valeur = insere_liste_ordonnee(new->liste_valeur, e);

            courant2 = renvoie_suivant_liste(courant2);
        }

    }

    /* la liste courant2 est vide, on complète avec les éléments restant de courant1 */
    if (!est_liste_vide(courant1)) {
        e.ligne = courant1->objet.ligne;
        e.colonne = courant1->objet.colonne;
        e.valeur = courant1->objet.valeur;

        new->liste_valeur = insere_liste_ordonnee(new->liste_valeur, e);

        courant1 = renvoie_suivant_liste(courant1);
    }

    /* la liste courant1 est vide, on complète avec les éléments restant de courant2 */
    if (!est_liste_vide(courant2)) {
        e.ligne = courant2->objet.ligne;
        e.colonne = courant2->objet.colonne;
        e.valeur = courant2->objet.valeur;

        new->liste_valeur = insere_liste_ordonnee(new->liste_valeur, e);

        courant2 = renvoie_suivant_liste(courant2);
    }


    /* retour de la matrice resultat*/
    return new;
}


/* multiplication de matrices : note algo non optimisé sur les colonnes car la structure de donnée ne s'y prete pas*/
matrice produit_matrices(matrice m1, matrice m2) {
    int i, j, k; /* compteurs */
    int dernier_i = -1; /* variable indiquant si on a deja fait la somme pour une ligne donnee */
    matrice new = cree_matrice(m1->nb_lignes, m2->nb_colonnes); /* matrice resultat*/

    liste courant1 = m1->liste_valeur; /*valeurs matrice 1*/


    /*calcul du produit, on ne le fait que pour des lignes non vides */
    while (courant1) {
        i = courant1->objet.ligne; /* on recupere le numero de la ligne a traitee */
        if (i != dernier_i) /* on verifie qu'elle n'a pas ete traitee precedemment */
        {
            dernier_i = i; /*mise a jour de dernier_i */
            for (j = 0; j < m2->nb_colonnes; j++) /* pour chaque colonne */
            {
                int res = 0;
                /*pour toutes les colonnes de la matrice 1, ligne i et toutes les colonnes de la matrice 2, colonne j, on recupere les valeurs 2 à 2 et on fait le produit, puis on ajoute au resultat */
                for (k = 0; k < m2->nb_lignes; k++)
                    res += recupere_valeur(m1, i, k) * recupere_valeur(m2, k, j);
                /*note : sur la ligne du dessus, l'acces a recupere_valeur(m1,i,k) n'est pas optimise: on parcours la liste du debut a chaque fois , on pourrait faire mieux ici en la parcourant une seule fois. C'est plus difficile d'optimiser pour recupere_valeur(m2,k,j), neanmoins on pourrait partir de la premiere valeur de la colonne correspondante et parcours la liste depuis ce point, plutot que de parcourir depuis le debut de la liste a chaque fois */

                /*on ajoute la valeur a la matrice resultat si la valeur est non nulle */
                if (res != 0)
                    ajoute_valeur(new, i, j, res);
            }
        }
        /*element suivant de la liste 1*/
        courant1 = renvoie_suivant_liste(courant1);
    }
    return new;
}


/* affichage matrice classique */
void affiche_matrice(matrice m) {
    int i, j;

    for (i = 0; i < m->nb_lignes; i++) {
        for (j = 0; j < m->nb_colonnes; j++) {
            /*on pourrait egalement optimiser en evitant de reparcourir la liste depuis le debut a chaque fois */
            int val = recupere_valeur(m, i, j);
            printf("%d ", val);
        }
        printf("\n");
    }

}

/* affichage matrice creuse : affichage de liste*/
void affiche_matrice_creuse(matrice m) {
    affiche_liste(m->liste_valeur);
}
