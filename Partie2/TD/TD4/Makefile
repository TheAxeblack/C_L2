#exemple de Makefile  pour le td4 
#Ci-dessous j'indique les cibles pour chaque exercice, les solutions sont indiquees dans tous les fichiers des LISTE_* correspondantes ci-dessous
#Fichiers Ex8: td4_8
#Fichiers Ex9: td4_9
#Fichiers Ex10: td4_mat
#Fichiers Ex11: main_file_2p_tableu : la correction utilise des piles avec tableau, mais elle s'adapte facilement pour des piles à base de file
#Fichiers Ex12: pile_tableau pour la partie pile et file_tableau pour la partie file
#Fichiers Ex13 Matrice Creuse: td4_mat_creuse
#Bonus file av 2 piles implémentées sous forme de tableau, Fichiers: file_tableau2 (main_file_2p_tableau)


CC = gcc #compilateur
CFLAGS = -W -Wall -pedantic -std=c89   #option
LDFLAGS =   #librairies supplementaires
LISTE_TD4_8 = mon_erreur.o allocation.o liste.o td4_8.o main_td4_8.o
LISTE_TD4_9 = mon_erreur.o allocation.o listedc.o main_td4_9.o
LISTE_TD4_MAT = mon_erreur.o allocation.o matrice.o main_matrice.o
LISTE_F2POINTEURS = mon_erreur.o allocation.o liste.o file_2pointeurs.o main_file2pointeurs.o
LISTE_PILE_TABLEAU = pile_tableau.o main_pile_tableau.o 
LISTE_FILE_TABLEAU =  file_tableau.o main_file_tableau.o
LISTE_FILE_TABLEAU2 =  file_av_2_piles_tableau.o main_file_av_2_piles_tableau.o pile_tableau.o
LISTE_TD4_MAT_C = mon_erreur.o allocation.o matrice_creuse.o liste_gen.o main_matrice_creuse.o


#pour tout creer
all: td4_8 td4_9 td4_mat main_file_2pointeurs pile_tableau file_tableau main_file_2p_tableau

td4_8 : $(LISTE_TD4_8)
	$(CC) $(LISTE_TD4_8) -o $@ $(lDFLAGS) 
#dans la ligne du dessus il y a une tabulation en debut ligne !! 

td4_9 : $(LISTE_TD4_9)
	$(CC) $(LISTE_TD4_9) -o $@ $(lDFLAGS) 
#dans la ligne du dessus il y a une tabulation en debut ligne !! 

main_file_2pointeurs : $(LISTE_F2POINTEURS)
	$(CC) $(LISTE_F2POINTEURS) -o $@ $(lDFLAGS) 
#dans la ligne du dessus il y a une tabulation en debut ligne !! 

td4_mat: $(LISTE_TD4_MAT)
	$(CC) $(LISTE_TD4_MAT) -o $@ $(lDFLAGS)	
#dans la ligne du dessus il y a une tabulation en debut ligne !! 


td4_mat_creuse: $(LISTE_TD4_MAT_C)
	$(CC) $(LISTE_TD4_MAT_C) -o $@ $(lDFLAGS)	
#dans la ligne du dessus il y a une tabulation en debut ligne !!


file_tableau: $(LISTE_FILE_TABLEAU)
	$(CC) $(LISTE_FILE_TABLEAU) -o $@ $(lDFLAGS)

pile_tableau: $(LISTE_PILE_TABLEAU)
	$(CC) $(LISTE_PILE_TABLEAU) -o $@ $(lDFLAGS)

main_file_2p_tableau:  $(LISTE_FILE_TABLEAU2)
	$(CC) $(LISTE_FILE_TABLEAU2) -o $@ $(lDFLAGS)


#declaration des cibles .o
mon_erreur.o : mon_erreur.c mon_erreur.h
	$(CC) $(CFLAGS) -c $<
allocation.o : allocation.c allocation.h
	$(CC) $(CFLAGS) -c $<
liste.o : liste.c liste.h
	$(CC) $(CFLAGS) -c $<
td4_8.o : td4_8.c
	$(CC) $(CFLAGS) -c $<
main_td4_8.o : main_td4_8.c  
	$(CC) $(CFLAGS) -c $<
main_td4_9.o : main_td4_9.c  
	$(CC) $(CFLAGS) -c $<
listedc.o : listedc.c listedc.h
	$(CC) $(CFLAGS) -c $<
matrice.o : matrice.c matrice.h
	$(CC) $(CFLAGS) -c $<
main_matrice.o: main_matrice.c
	$(CC) $(CFLAGS) -c $<
pile_tableau.o: pile_tableau.c pile_tableau.h
	$(CC) $(CFLAGS) -c $<
main_pile_tableau.o: main_pile_tableau.c
	$(CC) $(CFLAGS) -c $<
file_tableau.o: file_tableau.c file_tableau.h
	$(CC) $(CFLAGS) -c $<
main_file_tableau.o: main_file_tableau.c
	$(CC) $(CFLAGS) -c $<
file_av_2_piles_tableau.o: file_av_2_piles_tableau.c file_av_2_piles_tableau.h
	$(CC) $(CFLAGS) -c $<
main_file_av_2_piles_tableau.o: main_file_av_2_piles_tableau.c 
	$(CC) $(CFLAGS) -c $<
liste_gen.o : liste_gen.c liste_gen.h
	$(CC) $(CFLAGS) -c $<
matrice_creuse.o : matrice_creuse.c matrice_creuse.h
	$(CC) $(CFLAGS) -c $<
main_matrice_creuse.o: main_matrice_creuse.c
	$(CC) $(CFLAGS) -c $<

#Pour supprimer les .o
clean :
	rm -f *.o













