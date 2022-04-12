/**
 *Fichier implémentant une correction des fonctions de l'exo VIII du TD4
 *
 * hist:
 *   A. Habrard le 09/03/2015
 *      maj le 09/03/2016
 *      maj le 27/02/2017
 *       
 *
 */


#include <stdio.h>
#include "liste.h"
#include "td4_8.h"

/* fonction qui recherche un element*/
liste recherche_element(liste l, element elem) {
    liste p = l;

    while (!est_liste_vide(p) && p->objet != elem) /* on cherche le pointeur sur maillon qui contient elem */
    {
        p = p->suivant;
    }
    return p; /* on renvoie le pointeur sur le maillon, si on n'a pas trouve on revoie directement NULL par construction */
}

/*fonction qui concatene 2 listes
 *NB: cette fonction pourrait etre ajoutee au TAD
 *car elle permet de faire la concatenation en temps lineaire
 *en se basant sur l'implementation de la liste*/
liste concatene_listes(liste l1, liste l2) {
    liste p = l1;

    if (est_liste_vide(l1)) /* si la premiere liste est vide, la liste concatenee est directement l2 */
        return l2;

    while (p->suivant != NULL) /* on cherche le dernier maillon de l1 */
    {
        p = p->suivant;
    }

    /* on met a jour le chainage vers l2 */
    p->suivant = l2;

    return l1;
}

/*
 * fonction d'insertion ordonnee, on suppose que les elements sont des entiers (!)
 * dans le cas contraire il faudrait definir une fonction de comparaison d'elements
 */
liste insere_liste_ordonnee(liste l, element e) {
    liste p = l;
    liste cell_debut = insere_element_liste(liste_vide(), e); /*creation du maillon a partir d'une liste vide*/

    if (est_liste_vide(l)) /* si la liste est vide*/
    {
        return cell_debut;
    }

    if (l->objet > e) /*si il faut mettre au debut*/
    {
        cell_debut->suivant = l;
        return cell_debut;
    }

    while (!est_liste_vide(p->suivant) && p->suivant->objet < e) /*on cherche où inserer en milieu de liste*/
    {
        p = p->suivant;
    }

    /* on a trouve, on met a jour les chainages */
    cell_debut->suivant = p->suivant;
    p->suivant = cell_debut;

    return l; /* on renvoie l */
}

/* --- */
/* 3 fonctions possibles de tri de liste (pas forcement optimal d'un point de vue algorithmique) */

/*
 *obtient une liste en utilisant la fonction precedente, cad insertion au debut ce qui inverse bien la liste
 *cette solution a l'inconvenient de creer une autre liste, une copie ordonnee
 */
liste trie_liste_solution1(liste l) {
    liste p = l;
    liste resultat = liste_vide();
    while (!est_liste_vide(p)) {
        resultat = insere_liste_ordonnee(resultat, p->objet);
        p = p->suivant;
    }
    return resultat;
}


/*
 *cette solution implemente un tri par insertion, mais on inverse les objets, pas les cellules
 */
liste trie_liste_solution2(liste l) {
    liste p1 = l; /* parcours de l */
    liste p2; /* parcours de l a la suite de p1 */

    while (!est_liste_vide(p1)) {
        p2 = p1->suivant;
        while (!est_liste_vide(p2)) {
            if (est_avant(p2->objet, p1->objet)) /*//si p2 est avant on inverse les 2 objets*/
            {
                element e = p1->objet;
                p1->objet = p2->objet;
                p2->objet = e;
            }
            p2 = p2->suivant;
        }
        p1 = p1->suivant;
    }
    return l; /*//le debut de liste n'a pas change*/
}

/*cette solution implemente un tri par insertion en inversant les cellules (plus complique!)*/
liste trie_liste_solution2bis(liste l) {
    liste p1 = l; /*//sert a parcourir l*/
    liste p2; /*//va servir a parcourir la liste depuis p1*/
    liste precedent_p1 = liste_vide(); /*//sauvegarde du precedent de p1*/
    liste debut = l; /*//indique le debut de la liste resultat a renvoyer*/

    while (!est_liste_vide(p1)) {
        liste precedent_p2 = p1; /*//sauvegarde du precedent de p2*/
        p2 = p1->suivant;       /*//on commence au suivant de p1*/

        while (!est_liste_vide(p2)) {
            if (p2->objet < p1->objet) /*si p2 est plus petit, on va inverser les cellules p2 et p1 */
            {
                liste paux = p1; /*//sert a sauvegarder p1*/
                liste aux_p1suivant = p1->suivant; /*//set a sauvegarder le suivant de p1*/

                if (est_liste_vide(precedent_p1)) /*//si n'a pas de precedent, p2 devient le nouveau debut de liste*/
                    debut = p2;
                else
                    precedent_p1->suivant = p2; /*//sinon on met a jour le chainage avec le precedent de p1*/

                if (precedent_p2 != p1) {        /*//on verifie que le precedent de p2 n'est pas p1*/
                    precedent_p2->suivant = p1;   /*//et on met a jour le chainage du precedent de p2*/
                }

                p1->suivant = p2->suivant;    /*//on met a jour le chainage du p1->suivant*/

                if (aux_p1suivant != p2)      /*//on verifie que le suivant de p1 n'est pas p2*/
                    p2->suivant = aux_p1suivant;   /*//et on met a jour le suivant de p2*/
                else p2->suivant = p1;       /*//sinon le suivant de p2 est directement p1*/

                p1 = p2; /*//p1 devient p2 car on a inverse les 2*/
                p2 = paux; /*//p2 devient p1*/
            }
            precedent_p2 = p2; /*//on met a jour le precedent de p2*/
            p2 = p2->suivant; /*//et on passe au suivant*/
        }

        precedent_p1 = p1;/* //on met a jour le precedent de pA*/
        p1 = p1->suivant; /*//et on passe au suivant*/
    }

    return debut; /*//renvoie du debut de liste*/
}

/*---*/

/*---*/
/* 2 solutions de recopie de liste - comme le resultat doit etre passe en argument il nous faut un pointeur de liste*/

/*version recursive*/
void recopie_liste_recu(liste l, liste *resultat) {
    if (est_liste_vide(l)) /*//si la liste est vide, on a pour resultat une liste vide*/
        *resultat = liste_vide();
    else {
        *resultat = insere_element_liste(liste_vide(),
                                         l->objet); /*//on cree un nouveau maillon avec l'objet courant et on le "met" dans resultat*/
        recopie_liste_recu(l->suivant,
                           &((*resultat)->suivant)); /*//on copie la suite de la liste en mettant le début de la copie à (*resultat)->suivant*/
    }
}

/*version recursive2 avec renvoi de liste*/
liste recopie_liste_recu2(liste l) {
    liste cell_new = liste_vide();

    if (est_liste_vide(l))
        return liste_vide();

    cell_new = insere_element_liste(liste_vide(), l->objet);
    cell_new->suivant = recopie_liste_recu2(l->suivant);

    return cell_new;
}

/*version iterative */
void recopie_liste_iter(liste l, liste *resultat) {
    liste precedent = liste_vide(); /*//pointeur qui precedent sur le precedent maillon traite*/
    liste courant = l;

    *resultat = liste_vide(); /*//on initiliase la liste resultat a NULL*/

    /*//on parcours la liste et pour chaque maillon on cree une copie et on met a jour le chainage*/
    while (!est_liste_vide(courant)) {
        liste new = insere_element_liste(liste_vide(), courant->objet); /*//on cree un nouveau maillon de liste*/

        if (est_liste_vide(*resultat)) /*// si la liste est vide, ce maillon devient le resultat*/
            *resultat = new;
        else
            precedent->suivant = new; /*//sinon on met a jour le chainage du maillon precedent vers new*/

        precedent = new;            /*//le nouveau maillon va devenir le precedent dans le prochain tour de boucle*/
        courant = courant->suivant; /*//on passe au maillon suivant*/
    }
}
/* -- */

/*fonction d'inversion de liste*/
liste inverse_liste(liste l) {
    liste p = l; /* pointeur courant pour parcourir la liste */
    liste precedent = liste_vide(); /* pointeur sur le maillon precedemment traite */
    liste a_venir = liste_vide(); /* pointeur sur le futur maillon a traiter */


    while (!est_liste_vide(p)) {
        a_venir = p->suivant;   /* on sauvegarde le futur maillon a traiter */
        p->suivant = precedent;/* on change le chainage du maillon courant vers le precedent */
        precedent = p;          /* on met a jour le futur precedent au maillon courant */
        p = a_venir;            /* on recupere le futur maillon a traiter pour le prochain tour de boucle */
    }
    return precedent;
}
