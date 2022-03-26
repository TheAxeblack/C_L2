cmake_minimum_required(VERSION 3.13)
project(TP C)

set(CMAKE_C_STANDARD 90)

add_executable(TP tp1/triangle.c tp1/ackermann.c
        tp1/types.c
        tp1/calculatrice/main.c
        tp1/calculatrice/utilitaire.c
        tp1/calculatrice/fonctions_std.c
        tp1/calculatrice/fonctions_trigo.c
        tp1/calculatrice/calculatrice.h
        tp1/calculatrice/fonctions_non_std.c
        tp2/ex1.c
        tp2/allocation.c tp2/allocation.h
        tp2/ex3.c
        tp2/main.c
        tp2/erreur.c tp2/erreur.h tp2/tp2.h tp2/pascal.c
        tp2/tp_anne_canteaut/exemple.c tp3/ex1.c tp3/main.c tp3/tp3.h tp3/liste.h tp3/liste.c tp3/pile.c tp3/pile.h tp3/file.c tp3/file.h)
