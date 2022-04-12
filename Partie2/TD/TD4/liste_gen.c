/**
 *fichier d'implementation du module TAD liste
 *version utilisée pour les matrices creuses
 *
 *Il faut définir les fonctions est_avant et est_egal en fonction des valeurs possible du type element
 *
 *hist A. Habrard
 * creation le 20/03/2019
 *  
 */

#include <stdio.h>
#include "liste_gen.h"

/*retour liste vide*/
liste liste_vide()
{
  return NULL;
}

/*test liste vide*/
int est_liste_vide(liste l)
{
  if(l==liste_vide())
    return 1;
  return 0;
}

/*insertion element au debut de la liste*/
liste insere_element_liste(liste l,element elem)
{
  liste lnew=(liste)allocation_mem(1,sizeof(struct_cellule));
  lnew->objet=elem;
  lnew->suivant=l;
  return lnew;
}

/*renvoie le premier element de la liste, erreur sinon*/
element renvoie_premier_liste(liste l)
{
  if(est_liste_vide(l))
   mon_erreur("Erreur la liste est vide dans la fonction renvoie_premier\n");
  return l->objet;
}

/*renvoie la suite de la liste, liste_vide sinon*/
liste renvoie_suivant_liste(liste l)
{
  if(est_liste_vide(l))
    return l;
  return l->suivant;
}

/*supprimer le premier de la liste*/
liste supprimer_premier_liste(liste l)
{
  liste lsuivant=l->suivant;
  libere_mem((void**)&l);
  return lsuivant;
}


/* fonction qui recherche un element*/
liste recherche_element(liste l, element elem)
{
  liste p=l;

  while(!est_liste_vide(p) && est_egal(p->objet,elem)) //on cherche le pointeur sur maillon qui contient elem
    {
      p=p->suivant;  //p=renvoie_suite(p);
    }
  return p; //on renvoie le pointeur sur le maillon, si on n'a pas trouve on revoie directement NULL par construction
}

/*fonction qui concatene 2 listes
 *NB: cette fonction pourrait etre ajoutee au TAD
 *car elle permet de faire la concatenation en temps lineaire
 *en se basant sur l'implementation de la liste*/
liste concatene_listes(liste l1,liste l2)
{
  liste p=l1;
  
  if(est_liste_vide(l1)) //si la premiere liste est vide, la liste concatenee est directement l2
    return l2;

  while(p->suivant!=NULL) //on cherche le dernier maillon de l1
    {
      p=p->suivant;
    }
  
  //on met a jour le chainage vers l2
  p->suivant=l2;

  return l1;
}

/*
 * fonction d'insertion ordonnee, on suppose que les elements sont des entiers (!)
 * dans le cas contraire il faudrait definir une fonction de comparaison d'elements
 */
liste insere_liste_ordonnee(liste l,element e)
{
  liste p=l;
  liste cell_debut=insere_element_liste(liste_vide(),e); //creation du maillon a partir d'une liste vide

  if(est_liste_vide(l)) //si la liste est vide
    {
      return cell_debut;
    }
  
  if(est_avant(e,l->objet)) //si il faut mettre au debut
    {
      cell_debut->suivant=l;
      return cell_debut;
    }

  while(!est_liste_vide(p->suivant) && est_avant(p->suivant->objet,e)) //on cherche où inserer en milieu de liste
    {
      p=p->suivant;
    }

  //on a trouve, on met a jour les chainages
  cell_debut->suivant=p->suivant;
  p->suivant=cell_debut;
  
  return l; //on renvoie l
}


/*affichage d'une liste*/
void affiche_liste(liste l)
{
  liste p=l;

  while(!est_liste_vide(p))
    {
      printf("%d %d: %d,",p->objet.ligne,p->objet.colonne,p->objet.valeur);
      p=p->suivant;
    }
  printf("\n");

}

/*fonction d'ordre sur les elements*/
int est_avant(element e1,element e2)
{
  if(e1.ligne < e2.ligne)
    return 1;
  else if(e1.ligne > e2.ligne)
    return 0;
  
  else if(e1.colonne < e2.colonne)
    return 1;
  
  return 0;
}

/*fonction d'egalite sur les elements*/
int est_egal(element e1,element e2)
{
  if(e1.ligne == e2.ligne && e1.colonne == e2.colonne && e1.valeur== e2.valeur)
    return 1;
 
  
  return 0;
}


/*fonction de recopie de liste - implementation itérative*/
liste recopie_liste(liste l)
{
  liste cell_new=liste_vide();

  if(est_liste_vide(l))
    return liste_vide();

 cell_new=insere_element_liste(liste_vide(),l->objet);
 cell_new->suivant=recopie_liste(l->suivant);

 return cell_new;
}

/*fonction d'inversion de liste*/
liste inverse_liste(liste l)
{
  liste p=l; //pointeur courant pour parcourir la liste
  liste precedent=liste_vide(); //pointeur sur le maillon precedemment traite
  liste a_venir=liste_vide(); //pointeur sur le futur maillon a traiter


  while(!est_liste_vide(p))
    {
      a_venir=p->suivant;   //on sauvegarde le futur maillon a traiter
      p->suivant=precedent; //on change le chainage du maillon courant vers le precedent
      precedent=p;          //on met a jour le futur precedent au maillon courant
      p=a_venir;            //on recupere le futur maillon a traiter pour le prochain tour de boucle
    }
  return precedent;
}


