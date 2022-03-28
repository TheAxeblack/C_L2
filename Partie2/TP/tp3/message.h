//
// Created by Utilisateur on 28/03/2022.
//

#ifndef C_MESSAGE_H
#define C_MESSAGE_H

typedef struct message {
    char *expediteur;
    char *sujet;
    char *date;
    char *contenu;
} struct_message;

typedef struct cellule_msg {
    struct_message objet;
    struct cellule_msg *suivant;
} struct_cell_msg;

typedef struct_cell_msg *messagerie;

typedef messagerie file_msg;

#endif //C_MESSAGE_H
