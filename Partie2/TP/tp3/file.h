#ifndef TP_FILE_H
#define TP_FILE_H

typedef liste file;

file file_vide();

int est_file_vide(file f);

file enfiler(file f, element elem);

element debut_file(file f);

file defiler(file f);

int taille_file(file f);

#endif
