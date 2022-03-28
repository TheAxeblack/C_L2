CC= gcc
OPTIONS= -W -Wall -Wextra -std=c89 -pedantic -O3
OPTIONS_MLV_1= `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTIONS_MLV_2= `pkg-config --libs-only-l MLV`
MATHS_OPTIONS= -lm

tp3: liste.o pile.o file.o ex1.o ex2.o
	$(CC) $(OPTIONS_MLV_1) $(OPTIONS) main.c liste.o pile.o file.o ex1.o ex2.o -o tp3 $(OPTIONS_MLV_2)
ex2.o: ex2.c tp3.h
	$(CC) $(OPTIONS) -c ex2.c
ex1.o: ex1.c tp3.h
	$(CC) $(OPTIONS_MLV_1) $(OPTIONS) -c ex1.c $(OPTIONS_MLV_2)
liste.o: liste.c liste.h
	$(CC) $(OPTIONS) -c liste.c
pile.o: pile.c pile.h
	$(CC) $(OPTIONS) -c pile.c
file.o: file.c file.h
	$(CC) $(OPTIONS) -c file.c
clean:
	rm -rf *.o tp3