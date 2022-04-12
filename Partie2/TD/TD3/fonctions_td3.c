/**
 *Fichier implémentant une correction des fonctions du TD3
 *Les corrections correspondantes:
 * -question IX correspond a concat
 * -question X correspond a sous_chaine
 * -question XI correspond a somme (ainsi que somme_constante)
 * -question XII correspond a itoa
 *
 *POINT IMPORTANT
 * ce TD montre l'utilisation de l'allocation dynamique
 * il montre notamment la differente dans l'utilisation de
 * tableaux a plusieurs dimensions (2 ici, cad des matrices)
 * suivant si les tableaux sont de dimension constante
 * comme lorsqu'ils sont déclarés en : int tab[5][5];,
 * ou comme pointeur de pointeur : int **tab=NULL; qui
 * sera utilisé avec une allocation dynamique plus tard
 * en particulier la notation tab[i][j] sera interprétée
 * de manière différente :
 * allocation de toute les dimension de manière contigue dans le
 * premier cas
 * allocation par l'intermédiaire d'un tableau de pointeur (donc pas
 * forcement contigue) dans le 2nd cas avec pointeur de pointeur.
 * la correction de la question VII avec somme montre l'exemple
 * avec pointeur de pointeur,
 * il est propose avec somme_constante une correction pour des tableaux
 * de dimension constante,
 * la même chose est montree avec des fonctions d'affichage de matrice
 * soit en utilisant un pointeur de pointeur (affiche_matrice_pointeur),
 * soit un tableau a 2 dimensions constantes (affiche_matrice_constante).
 * C'est un point a bien comprendre (revoyez vos notes de cours si besoin)
 *
 * cette correction montre egalement comment liberer de la memoire
 * avec la fonction proposee
 *
 * hist:
 *   A. Habrard le 10/02/2014
 *        modif le 01/02/2014
 *        modif le 08/02/2016
 *        maj   le 06/02/2017
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "allocation.h"
#include "fonctions_td3.h" /*declaration des constantes et fonctions du fichier*/




/* ---- Implementation des fonctions ----- */

/*fonction qui cree et renvoie un tableau contenant les entiers de 
 *deux tableaux d'entiers passes en parametre:
 *tab1 de taille n1, tab2 de taille n2
 */
int * concat(int * tab1, int * tab2, int n1, int n2)
{
  int * resultat=NULL; 
  int i;

  resultat=(int *)allocation_mem(n1+n2,sizeof(int));

  for(i=0;i<n1;i++)
    resultat[i]=tab1[i];  /* *(resultat+i)=*(tab1+i); */

  for(i=0;i<n2;i++)
    resultat[n1+i]=tab2[i];

  return resultat;
}

/*fonction qui cree et renvoie la sous-chaine de la chaine  
 * de caracteres contenue dans chauine omprise entre les deux 
 *index1 et index2 inclus
 */
char * sous_chaine(char * chaine, int index1, int index2)
{
  char * resultat=NULL;
  int i;
  
  assert(index1<=index2); /*verification index*/

  /*dans le nombre d'objets il faut rajouter +1 pour a voir la bonne
    taille et un autre +1 pour le '\0' */
  resultat=(char *)allocation_mem(index2-index1+2,sizeof(char));

  for(i=index1;i<=index2;i++){
    resultat[i-index1]=chaine[i];
  }

  resultat[i-index1]='\0'; /*a ne pas oublier*/

  return resultat;
}

/*fonction qui prend en argument deux matrices carrées de même taille, 
 *leur taille n et qui renvoie une matrice de même taille contenant la 
 *somme des 2 matrices mat1 et mat2 données en argument
 *ces matrices doivent être définies par des pointeurs de pointeurs
 */
int **somme(int ** mat1,int ** mat2, int dimension_mat)
{
  int ** matrice_resultat=NULL;
  int i,j;
  
  matrice_resultat=(int **)allocation_mem(dimension_mat,sizeof(int *));

  for(i=0;i<dimension_mat;i++){
      matrice_resultat[i]=(int *)allocation_mem(dimension_mat,sizeof(int));
      
  }
    
  for(i=0;i<dimension_mat;i++)
    for(j=0;j<dimension_mat;j++)
      matrice_resultat[i][j]=mat1[i][j]+mat2[i][j];
  /* matrice_resultat[i][j] correspond  a *(*(matrice_resultat +i) +j) */

  return matrice_resultat;
}


/*fonction qui prend en argument deux matrices carrées de même taille, 
 *leur taille n et qui renvoie une matrice de même taille contenant la 
 *somme des 2 matrices mat1 et mat2 données en argument
 *ces matrices sont de dimensions constantes
 */
int **somme_constante(int mat1[][TAILLE_MATRICE],int mat2[][TAILLE_MATRICE], int dimension_mat)
{
  int ** matrice_resultat=NULL;
  int i,j;
  
  matrice_resultat=(int **)allocation_mem(dimension_mat,sizeof(int *));
  for(i=0;i<dimension_mat;i++)
      matrice_resultat[i]=(int *)allocation_mem(dimension_mat,sizeof(int));
    
  for(i=0;i<dimension_mat;i++)
    for(j=0;j<dimension_mat;j++)
      matrice_resultat[i][j]=mat1[i][j]+mat2[i][j];

  return matrice_resultat;
}

/* fonction itoa, la solution est rangée dans chaine_nombre 
 * n est le nombre à inverser, et chaine_nombre représente la chaine
 * ou on stocke le resultat */
char * itoa(int n)
{
  char * chaine_nombre = NULL;
  int signe;
  int valeur = n;
  int taille=0;

  signe=n; /*on conserve le signe en stockant le nombre*/
  
  if (signe < 0){  
    valeur = -n; /*on travaille avec n positif*/
    taille++; /*il faut une case de plus pour le '-'*/
  }else 
    valeur = n;
  
  /*on cherche la taille de la representation*/
  /*on reserve au moins une case pour chaque chiffre du nombre*/
  /*a noter que l'on peut se passer de cette boucle en utilisant le log à base 10 +1*/
  /*attention toutefois au cas particulier du 0*/
  while(valeur!=0)
    {
      taille++; 
      valeur/=10;
    }

  /*on traite le cas particulier lorsque n=0, non couvert par la boucle ci-dessus*/
  /*on aurait pu faire un do-while au dessus pour éviter ce test */
  if(n==0)
    {
      taille=1;
    }

  /*allocation*/
  chaine_nombre=(char *)allocation_mem(taille+1,sizeof(char));

  /* on re-recupere la valeur*/
  if (signe < 0){  
    valeur = -n; /*on travaille avec n positif*/
  }else 
    valeur = n;
  
 
  /*on met le signe si besoin*/
  if(signe<0)
    {
      chaine_nombre[0]='-';
    }
  /*ensuite on va travaille a l'envers*/
    /*on termine la chaine*/
  chaine_nombre[taille] = '\0';
  /*ici on utilise la variable taille pour gerer les indices*/
  while(valeur>0)
    {
      chaine_nombre[taille-1] = valeur % 10 + '0'; 
       valeur/=10;
       taille--; 
    }

  /* on traite le cas particulier n=0, non couvert ci-dessus */
  if(n==0)
    {
      chaine_nombre[0]='0';
    }
  
  return chaine_nombre;
}

/*fonctions auxiliaires*/

/*affichage d'un tableau d'entier */
void affiche_tableau(int * tab, int taille)
{
  int i;
  for(i=0;i<taille;i++)
    printf("%d ",tab[i]);
  printf("\n");
}


/*affichage d'un tableau d'entier constant de taille TAILLE_MATRICE*/
void affiche_matrice_constante(int  mat[][TAILLE_MATRICE], int taille)
{
  int i,j;

  for(i=0;i<taille;i++)
    {
      for(j=0;j<taille;j++)
	printf("%d ",mat[i][j]);
      printf("\n");
    }
  printf("\n");
}

/*affichage d'un tableau d'entier defini par des pointeurs */
void affiche_matrice_pointeur(int ** mat, int taille)
{
  int i,j;

  for(i=0;i<taille;i++)
    {
      for(j=0;j<taille;j++)
	printf("%d ",mat[i][j]);
      printf("\n");
    }
  printf("\n");
}


/* ---- */


