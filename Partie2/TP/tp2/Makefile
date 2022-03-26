CC= gcc
OPTIONS= -W -g -Wall -Werror -Wextra -std=c89 -pedantic -O3
OPTIONS_MATH= -lm

tp2: erreur.o allocation.o ex3.o pascal.o
	$(CC) $(OPTIONS) main.c erreur.o allocation.o ex3.o pascal.o -o tp2
pascal.o: pascal.c allocation.h tp2.h
	$(CC) $(OPTIONS) -c pascal.c
ex3.o: ex3.c allocation.h tp2.h
	$(CC) $(OPTIONS) -c ex3.c
allocation.o: allocation.c erreur.h allocation.h
	$(CC) $(OPTIONS) -c allocation.c
erreur.o: erreur.c erreur.h
	$(CC) $(OPTIONS) -c erreur.c
clean:
	rm -rf *.o tp2