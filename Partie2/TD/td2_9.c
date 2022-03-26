/**
 * Programme implémentant une fonction permettant de savoir si une chaine est un palindrome
 *
 *
 * historique: 
 *  creation le 28/01/2014 - A. Habrard
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/*declaration fonction */
void mon_erreur (char *format,...);
int est_palindrome_ite(char * chaine);
int est_palindrome_recu(char * chaine);
int est_palindrome_recu_aux(char * chaine, int index,int taille);

/*definition fonction*/

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


/* fonction iterative affichant l'inverse*/
int est_palindrome_ite(char * chaine)
{
  int taille=strlen(chaine);
  int i=0;
  int ok=1;
 
  for(i=0;i<taille/2 && ok==1;i++)
    {
      if(chaine[i]!=chaine[taille-1-i])
	ok=0;
    }
  return ok;
}

/*fonction recursive indiquant si une chaine est un palindrome, 
on utilise une fonction auxiliaire avec plus d'arguments*/
int est_palindrome_recu(char * chaine)
{
  return est_palindrome_recu_aux(chaine,0,strlen(chaine)-1);
}

/*fonction recursive indiquant si une chaine est un palindrome*/
int est_palindrome_recu_aux(char * chaine, int index_g,int index_d)
{
  /*les indices se croisent : on a vu tous les caracteres*/
  if( index_g >= index_d )
    return 1;

  /*les 2 caracteres sont differents, on renvoie 0*/
  if(chaine[index_g]!=chaine[index_d])
    return 0;
  
  return est_palindrome_recu_aux(chaine,index_g+1,index_d-1);
}

/* Fonction main */
int main(int argc,char * argv[])
{
  char * chaine;

  if (argc != 2)
    mon_erreur("Erreur usage: %s chaine\n\tchaine: chaine de caracteres, indique si la chaine est une palindrome\n",argv[0]);
  
  chaine=argv[1];

  printf("On cherche si %s est un palindrome\n",chaine);

  printf("Version iterative (1 vrai,0 faux): %d\n",est_palindrome_ite(chaine));
  

  printf("Version recursive (1 vrai,0 faux): %d\n",est_palindrome_recu(chaine));
  
  

  return EXIT_SUCCESS;
}


