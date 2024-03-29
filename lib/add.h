#ifndef ADD
#define ADD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

void add_personnel() {
    personnel p;
    login l;
    int choice;
    char p1[30], p2[30];
    p.ID = generate_ID();
    l.ID = p.ID;
    printf(GREEN"Fill in the new personnel data:\n"RESET);
    printf("NAME = ");
    scanf("%s", p.name);
    printf("SURNAME = ");
    scanf("%s", p.surname);
    printf("EMAIL = ");
    scanf("%s", p.email);
    printf("SALARY = ");
    scanf("%d", &p.salary);
    printf(GREEN"All good,now choose a job from the list:\n"RESET
           "\t1.Professor.\n"
           "\t2.Student Affairs.\n"
           "\t3.Administration.\n"
           "\t4.Service maintainer(service info).\n"
           GREEN"Your choice (1-4): "RESET);
    scanf("%d", &choice);
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        printf(GREEN"Input a valid choice (1-4): "RESET);
        scanf("%d", &choice);
    }
    switch (choice) {
        case 1:
            strcpy(p.job, "professor");
            break;
        case 2:
            strcpy(p.job, "student_affairs");
            break;
        case 3:
            strcpy(p.job, "administration");
            break;
        default:
            strcpy(p.job, "service_maintainer");
            break;
    }
    getchar();
    printf(GREEN"Now choose a password for the new account:\n"RESET);
    while (1) {
        strcpy(p1, getpass("Input password = "));
        strcpy(p2, getpass("Confirm password = "));
        if (!strcmp(p1, p2)) {
            printf(YELLOW"Password confirmed!\n"RESET);
            break;
        } else {
            printf(GREEN"Wrong password! Do it again:\n"RESET);
            sleep(1);
        }
    }

    // write to personnel.txt
    FILE *fp = fopen("./Data/personnel.txt", "a");
    if (fp == NULL) {
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
    fclose(fp);

    // writing to passwords.bin
    strcpy(l.passHash, passHasher(p1));
    FILE *fb = fopen("./Data/passwords.bin", "ab");
    if (fb == NULL) {
        perror("Error opening passwords.bin");
        exit(EXIT_FAILURE);
    }
    fwrite(&l, sizeof(login), 1, fb);
    fclose(fb);
    printf(YELLOW"Added successfully to personnel. Returning to main menu...\n"RESET);
    sleep(2);


}

void add_leave_request() {

}

#endif // ADD