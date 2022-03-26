CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3

promo : ex2.o
	$(CC) $(OPTIONS) ex2.o -o promo
ex2.o : ex2.c ex2.h
	$(CC) $(OPTIONS) -c ex2.c
clean :
	rm -rf *.o promo