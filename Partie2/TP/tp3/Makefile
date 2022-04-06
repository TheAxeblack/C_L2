CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3
OPTIONS_MLV_1= `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTIONS_MLV_2= `pkg-config --libs-only-l MLV`
MATHS_OPTIONS= -lm

OBJ=allocation.o liste.o pile.o file.o ex1.o ex2.c ex3.o

tp3: $(OBJ)
	$(CC) $(OPTIONS_MLV_1) $(OPTIONS) main.c $(OBJ) -o $@ $(OPTIONS_MLV_2)
ex3.o: ex3.c tp3.h
	$(CC) $(OPTIONS) -c ex3.c
ex2.o: ex2.c tp3.h
	$(CC) $(OPTIONS) -c ex2.c
ex1.o: ex1.c tp3.h
	$(CC) $(OPTIONS_MLV_1) $(OPTIONS) -c ex1.c $(OPTIONS_MLV_2)
allocation.o: allocation.c tp3.h
	$(CC) $(OPTIONS) -c allocation.c
liste.o: liste.c tp3.h
	$(CC) $(OPTIONS) -c liste.c
pile.o: pile.c tp3.h
	$(CC) $(OPTIONS) -c pile.c
file.o: file.c tp3.h
	$(CC) $(OPTIONS) -c file.c
clean:
	rm -rf *.o tp3