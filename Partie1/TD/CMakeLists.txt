cmake_minimum_required(VERSION 3.13)
project(C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(Archive_L3_2020_-_2021)
include_directories(TD)

add_executable(C
        .idea/.gitignore
        .idea/C.iml
        .idea/modules.xml
        .idea/workspace.xml
        Archive_L3_2020_-_2021/Archive_complete_correction_tps_C_S3/Correction_jeu_du_pendu.c
        Archive_L3_2020_-_2021/Archive_correction_premier_partiel_C_S3/premier_partiel_C_code.c
        Archive_L3_2020_-_2021/Archive_correction_second_partiel_C_S3/second_partiel_C_code.c
        TD/decode.c
        TD/pgcd.c
        TD/puissance.c
        TD/factorielle.c
        TD/equivalence.c TD/degre2.c TD/min_max.c)
