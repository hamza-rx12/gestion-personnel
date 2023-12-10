#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ID;
    char name[20];
    char surname[30];
    char email[50];
    char salary[20];
    char job[20];
}personnel;

typedef struct {
    int ID;
    char passHash[256];
}login;
