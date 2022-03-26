#include <stdlib.h>
#include <stdio.h>

void strreverse(char *str){
  int i, lg = 0;
  char tmp;
  while(str[lg+1] != '\0'){
    lg++;
  }
  for(i = 0; i < lg/2+1; i++){
    tmp = str[i];
    str[i] = str[lg-i];
    str[lg-i] = tmp;
  }
}

int palindrome(char *str, int lg){
  int i = 0, diff = 0;
  char rev[lg];
  while(str[i] != '\0'){
    rev[i] = str[i];
    i++;
  }
  strreverse(rev);
  i = 0;
  while(str[i] != '\0' && !diff){
    diff = str[i]!=rev[i];
    i++;
  }
  return !diff;
}

/*---Le main dédié à l'exercice du palindrome---*/
/*
int main(void){
  char str[100];
  printf("Votre chaîne ? : ");
  if(scanf("%s", str) != 1){
    printf("Erreur de saisie\n");
    exit(-1);
  }
  if(palindrome(str, 100)){
    printf("votre chaine est un palindrome\n");
  }
  else{
    printf("Votre chaîne n'est pas un palindrome\n");
  }
  exit(0);
}
*/

int pgcd(int n, int d){
  int min, i, pgcd;
  if(n >= d){
    min = d;
  }
  else{
    min = n;
  }
  for(i = 1; i <= min; i++){
    if(n % i == 0 && d % i == 0){
      pgcd = i;
    }
  }
  return pgcd;
}

void simplifie(int *n, int *d){
  int div = pgcd(n[0], d[0]);
  n[0] /= div;
  d[0] /= div;
}

/*---Le main dédié à la fonction sur la simplification de fraction---*/
/*
int main(int argc, char *argv[]){
  int n, d;

  if(argc < 3){
    printf("Trop peu d'arguments\n");
    exit(-1);
  }
  if(atoi(argv[2]) == 0){
    printf("Division par zero impossible");
    exit(-1);
  }
  n = atoi(argv[1]);
  d = atoi(argv[2]);
  simplifie(&n, &d);
  printf("Voici la fraction simplifiée : %d/%d\n", n, d);
  exit(0);
}
*/

void aff_tab(int *tab, int lg){
  int i;
  for(i = 0; i < lg; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
}

int lecture(int *tab){
  int i, j, nb, lg, tmp;
  char chemin[100];
  FILE *fic = NULL;

  printf("Le chemin : ");
  if(scanf("%s", chemin) != 1){
    printf("Mauvaise saisie\n");
    exit(-1);
  }

  fic = fopen(chemin, "r");
  if(fic == NULL){
    printf("Fichier non trouvé\n");
    exit(-1);
  }

  if(fscanf(fic, "%d", &nb) == 1){
    tab[0] = nb;
    lg = 1;
  }

  while(fscanf(fic, "%d", &nb) == 1){
    i = 0;
    while(i < lg && nb < tab[i]){
      i++;
    }
    if(i == lg){
      tab[lg] = nb;
      lg++;
    }
    else if(nb > tab[i]){
      for(j = lg; j > i; j--){
        tmp = tab[j];
        tab[j] = tab[j-1];
        tab[j-1] = tmp;
      }
      tab[i] = nb;
      lg++;
    }
  }
  return lg;
  fclose(fic);
}

void save(int *tab, int lg){
  int i;
  FILE *fic = NULL;
  fic = fopen("save", "w");

  if(fic == NULL){
    printf("Fichier non trouvé\n");
    exit(-1);
  }

  aff_tab(tab, lg);
  for(i = 0; i < lg; i++){
    fprintf(fic, "%d\n", tab[i]);
  }
  fclose(fic);
}

int main(void){
  int i, tab[500], lg;

  lg = lecture(tab);
  aff_tab(tab, lg);
  save(tab, lg);

  exit(0);
}
