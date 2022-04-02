#include "tp3.h"

/*
file ajout_message(file f, element msg) {
    file k = f;
    enfiler(k, msg);
    if (!est_file_vide(k) && !est_file_vide(f))
        printf("Message ajoute\n");
    else
        fprintf(stderr, "Erreur, rien n'a été ajouté\n");
    return k;
}

file supprime_message(file f) {
    file p = f;
    defiler(p);
    return f;
}

void affiche_message(file f) {
    if (est_file_vide(f)) {
        fprintf(stderr, "Vous n'avez aucun messages pour le moment !\n");
        exit(EXIT_FAILURE);
    }
    while (!est_file_vide(f)) {
        printf("Sujet : %s\nAuteur = %s\nDate : %s\n Contenu : %s\n", f->objet.sujet, f->objet.expediteur,
               f->objet.date, f->objet.contenu);
        f = f->suivant;
    }
}*/
