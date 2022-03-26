CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3

toto : main.o recherche.o tri.o lecture.o
	$(CC) $(OPTIONS) recherche.o tri.o lecture.o main.o -o toto
main.o : main.c lecture.h
	$(CC) $(OPTIONS) -c main.c
recherche.o : recherche.c lecture.h
	$(CC) $(OPTIONS) -c recherche.c
tri.o : tri.c lecture.h
	$(CC) $(OPTIONS) -c tri.c
lecture.o : lecture.c lecture.h
	$(CC) $(OPTIONS) -c lecture.c
clean :
	rm -rf *.o *~ prog