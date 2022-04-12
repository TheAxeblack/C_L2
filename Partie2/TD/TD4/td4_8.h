/**
 *fichier d'en tete du TD4_8
 *
 *hist A. Habrard
 * creation le 16/03/2015
 *      maj le 27/02/2017
 */

#ifndef _TD4_8_H_
#define _TD4_8_H_

liste recherche_element(liste l, element elem);

liste concatene_listes(liste l1, liste l2);

liste insere_liste_ordonnee(liste l, element e);

liste trie_liste_solution1(liste l);

liste trie_liste_solution2(liste l);

liste trie_liste_solution2bis(liste l);

void recopie_liste_recu(liste l, liste *resultat);

liste recopie_liste_recu2(liste l);

void recopie_liste_iter(liste l, liste *resultat);

liste inverse_liste(liste l);


#endif
