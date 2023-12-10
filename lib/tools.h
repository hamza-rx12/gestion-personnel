#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STATIC_SALT "$6$somesalt$"

char *passHasher(char *password){
    char *hashed_pass=crypt(password, STATIC_SALT);
    return hashed_pass;
}