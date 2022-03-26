#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 10

int enreg_secr(char mot_secret[]){
  int lg ;
  printf ("donner le mot secret : ");

  /*J'ai rajouté cette ligne qui évite de faire sa fonction vider buffer de mort*/
  while(getchar() != '\n'){}
  if(fgets (mot_secret, N, stdin) != NULL){
    lg = strlen (mot_secret) ;
    return (lg-1) ;
  }
 else return -1;
}

int enreg_secr_bis(char mot_secret[]){
  int i = 0, nb_ligne;
  FILE *fic = NULL;
  fic = fopen("fic-mots-secrets.txt", "r");

  if(fic == NULL){
    printf("Fichier non trouvé\n");
    exit(-1);
  }

  while(fscanf(fic, "%s", mot_secret) == 1){
    i++;
  }
  rewind(fic);

  nb_ligne = rand()%i;
  for(i = 0; i < nb_ligne; i++){
    if(fscanf(fic, "%s", mot_secret) != 1){}
  }
  fclose(fic);
  return strlen(mot_secret)-1;
}

void aff_tab(char t[], int n){
  int i;
  printf("\ncontenu du tableau : ");
  for(i = 0; i < n; i++)
    printf("%c ", t[i]);
  printf("\n\n");
}

void poser_lettre(char c, char mot_secret[], int lg, char tab[]){
  int i, cpt = 0;
  for(i = 0; i < lg; i++){
    if(mot_secret[i] == c){
      tab[i] = c;
      cpt++;
    }
  }
  if(cpt == 0){
    printf("Lettre absente !\n");
  }
}

void essai_mot(char mot_secret[]){
  char tab[N];
  while(getchar() != '\n'){}
  if(fgets(tab, N, stdin) != NULL){
    if(!strcmp(mot_secret, tab)){
      printf("BRAVO, vous avez trouvé le mot secret !\n\n");
    }
    else{
      printf("Perdu !\n\n");
    }
  }
}

/*---Fonction emondant le main de la gestion du menu---*/
int menu(){
  int choix;

  printf("Bienvenu dans le jeu du pendu\n");
  printf("Faite votre choix :\n");
  printf("1 - Jouer\n");
  printf("2 - Rajouter un mot\n");
  printf("3 - Quitter\n");

  while(!(0 < choix && choix < 4)){
    choix = 0;
    if(scanf(" %d", &choix) != 1){
      printf("Mauvaise entrée :/ \n");
      exit(-1);
    }
    if(!(0 < choix && choix < 4)){
      printf("Choix incohérent, recommencez !\n");
    }
  }
  return choix;
}

/*---Fonction gérant une partie---*/
void jeu(){
  char mot_secret[N], tab[N], essai_char;
  int lg, i, nb_lettre_prop=0, fin=0, choix;

  lg = enreg_secr_bis(mot_secret);

  printf("Le mot secret comporte %d lettres.\n", lg);
  for(i = 0; i < lg; i++){
    tab[i] = '_';
  }

  while(!fin && nb_lettre_prop < 10){
    aff_tab(tab, lg);
    printf("que voulez-vous proposer : un mot (1) ? une lettre (2) ? : ");

    choix = 0;
    while(choix != 1 && choix != 2){
      if(scanf("%d", &choix) != 1){
        printf("Mauvaise entrée :/\n");
        exit(-1);
      }
      if(choix != 1 && choix != 2){
        printf("Choix incohérent, recommencez !\n");
      }
    }

    if(choix == 2){
      if(scanf(" %c", &essai_char) != 1){
        printf("Mauvaise entrée :/\n");
        exit(-1);
      }
      poser_lettre(essai_char, mot_secret, lg, tab);
      nb_lettre_prop++;
    }
    else{
      essai_mot(mot_secret);
      fin = 1;
    }
  }
  if(nb_lettre_prop == 10){
    printf("Perdu, trop d'essais !\n\n");
  }
}

/*---Fonction permettant de rajouter un mot dans le fichier---*/
void ajouter_mot(){
  FILE *fic = NULL;
  char mot[N*2];
  fic = fopen("fic-mots-secrets.txt", "a");

  if(fic == NULL){
    printf("Fichier non trouvé\n");
    exit(-1);
  }

  printf("Quel est le mot ? : ");
  while(getchar() != '\n'){}
  if(fgets (mot, N, stdin) != NULL && 5 < strlen(mot) && strlen(mot) < 11){
    fprintf(fic, "%s\n", mot);
  }
  else{
    printf("Mauvaise entrée :/\n");
  }
  printf("\n");
  while(getchar() != '\n'){}
  fclose(fic);
}

int main(void){
  int choix = 0;
  srand(time(NULL));

  choix = menu();
  while(choix != 3){
    switch(choix){
      case 1:
        jeu();
        break;
      case 2:
        ajouter_mot();
        break;
      default:
        break;
    }
    choix = menu();
  }
  exit(0);
}
