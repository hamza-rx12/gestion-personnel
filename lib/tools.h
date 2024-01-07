#ifndef TOOLS
#define TOOLS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "variables.h"

#define STATIC_SALT "$6$somesalt$"
#define MAX_BUFFER_SIZE 1024

void design() {
    printf(CYAN"\n"
           "\n"
           "                    ███████╗███╗   ██╗███████╗ █████╗ ██╗  ██╗                              \n"
           "                    ██╔════╝████╗  ██║██╔════╝██╔══██╗██║  ██║                              \n"
           "                    █████╗  ██╔██╗ ██║███████╗███████║███████║                              \n"
           "                    ██╔══╝  ██║╚██╗██║╚════██║██╔══██║██╔══██║                              \n"
           "                    ███████╗██║ ╚████║███████║██║  ██║██║  ██║                              \n"
           "                    ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝                              \n"
           "                                                                                            \n"
           "        ██████╗ ███████╗██████╗ ███████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗██╗            \n"
           "        ██╔══██╗██╔════╝██╔══██╗██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██║            \n"
           "        ██████╔╝█████╗  ██████╔╝███████╗██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║            \n"
           "        ██╔═══╝ ██╔══╝  ██╔══██╗╚════██║██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║            \n"
           "        ██║     ███████╗██║  ██║███████║╚██████╔╝██║ ╚████║██║ ╚████║███████╗███████╗       \n"
           "        ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚══════╝       \n"
           "                                                                                            \n"
           "███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n"
           "████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n"
           "██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║   \n"
           "██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   \n"
           "██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   \n"
           "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n"
           RESET
           "");
    printf("                                                                                  @HAMZA\n");

}

char *passHasher(char *password) {
    char *hashed_pass = crypt(password, STATIC_SALT);
    return hashed_pass;
}

int loginChecker(login l) {
    login lg;
    FILE *fp = fopen("./Data/passwords.bin", "rb");
    if (fp == NULL) {
        perror("Error opening passwords.bin!");
        exit(EXIT_FAILURE);
    }
    while (fread(&lg, sizeof(login), 1, fp) == 1) {
        if (lg.ID == l.ID) {
            if (!strcmp(lg.passHash, l.passHash)) {
                fclose(fp);
                return 1;
            } else {
                printf("Wrong password!\n");
                fclose(fp);
                return 0;
            }
        }
    }
    printf("ID not found in data base!\n");
    fclose(fp);
    return 0;

}

char *IDtoJob(int ID) {
    personnel p;
    FILE *fp = fopen("./Data/personnel.txt", "r");
    if (fp == NULL) {
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%d %s %s %s %d %s", &p.ID, p.name, p.surname, p.email, &p.salary, p.job) == 6) {
        if (p.ID == ID) {
            fclose(fp);
            return strdup(p.job);
        }
    }
    fclose(fp);
    printf("Error finding ID %d job!\n", ID);
    exit(EXIT_FAILURE);

}

int generate_ID() {
    login l;
    int ID = 1;
    FILE *fp = fopen("./Data/passwords.bin", "rb");
    if (fp == NULL) {
        perror("Error opening passwords.bin");
        exit(EXIT_FAILURE);
    }
    int IDs[MAX_BUFFER_SIZE];
    int i = 0;
    while (fread(&l, sizeof(login), 1, fp) == 1) {
        IDs[i] = l.ID;
        i++;
    }
    // Sort IDs in ascending order
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (IDs[j] > IDs[k]) {
                int temp = IDs[j];
                IDs[j] = IDs[k];
                IDs[k] = temp;
            }
        }
    }
    //fetch smallest non-used id possible
    for (int j = 0; j < i; j++) {
        if (ID == IDs[j]) {
            ID++;
        } else if (IDs[j] == ID - 1) continue;
        else break;
    }
    fclose(fp);
    return ID;

}

int check_ID(int ID) {
    login l;
    FILE *fb = fopen("./Data/passwords.bin", "rb");
    if (fb == NULL) {
        perror("Error opening passwords.bin!");
        exit(EXIT_FAILURE);
    }
    while (fread(&l, sizeof(login), 1, fb) == 1) {
        if (l.ID == ID) {
            fclose(fb);
            return 1;
        }
    }
    fclose(fb);

    return 0;
}

#endif // TOOLS