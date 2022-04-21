#ifndef C_EX2_H
#define C_EX2_H

typedef struct message_struct {
    char *expediteur;
    char *sujet;
    char *date;
    char *contenu;
} struct_message;

typedef struct_message m_element;

typedef struct cellule_struct {
    m_element val;
    struct cellule_struct *suivant;
} struct_cell;

typedef struct_cell *m_liste;

#endif
