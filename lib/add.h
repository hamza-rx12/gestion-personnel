#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

void add_personnel(){
    personnel p;
    int choice;
    p.ID=generate_ID();
    printf("NAME = ");
    scanf("%s",p.name);
    printf("SURNAME = ");
    scanf("%s",p.surname);
    printf("EMAIL = ");
    scanf("%s",p.email);
    printf("SALARY = ");
    scanf("%d",&p.salary);
    printf("All good,now choose a job from the list:\n"
           "\t1.Professor.\n"
           "\t2.Student Affairs.\n"
           "\t3.Administration.\n"
           "\t4.Service maintainer(service info).\n"
           "Your choice (1-4): ");
    scanf("%d",&choice);
    while(choice!=1 && choice!=2 && choice!=3 && choice!=4){
        printf("Input a valid choice (1-4): ");
        scanf("%d",&choice);
    }
    switch(choice){
        case 1:
            strcpy(p.job,"professor");
            break;
        case 2:
            strcpy(p.job,"student_affairs");
            break;
        case 3:
            strcpy(p.job,"administration");
            break;
        case 4:
            strcpy(p.job,"service_maintainer");
            break;
    }

    // write to personnel.txt
    FILE *fp=fopen("./Data/personnel.txt","a");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    fprintf(fp,"%d %s %s %s %d %s",p.ID,p.name,p.surname,p.email,p.salary,p.job);
    fclose(fp);

    // demanding password and writing to passwords.bin
    login l;
    l.ID=p.ID;
    char p1[30], p2[30];
    printf("Now choose a password for the new account:\n");
    while(1){
        strcpy(p1,getpass("Input new password = "));
        strcpy(p2,getpass("Confirm password = "));
        if (!strcmp(p1,p2)) {
            printf("Password confirmed!\n");
            break;
        }else {
            printf("Wrong password! do it again:\n");
            sleep(1);
        }
    }
    strcpy(l.passHash,p1);
    FILE *f=fopen("./Data/passwords.bin","ab");
    if(f==NULL){
        perror("Error opening passwords.bin");
        exit(EXIT_FAILURE);
    }
    fwrite(&l, sizeof(login),1,f);
    fclose(f);



}