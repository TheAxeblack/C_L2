#include <stdlib.h>
#include <stdio.h>

typedef struct date{
  int jour;
  char mois[10];
  int annee;
}date;

typedef struct tabDates{
  date tab[1000];
  int nbDate;
}tabDates;

void afficheDate(date d, FILE *flux){
  fprintf(flux, "%d %s %d\n", d.jour, d.mois, d.annee);
}

void affListeDate(tabDates t){
  int i;
  for(i = 0; i < t.nbDate; i++){
    afficheDate(t.tab[i], stdout);
  }
}

/*---fonction servant à déterminer le mois à partir d'une chaîne de caractère---*/
int mois(date d){
  switch(d.mois[0]){
    case 'j':
      if(d.mois[1] == 'a'){
        return 1;
      }else if((d.mois[3]) == 'n'){
        return 6;
      }else{
        return 7;
      }
      break;
    case 'f':
      return 2;
      break;
    case 'a':
      if(d.mois[1] == 'v'){
        return 4;
      }else{
        return 8;
      }
      break;
    case 'm':
      if(d.mois[2] == 'r'){
        return 3;
      }
      else{
        return 5;
      }
    case 's':
      return 9;
      break;
    case 'o':
      return 10;
      break;
    case 'n':
      return 11;
      break;
    case 'd':
      return 12;
      break;
    default:
      break;
  }
  return 0;
}

int cmpDates(date d1, date d2){
  if(d1.jour == d2.jour && mois(d1) == mois(d2) && d1.annee == d2.annee){
    return 0;
  }
  if(d1.annee > d2.annee){
    return 1;
  }
  if(d1.annee < d2.annee){
    return -1;
  }
  if(mois(d1) > mois(d2)){
    return 1;
  }
  if(mois(d1) < mois(d2)){
    return -1;
  }
  if(d1.jour > d2.jour){
    return 1;
  }
  return -1;
}

void remplirTabDates(char *chemin_fic, tabDates *t){
  int i, j, jour, annee;
  char mois[20];
  date tmp, echange;
  FILE *fic = NULL;
  fic = fopen(chemin_fic, "r");

  if(fic == NULL){
    printf("Fichier non trouvé\n");
    exit(-1);
  }

  if(fscanf(fic, "%d %s %d", &jour, mois, &annee) == 3){
    t->nbDate = 1;
    t->tab[0].jour = jour;
    sprintf(t->tab[0].mois, "%s", mois);
    t->tab[0].annee = annee;
  }

  while(t->nbDate < 1000 && fscanf(fic, "%d %s %d", &tmp.jour, tmp.mois, &tmp.annee) == 3){
    i = 0;

    while(i < t->nbDate && cmpDates(tmp, t->tab[i]) == 1){
      i++;
    }
    if(i == t->nbDate){
      t->tab[i] = tmp;
      t->nbDate++;
    }
    else if(cmpDates(tmp, t->tab[i]) != 0){
      for(j = t->nbDate; j > i; j--){
        echange = t->tab[j];
        t->tab[j] = t->tab[j-1];
        t->tab[j-1] = echange;
      }
      t->tab[i] = tmp;
      t->nbDate++;
    }
  }
}

void saveTabDates(char *chemin_fic, tabDates t){
  int i;
  FILE *fic = NULL;
  fic = fopen(chemin_fic, "w");

  if(fic == NULL){
    printf("Fichier non trouvé\n");
    exit(-1);
  }

  for(i = 0; i < t.nbDate; i++){
    afficheDate(t.tab[i], fic);
    afficheDate(t.tab[i], stdout);
  }
}

int main(int argc, char *argv[]){
  tabDates t;

  if(argc < 3){
    printf("Trop peu d'arguments\n");
    exit(-1);
  }

  remplirTabDates(argv[1], &t);
  saveTabDates(argv[2], t);

  exit(0);
}
