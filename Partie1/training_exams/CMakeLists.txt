cmake_minimum_required(VERSION 3.13)
project(training_exams C)

set(CMAKE_C_STANDARD 11)

include_directories(ex2)

add_executable(training_exams
        ex2/ex2.c
        ex2/ex2.h)
