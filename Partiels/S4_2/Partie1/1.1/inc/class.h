#ifndef C_CLASS
#define C_CLASS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char STRING[20];
typedef struct student
{
    int id;
    STRING name;
    STRING firstname;
} student;
typedef student *PtrStudent;

#endif