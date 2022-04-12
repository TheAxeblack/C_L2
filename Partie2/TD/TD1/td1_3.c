/**
 * Programme calculant un rendu de monnaie en fonction de valeurs de 
 * billets/pieces predefinis 
 * 
 * Version utilisant une fonction pour l'erreur, une pour le calcul
 * plus une definition globale du tableau de valeurs de billets/pieces
 *
 * historique: 
 *  creation le 23/01/2014 - A. Habrard
 *  MAJ      le 19/01/2018 - A. Habrard - commentaires
 *  MAJ      le 22/01/2018 - A. Habrard - gestion cas somme=0
 *  MAJ      le 09/02/2021 - A. Habrard - correction typos dans affichage texte
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*definitions constantes*/
#define NB_VALEURS 9
int tab_valeurs[NB_VALEURS]={500,200,100,50,20,10,5,2,1};

/*declaration des fonctions*/
void mon_erreur(char * format, ...);
void calcule_rendu(int somme,int tab[]);


/*definitions fonctions*/

/*----
 * fonction definissant un message d'erreur,et affiche 'format',
 * peut prendre plusieurs args pour l'affichage de format
 * Note cette fonction fait office de fonction usage
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


/* ---- 
 * Fonction de rendu de monnaie
 */
void calcule_rendu(int somme, int tab_val[])
{
  int i;
  int somme_courante = somme;
  int nombre_operande = 0; /*booleen pour savoir s'il faut rajouter un '+' */

  printf("%d =",somme);

  if(somme==0)
    {
      printf(" 0 ");
    }else{

    for(i=0;i<NB_VALEURS;i++)
      {
	int quotient=somme_courante/tab_val[i]; /*quotient*/

	somme_courante=somme_courante % tab_val[i]; /*reste*/
      
	if(quotient!=0)
	  {
	    if(nombre_operande==1)
	      printf("+");
	  
	    printf(" %d * %d ",quotient,tab_val[i]);
	    nombre_operande=1;
	  }
      }
    }
  printf("\n"); /*on saute une ligne pour terminer*/
}

/*fonction main*/
int main(int argc,char *argv[])
{
  int somme_euro=0;

  if(argc!=2)
    mon_erreur("usage : %s somme\n\tsomme valeur entiere positive\n\tle programme calcule un rendu de monnaie\n",argv[0]);

  somme_euro=atoi(argv[1]);

  if(somme_euro<0)
    mon_erreur("Valeur negative\n\tusage : %s somme\n\tsomme valeur entiere positive\n\tle programme calcule un rendu de monnaie\nAttention, la somme etait negative: %d\n",argv[0],somme_euro);

  calcule_rendu(somme_euro,tab_valeurs);

  return EXIT_SUCCESS;
}
