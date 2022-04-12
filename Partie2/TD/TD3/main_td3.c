/**
 *Fichier main associé au td3
 *
 *
 * hist:
 *   A. Habrard le 10/02/2014
 *        modif le 04/03/2015
 *        modif le 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "allocation.h"
#include "mon_erreur.h"
#include "fonctions_td3.h" //declaration des constantes et fonctions du fichier


/*  ------- Fonction main -------- */
int main(int argc, char *argv[])
{
  int q6=0,q7=0,q8=0,q9=0; //variables liées aux questions
  int i,j; //compteurs
  int n; //variable utilisée pour itoa
  int tab1[TAILLE_TAB1]={2,4,5,6,1}; //tab pour concat
  int tab2[TAILLE_TAB2]={7,8,9}; //tab pour concat
  int * result_concat=NULL; //resultat pour concat
  char * chaine="Bonjour titi, va va?";
  char * result_sous_chaine=NULL;// pour sous_chaine
  int mat1_constante[TAILLE_MATRICE][TAILLE_MATRICE]={{1,2,3},{4,5,6},{7,8,9}};
  int mat2_constante[TAILLE_MATRICE][TAILLE_MATRICE]={{9,8,7},{6,5,4},{3,2,1}};
  int **mat1=NULL;
  int **mat2=NULL;
  int ** mat_res_op_constante=NULL;
  int ** mat_res=NULL;

  /* analyse de la ligne de commande */
  if(argc==1)
    {
      q6=q7=q8=q9=1;
    }else
    {
      for(i=1;i<argc;i++)
	{
	  char var=argv[i][0];

	  switch(var)
	    {
	    case '1': q6=1;break;
	    case '2': q7=1;break;
	    case '3': q8=1;break;
	    case '4': q9=1;break;
	    default: mon_erreur("Usage: %s [1|2|3|4]\nChaque entier correspond aux questions 9, 10, 11, 12 du TD3 respectivement. Ne pas mettre d'argument implique que toutes les questions sont traitées, sinon le programme n'affiche le résultat que des questions indiquées\n",argv[0]);
	    }
	}
      
    }

  /* ------- test concat -------*/
  if(q6)
    {
      printf("***Test concat \n");
      result_concat=concat(tab1,tab2,TAILLE_TAB1,TAILLE_TAB2);
      printf("affichage tableau 1\n");
      affiche_tableau(tab1,TAILLE_TAB1);
      printf("affichage tableau 2\n");
      affiche_tableau(tab2,TAILLE_TAB2);
      printf("affichage resultat concat : \n");
      affiche_tableau(result_concat,TAILLE_TAB1+TAILLE_TAB2);
      printf("\n\n");
    }

  /* ---------- test sous-chaine ------------ */
  if(q7){
    result_sous_chaine=sous_chaine(chaine,8,11);
    printf("***Test sous chaine : chaine depart \"%s\",\n on choisit les indices 8 et 11, resultat: %s\n",chaine,result_sous_chaine);
    printf("\n\n");
  }
  
  /* ---------- test matrices ------------ */
  if(q8)
    {
      /*maintenant on alloue les 2 matrices de pointeur de pointeur*/
      mat1=(int **)allocation_mem(TAILLE_MATRICE,sizeof(int *));
      mat2=(int **)allocation_mem(TAILLE_MATRICE,sizeof(int *));
      for(i=0;i<TAILLE_MATRICE;i++)
	{
	  mat1[i]=(int *)allocation_mem(TAILLE_MATRICE,sizeof(int));
	  mat2[i]=(int *)allocation_mem(TAILLE_MATRICE,sizeof(int));
	}  
      /*NB notre fonction allocation_mem fait le choix d'arreter le programme*/
      /*si l'allocation ne fonctionnait pas et si on voulait le continuer*/
      /*il faudrait penser a liberer les parties intermediaires allouees*/
      
      
      /*maintenant il faut remplir a la main ou trouver une formule comme ici*/
      for(i=0;i<TAILLE_MATRICE;i++)
	{
	  for(j=0;j<TAILLE_MATRICE;j++)
	    {
	      mat1[i][j]=i*TAILLE_MATRICE+j+1;
	      mat2[i][j]=TAILLE_MATRICE*TAILLE_MATRICE+1-(i*TAILLE_MATRICE+j+1);
	    }
	}
      
      printf("**Test somme matrice definie par pointeur de pointeur\n");
      mat_res=somme(mat1,mat2,TAILLE_MATRICE);
      printf("Affichage matrice pointeur de pointeur 1 :\n");
      affiche_matrice_pointeur(mat1,TAILLE_MATRICE);
      printf("Affichage matrice pointeur de pointeur 2 :\n");
      affiche_matrice_pointeur(mat2,TAILLE_MATRICE);
      printf("Affichage resultat somme :\n");
      affiche_matrice_pointeur(mat_res,TAILLE_MATRICE);
      printf("\n");
      /*Notez ci-dessus que la matrice mat_res_op_constante n'est pas de dim constante !!*/

  

      printf("**Test somme matrice a dimension constante\n"); 
      mat_res_op_constante=somme_constante(mat1_constante,mat2_constante,TAILLE_MATRICE);
      printf("Affichage matrice dimension constante 1 :\n");
      affiche_matrice_constante(mat1_constante,TAILLE_MATRICE);
      printf("Affichage matrice dimension constante 2 :\n");
      affiche_matrice_constante(mat2_constante,TAILLE_MATRICE);
      printf("Affichage resultat somme :\n");
      affiche_matrice_pointeur(mat_res_op_constante,TAILLE_MATRICE);
      printf("\n");
      /*Notez ci-dessus que la matrice mat_res_op_constante n'est pas de dim constante !!*/
      printf("\n");
    }
  
  /* ---------- Test itoa ------------ */
  if(q9)
    {
      n=101;
      printf("***Test itoa : La chaine trouvee pour %d est %s\n",n,itoa(n));
      n=-16;
      printf("***Test itoa : La chaine trouvee pour %d est %s\n",n,itoa(n));
      n=0;
      printf("***Test itoa : La chaine trouvee pour %d est %s\n",n,itoa(n));
    }

  
  /* ----- On nettoie --------- */
  printf("\n\nOn lance les etapes de liberation memoire...\n");

  /* liberation des espaces alloues */
  if(q6)
    libere_mem(&result_concat);
  if(q7)
    libere_mem(&result_sous_chaine);
  /*pour les matrices il faut liberer dans l'ordre inverse*/
  if(q8)
    {
      for(i=0;i<TAILLE_MATRICE;i++)
	{
	  libere_mem(&mat1[i]); 
	  libere_mem(&mat2[i]);
	  libere_mem(&mat_res_op_constante[i]);
	  libere_mem(&mat_res[i]);
	}
      /*puis on libere le pointeur de pointeur*/
      libere_mem(&mat1);
      libere_mem(&mat2);
      libere_mem(&mat_res_op_constante);
      libere_mem(&mat_res);
    }
  
  /*a noter on ne peut pas liberer les parties allouee par itoa*/
  /*car les resultats n'ont pas ete recuperes par un pointeur*/
  /*donc penser a le faire si vous voulez les liberer plus tard*/
  /*declarer un char * res_itoa1=NULL; et char * res_itoa2=NULL;*/
  /*n=101;res_itoa1=itoa(n); ... n=-16;res_itoa2=itoa(n);*/
  /* faire les printf, puis lancer  libere_mem(&res_itoa1);liberer_mem(&res_itoa2);*/
  /* vous trouverez le code ci-dessous */
  
  
  /* -- autre version de liberation memoire -- */
  /* version utilisant libere_mem_peda qui force a mettre un (void **) */
  /* 
   if(q6)
    libere_mem_peda((void **)&result_concat);
  if(q7)
    libere_mem_peda((void **)&result_sous_chaine);
  if(q8)
    {
      for(i=0;i<TAILLE_MATRICE;i++)
	{
	  libere_mem_peda((void **)&mat1[i]); 
	  libere_mem_peda((void **)&mat2[i]);
	  libere_mem_peda((void **)&mat_res_op_constante[i]);
	  libere_mem_peda((void **)&mat_res[i]);
	}
     
      libere_mem_peda((void **)&mat1);
      libere_mem_peda((void **)&mat2);
      libere_mem_peda((void **)&mat_res_op_constante);
      libere_mem_peda((void **)&mat_res);
    }
  */

  /* ---- autre version --- */
  /*ci-dessous un code si on voulait utiliser free directement et non pas libere_mem*/
  /* mais ATTENTION il faut penser a remettre les pointeurs a NULL :*/
  /*
   if(q6)
    {
      free(result_concat);
      result_concat=NULL;
    }
  if(q7)
    {
     free(result_sous_chaine);
     result_sous_chaine=NULL;
   }
  if(q8)
    {
     for(i=0;i<TAILLE_MATRICE;i++)
      {
        free(mat1[i]);
        mat1[i]=NULL;
        free(mat2[i]);
        mat2[i]=NULL;
        free(mat_res_op_constante[i]);
        mat_res_op_constante[i]=NULL;
        free(mat_res[i]);
       mat_res[i]=NULL;
      }
     
    free(mat1);
    mat1=NULL;
    free(mat2);
    mat2=NULL;
    free(mat_res_op_constante);
    mat_res_op_constante=NULL;
    free(mat_res);
    mat_res=NULL;
   }
  */



  printf("\n...Et voila c'est fini\n\n");
  printf("Si tout a bien marche on peut encore afficher des choses encore en memoire:\n");
  printf("n de itoa %d, chaine de sous-chaine: %s\nMatrice constante 1:\n",n,chaine);
  affiche_matrice_constante(mat1_constante,TAILLE_MATRICE);
  printf("Bye\n");

  return EXIT_SUCCESS;
}

