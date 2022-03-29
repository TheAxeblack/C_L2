#ifndef C_MESSAGE_H
#define C_MESSAGE_H

typedef struct message {
    char *expediteur;
    char *sujet;
    char *date;
    char *contenu;
} struct_message;


typedef struct conversation {
    struct_message objet;
    struct conversation *suivant;
} struct_conversation;

typedef struct_conversation *messagerie;
#endif
