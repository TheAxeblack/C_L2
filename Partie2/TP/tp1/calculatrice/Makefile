CC= gcc
OPTIONS= -W -Wall -Werror -Wextra -std=c89 -pedantic -O3
OPTIONS_MATH= -lm

calc: utilitaire.o fonctions_std.o fonctions_trigo.o fonctions_non_std.o main.c
	$(CC) $(OPTIONS) main.c utilitaire.o fonctions_std.o fonctions_trigo.o fonctions_non_std.o -o calc $(OPTIONS_MATH)
utilitaire.o: utilitaire.c calculatrice.h
	$(CC) $(OPTIONS) -c utilitaire.c
fonctions_std.o: fonctions_std.c calculatrice.h
	$(CC) $(OPTIONS) -c fonctions_std.c $(OPTIONS_MATH)
fonctions_trigo.o: fonctions_trigo.c calculatrice.h
	$(CC) $(OPTIONS) -c fonctions_trigo.c $(OPTIONS_MATH)
fonctions_non_std.o: fonctions_non_std.c calculatrice.h
	$(CC) $(OPTIONS) -c fonctions_non_std.c
clean:
	rm -rf *.o calc