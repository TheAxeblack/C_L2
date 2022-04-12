/**
 * Programme implémentant une fonction qui affiche une chaine à l'envers
 * 1 version iterative et 2 versions recursives sont presentees
 * les versions recursives different par l'utilisation ou non de strlen
 *
 * Exemple d'utilisation de la bibliothèque assert
 *
 * historique: 
 *  creation le 28/01/2014 - A. Habrard
 *       MAJ le 30/01/2017 - A. Habrard - version recursive 2
 *       MAJ le 31/01/2017 - A. Habrard - correction version recursive 2
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

/*declaration fonction */
void affiche_inverse_ite(char * chaine);
void affiche_inverse_recu(char * chaine);
void affiche_inverse_recu_aux(char * chaine,int index);
void affiche_inverse_recu2(char * chaine);
void affiche_inverse_recu_aux2(char * chaine,int index);


/*definition fonctions*/

/*----
 * fonction definissant un message d'erreur,et affiche 'format',
 * peut prendre plusieurs args pour l'affichage de format
 */
void mon_erreur (char *format,...)
{
  va_list arg;
  
  va_start(arg,format);

  fprintf(stderr,"Erreur - ");
  
  vfprintf(stderr,format,arg);/*affichage de la chaine format*/

  va_end(arg);

  exit(EXIT_FAILURE);/*on sort de l'application, on utilise exit ici*/
}


/* fonction iterative affichant l'inverse d'une chaine*/
void affiche_inverse_ite(char * chaine)
{
  int i=0;

  /* on cherche le dernier caractère, on pourrait aussi utiliser i=strlen(chaine), dans ce cas ne pas oublier d'inclure <string.h>*/
  while(chaine[i]!='\0')
    {
      i++;
    }
  i--;
  while(i>=0)
    {
      printf("%c",chaine[i]);
      i--;
    }
  printf("\n");
}

/* ---------- Une premiere version utilisant strlen -------*/

/*fonction recursive affichant l'inverse, on utilise une fonction auxiliaire ayant un argument de plus*/
void affiche_inverse_recu(char * chaine)
{
  int l=strlen(chaine);
  if(l>0)
    affiche_inverse_recu_aux(chaine,l-1);
}

/*fonction auxiliaire qui est en fait la fonction récursive */
void affiche_inverse_recu_aux(char * chaine, int index)
{
  if(index>=0)
    {
      printf("%c",chaine[index]);
      affiche_inverse_recu_aux(chaine,index-1);
    }else printf("\n"); /*non obligatoire*/
}


/* ---------- autre version sans besoin de faire appel à strlen -------*/
/*fonction recursive affichant l'inverse, on utilise une fonction auxiliaire ayant un argument de plus*/
void affiche_inverse_recu2(char * chaine)
{
  affiche_inverse_recu_aux2(chaine,0);
  printf("\n"); /*non obligatoire*/
}

/*fonction auxiliaire qui est en fait la fonction récursive */
void affiche_inverse_recu_aux2(char * chaine, int index)
{
  assert(index>=0);   /*verification index positif*/

  if(chaine[index]!='\0')
    {
       affiche_inverse_recu_aux2(chaine,index+1);
       printf("%c",chaine[index]);
    }
}


/* --------------------------- */

/* Fonction main */
int main(int argc,char * argv[])
{
  char * chaine;

  if (argc != 2)
    mon_erreur("Erreur usage: %s chaine\n\tchaine: chaine de caracteres, affiche la chaine a l'envers\n",argv[0]);
  
  chaine=argv[1];

  printf("Chaine de depart: %s\n",chaine);
  
 
  printf("Version iterative\n");
  affiche_inverse_ite(chaine);

  printf("Version recursive AVEC strlen\n");
  affiche_inverse_recu(chaine);
  
   printf("Version recursive SANS strlen\n");
  affiche_inverse_recu2(chaine);

  return EXIT_SUCCESS;
}


