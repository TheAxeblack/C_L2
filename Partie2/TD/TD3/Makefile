#exemple de Makefile avec compilation particuliere
#hist A. Habrard, 02/02/2016

CC = gcc #compilateur
CFLAGS = -Wall -std=c11  #option
LDFLAGS =   #librairies supplementaires
LISTE_TD3 = mon_erreur.o allocation.o fonctions_td3.o main_td3.o
LISTE_TD3_mem = $(wildcard td3_*.c) #liste des fichiers avec prefixe td3_ et se terminant par .c
LISTE_TD3_mem_base:=$(basename $(LISTE_TD3_mem)) #prefixe de la liste precedente (sans .c)


#pour tout creer
all: fonctions_td3 echange test-mem



#pour la fonction echange
echange : echange.c
	$(CC) $(CFLAGS)  echange.c -o echange
#dans la ligne du dessus il y a une tabulation en debut ligne !! 


#pour les questions II a V: creation des executables
test-mem : $(LISTE_TD3_mem)
	for i in $(LISTE_TD3_mem_base); do ( $(CC) $(CFLAGS) $$i.c -o $$i); done

#pour les autres questions
fonctions_td3 : $(LISTE_TD3)
	$(CC) $(LISTE_TD3) -o $@ $(lDFLAGS) 


#declaration des cibles .o
mon_erreur.o : mon_erreur.c mon_erreur.h
	$(CC) $(CFLAGS) -c $<
allocation.o : allocation.c allocation.h
	$(CC) $(CFLAGS) -c $<
fonctions_td3.o : fonctions_td3.c
	$(CC) $(CFLAGS) -c $<
main_td3.o : main_td3.c  fonctions_td3.c
	$(CC) $(CFLAGS) -c $<

#pour nettoyer les .o
clean :
	rm -f *.o

clean_fonctions :
	rm -f fonctions_td3.o














