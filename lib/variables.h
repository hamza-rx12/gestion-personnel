#ifndef VARIABLES
#define VARIABLES

#include <stdio.h>
#include <stdlib.h>

// ANSI color codes
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

typedef struct{
    int ID;
    char name[20];
    char surname[30];
    char email[50];
    int salary;
    char job[20];
}personnel;

typedef struct {
    int ID;
    char passHash[256];
}login;
typedef struct{
    int ID;
    int persoID;
    int numberDays;
    char status[10];
}leave;

#endif // VARIABLES
