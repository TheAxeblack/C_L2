/**
 * Programme implémentant une fonction de calcul d'une exponentielle
 *
 * Exemple d'utilisation de la bibliothèque assert
 *
 * historique: 
 *  creation le 28/01/2014 - A. Habrard
 *  MAJ      le 12/02/2021 - A. Habrard - precisions entrees fonction calcule_puissance ds commentaires
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

/*declaration fonction */
double calcule_puissance(double x,int n);
void mon_erreur (char *format,...);

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


/* fonction calculant x^n*/
/* l'entree est un double */
/* l'entree n doit etre un entier positif*/
double calcule_puissance(double x,int n)
{
  assert(n>=0); /*test si n>=0 et quitte sinon */
  if(n==0)
    {
      return 1.0;
    }else if(n%2==0)
    {
      return calcule_puissance(x*x,n/2);
    }else{ 
    return x*calcule_puissance(x,n-1);
  }
}


/* Fonction main */
int main(int argc,char * argv[])
{
  double x;
  int n;
  double res=0.; 

  if (argc != 3)
  {
    mon_erreur("Erreur usage: %s x n\n\tx reel, n entier, calcule x^n\n",argv[0]);
  }  

  x=atof(argv[1]);
  n=atoi(argv[2]);

  /*lignes ci-dessous a decommenter si on veut tester assert */
  /*if(n<0) */ /*test si n>=0 et quitte sinon*/
  /*{
    mon_erreur("Erreur usage: %s x n\n\tx reel, n entier, calcule x^n\nAttention n doit etre positif\n",argv[0]);
    }  */
    
  res=calcule_puissance(x,n);

  printf("%f^%d = %f\n",x,n,res);

  return EXIT_SUCCESS;
}


