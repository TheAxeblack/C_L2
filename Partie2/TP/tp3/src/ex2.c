#include "../inc/tp3.h"

message ajouter_message(message m, element val) {
    return enfiler(m, val);
}

message supprimer_message(message m) {
    m = defiler(m);
    return m;
}


message afficher_message(message m) {
    message ptr1 = m;
    message ptr2;

    while (!est_file_vide(ptr1)) {
        ptr2 = ptr1->suivant;
        while (!est_file_vide(ptr2)) {
            if (strcmp(ptr1->val.date, ptr2->val.date) > 0) {
                m_element e = ptr1->val;
                ptr1->val = ptr2->val;
                ptr2->val = e;
            }
            if (strcmp(ptr1->val.date, ptr2->val.date) == 0) {
                if (strcmp(ptr1->val.expediteur, ptr2->val.expediteur) > 0) {
                    m_element e = ptr1->val;
                    ptr1->val = ptr2->val;
                    ptr2->val = e;
                }
            }
            ptr2 = ptr2->suivant;
        }
        ptr1 = ptr1->suivant;
    }
    ptr1 = m;
    while (!est_file_vide(ptr1)) {
        printf("Message du %s de %s\nSujet du message : %s\n%s\n", ptr1->val.date, ptr1->val.expediteur,
               ptr1->val.sujet, ptr1->val.contenu);
        ptr1 = ptr1->suivant;
    }
    return m;
}