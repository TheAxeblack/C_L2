/**
 * Programme calculant la différence entre la moyenne arithmétique et 
 * géométrique de 2 nombres
 *
 * Version utilisant une fonction pour le calcul de la difference
 *
 * Cette version prend les valeurs sur la ligne de commande
 * les versions avec valeurs fixées ou lisant les valeurs au clavier
 * sont indiquées en commentaires en bas du fichier
 *
 * historique: 
 *  creation le 23/01/2014 - A. Habrard
 *  MAJ      le 19/01/2018 - A. Habrard - modif usage
 *           le 24/01/2022 - A. Habrard - modif verification positivité nombres donnés en ligne de commande + usage
                                        - modif verification scanf 
 *
 * Note:
 *il n'est pas utile de prendre la valeur absolue car 
 *(sqrt(a)-sqrt(b))^2=a+b-2sqrt(a*b)>=0 et donc (a+b)/2>=sqrt(a*b) 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Declaration de constantes*/


/*declaration fonction */
void calcule_difference(double a,double b);
void usage(char *s);


/*definition fonction usage */
void usage(char *s)
{
  fprintf(stderr,"Erreur usage: %s a b\n\ta et b 2 reels positifs, calcule la difference entre la moyenne arithmetique et geometrique de a et b\n",s);
}

/*definition fonction calcule_difference*/
void calcule_difference(double a,double b)
{
  double moyenne_a=(a+b)/2.0;
  double moyenne_g=sqrt(a*b);

  double diff = moyenne_a-moyenne_g;

  printf("Moyenne arithmetique: %.4f, moyenne geometrique: %lf,\nla difference entre les 2 moyennes est %lf\n",moyenne_a,moyenne_g,diff);
}


/* Fonction main */
int main(int argc,char * argv[])
{
  double a,b;

  if (argc != 3)
  {
    usage(argv[0]);
    return EXIT_FAILURE;
  }  

  a=atof(argv[1]);
  b=atof(argv[2]);

  if(a>=0 && b>=0)
    calcule_difference(a,b);
  else{
    usage(argv[0]);
    printf("L'un des nombres au moins est negatif, a:%f, b:%f\n",a,b);
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}


/* ---- */
/* Fonction main, avec lecture clavier */
/*
int main(int argc,char * argv[])
{
  double a,b;
  
  printf("Entrez le nombre reel a :\n");
  if(scanf("%lf",&a)!=1){
     fprintf(stderr,"Erreur saisie nombre a\n");
     return EXIT_FAILURE;
  }
  printf("Entrez le nombre reel b :\n");
  if(scanf("%lf",&b)!=1){
     fprintf(stderr,"Erreur saisie nombre a\n");
     return EXIT_FAILURE;
  }

  if(a>=0 && b>=0)
    calcule_difference(a,b);
  else{
    usage(argv[0]);
    printf("L'un des nombres au moins est negatif, a:%f, b:%f\n",a,b);
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
*/


/* ----- */
/* avec nombres fixes : on les met en constantes au début*/
/*#define VALEUR_A 5 */
/*#define VALEUR_B 6  */


/* Fonction main nombres fixes */
/*
int main(int argc,char * argv[])
{
  calcule_difference(VALEUR_A,VALEUR_B);

  return EXIT_SUCCESS;
}
*/

/*---autre version avec const*/
/* Fonction main nombres fixes */
/*
int main(int argc,char * argv[])
{
  const int val_a=5; 
  const int val_b=6;
  calcule_difference(val_a,val_b);

  return EXIT_SUCCESS;
}
*/
/*--- on peut aussi combiner const avec la ligne de commande*/
/*mais il faut initiliser les variables a la declaration:*/
/* Fonction main */
/*
int main(int argc,char * argv[])
{
  if (argc != 3)
  {
    usage(argv[0]);
    return EXIT_FAILURE;
  }else{  

    const double a=atof(argv[1]);
    const double b=atof(argv[2]);

    if(a>=0 && b>=0)
        calcule_difference(a,b);
    else{
        usage(argv[0]);
        printf("L'un des nombres au moins est negatif, a:%f, b:%f\n",a,b);
        exit(EXIT_FAILURE);
    }calcule_difference(a,b);
  }

  return EXIT_SUCCESS;
}
*/

