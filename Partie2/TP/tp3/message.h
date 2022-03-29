#ifndef C_MESSAGE_H
#define C_MESSAGE_H

typedef struct message {
    char *expediteur;
    char *sujet;
    char *date;
    char *contenu;
} struct_message;


typedef struct_message *messagerie;

#endif
