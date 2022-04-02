#ifndef TP_PILE_H
#define TP_PILE_H

typedef liste pile;

pile pile_vide();

int est_pile_vide(pile p);

pile empiler(pile p, element elem);

element sommet_pile(pile p);

pile depiler(pile p);

int taille_pile(pile p);

void afficher_pile(pile p);

#endif
