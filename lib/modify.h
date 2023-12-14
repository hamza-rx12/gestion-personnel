#ifndef MODIFY
#define MODIFY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

void modify_personnel();
void modify_leave(int ID,char status[]);
void modify_name(int ID);
void modify_surname(int ID);
void modify_email(int ID);
void modify_salary(int ID);
void modify_job(int ID);
void modify_password(int ID);

void modify_personnel(){
    personnel p;
    int ID;
    login l;

    printf(GREEN"Input the ID of the personnel to modify: "RESET);
    scanf("%d",&ID);
    if(check_ID(ID)){
        int choice;
        printf(GREEN"Choose what to modify: \n"RESET
               "\t1.name.\n"
               "\t2.surname.\n"
               "\t3.email.\n"
               "\t4.salary.\n"
               "\t5.job.\n"
               "\t6.password.\n"
               "Your choice (1-6): ");

        scanf("%d", &choice);
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {
            printf("Input a valid choice (1-6): ");
            scanf("%d", &choice);
        }




        if(choice==6) {
            //modifying inside passwords.bin
            FILE *fb = fopen("./Data/passwords.bin", "rb");
            FILE *tb = fopen("./Data/temp__passwords.bin", "wb");
            if (fb == NULL || tb == NULL) {
                perror("Error opening passwords files!");
                exit(EXIT_FAILURE);
            }
            while (fread(&l, sizeof(login), 1, fb) == 1) {
                if (p.ID != ID) fwrite(&l, sizeof(login), 1, fb);
                else {
                    char p1[30];
                    while (1) {
                        getchar();
                        strcpy(l.passHash, passHasher(getpass("Input password = ")));
                        strcpy(p1, passHasher(getpass("Confirm password = ")));
                        if (!strcmp(p1, l.passHash)) {
                            printf("Password confirmed!\n");
                            break;
                        } else {
                            printf("Wrong password! do it again:\n");
                            sleep(2);
                        }
                    }
                    fwrite(&l, sizeof(login), 1, tb);

                }

            }
            fclose(fb);
            fclose(tb);
            remove("./Data/passwords.bin");
            rename("./Data/temp__passwords.bin", "./Data/passwords.bin");
        }else{
            //modifying inside personnel.txt
            FILE *fp=fopen("./Data/personnel.txt","r");
            FILE *ft=fopen("./Data/temp__personnel.txt","w");
            if(fp==NULL || ft==NULL){
                perror("Error with personnel files!");
                exit(EXIT_FAILURE);
            }
            while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {

                if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
                else {
                    switch (choice) {
                        case 1:
                            printf("New name = ");
                            scanf("%s", p.name);
                            fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
                            break;
                        case 2:
                            printf("New surname = ");
                            scanf("%s", p.surname);
                            fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
                            break;
                        case 3:
                            printf("New email = ");
                            scanf("%s", p.email);
                            fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
                            break;
                        case 4:
                            printf("New salary = ");
                            scanf("%d", &p.salary);
                            fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
                            break;
                        case 5:
                            printf("New job = ");
                            scanf("%s", p.job);
                            fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
                            break;
                    }
                }
            }
            fclose(fp);
            fclose(ft);
            remove("./Data/personnel.txt");
            rename("./Data/temp__personnel.txt","./Data/personnel.txt");

        }






    }else{
        printf("ID not found!\n");
    }




}

void modify_leave(int ID, char status[]){
    leave l;
    FILE *fp=fopen("./Data/leave_requests.txt","r");
    FILE *ft=fopen("./Data/temp__leave_requests.txt","w");
    if(fp==NULL || ft==NULL){
        perror("Error with leave files!");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%d %d %d %s",&l.ID,&l.persoID,&l.numberDays,l.status)==4) {

        if(l.ID!=ID) fprintf(ft, "%-8d%-8d%-8d%-15s\n", l.ID,l.persoID,l.numberDays,l.status);
        else {
            strcpy(l.status,status);
            fprintf(ft, "%-8d%-8d%-8d%-15s\n", l.ID,l.persoID,l.numberDays,l.status);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("./Data/leave_requests.txt");
    rename("./Data/temp__leave_requests.txt","./Data/leave_requests.txt");

}


void modify_name(int ID){
    personnel p;
    if(check_ID(ID)){
        //modifying inside personnel.txt
        FILE *fp=fopen("./Data/personnel.txt","r");
        FILE *ft=fopen("./Data/temp__personnel.txt","w");
        if(fp==NULL || ft==NULL){
            perror("Error with personnel files!");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {

            if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
            else {

                printf(GREEN"New name = "RESET);
                scanf("%s", p.name);
                fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);

            }
        }
        fclose(fp);
        fclose(ft);
        remove("./Data/personnel.txt");
        rename("./Data/temp__personnel.txt","./Data/personnel.txt");

    }else{
        printf("ID not found!\n");
    }

}
void modify_surname(int ID){
    personnel p;
    if(check_ID(ID)){
        //modifying inside personnel.txt
        FILE *fp=fopen("./Data/personnel.txt","r");
        FILE *ft=fopen("./Data/temp__personnel.txt","w");
        if(fp==NULL || ft==NULL){
            perror("Error with personnel files!");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {

            if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
            else {

                printf(GREEN"New surname = "RESET);
                scanf("%s", p.surname);
                fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);

            }
        }
        fclose(fp);
        fclose(ft);
        remove("./Data/personnel.txt");
        rename("./Data/temp__personnel.txt","./Data/personnel.txt");

    }else{
        printf("ID not found!\n");
    }
}
void modify_email(int ID){
    personnel p;
    if(check_ID(ID)){
        //modifying inside personnel.txt
        FILE *fp=fopen("./Data/personnel.txt","r");
        FILE *ft=fopen("./Data/temp__personnel.txt","w");
        if(fp==NULL || ft==NULL){
            perror("Error with personnel files!");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {

            if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
            else {

                printf(GREEN"New email = "RESET);
                scanf("%s", p.email);
                fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);

            }
        }
        fclose(fp);
        fclose(ft);
        remove("./Data/personnel.txt");
        rename("./Data/temp__personnel.txt","./Data/personnel.txt");

    }else{
        printf("ID not found!\n");
    }

}
void modify_salary(int ID){
    personnel p;
    if(check_ID(ID)){
        //modifying inside personnel.txt
        FILE *fp=fopen("./Data/personnel.txt","r");
        FILE *ft=fopen("./Data/temp__personnel.txt","w");
        if(fp==NULL || ft==NULL){
            perror("Error with personnel files!");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {

            if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
            else {

                printf(GREEN"New salary = "RESET);
                scanf("%d", &p.salary);
                fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);

            }
        }
        fclose(fp);
        fclose(ft);
        remove("./Data/personnel.txt");
        rename("./Data/temp__personnel.txt","./Data/personnel.txt");

    }else{
        printf("ID not found!\n");
    }

}
void modify_job(int ID){
    personnel p;
    if(check_ID(ID)){
        //modifying inside personnel.txt
        FILE *fp=fopen("./Data/personnel.txt","r");
        FILE *ft=fopen("./Data/temp__personnel.txt","w");
        if(fp==NULL || ft==NULL){
            perror("Error with personnel files!");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {

            if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
            else {
                int choice;
                printf(GREEN"Choose new job = \n"RESET);
                printf("\t1.Professor.\n"
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
                fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);

            }
        }
        fclose(fp);
        fclose(ft);
        remove("./Data/personnel.txt");
        rename("./Data/temp__personnel.txt","./Data/personnel.txt");

    }else{
        printf("ID not found!\n");
    }

}
void modify_password(int ID){

}

#endif // MODIFY