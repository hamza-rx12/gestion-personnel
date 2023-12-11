#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

void list_all();
void list_specific(int ID);
void list_service_maintainer();
void list_administration();
void list_professor();
void list_student_affairs();
void list_passwords();




void list_all(){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    int x=1;
    int count=0;
    while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(x){
            printf("Personnel list:\n");
            printf(YELLOW"%-8s%-15s%-15s%-30s%-10s%-15s\n"RESET,"ID","NAME","SURNAME","EMAIL","SALARY","JOB");
            x=0;
        }
        printf(BLUE"%-8d"RESET"%-15s%-15s%-30s%-10d%-15s\n",p.ID,p.name,p.surname,p.email,p.salary,p.job);
        count++;
    }
    if(count==0) printf("Personnel file empty!");
    fclose(fp);
}

void list_specific(int ID){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    int x=1;
    while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(p.ID==ID) {
            if(x){
                printf("Personnel ID %d:\n",ID);
                printf(YELLOW"%-8s%-15s%-15s%-30s%-10s%-15s\n"RESET,"ID","NAME","SURNAME","EMAIL","SALARY","JOB");
                x=0;
            }
            printf(BLUE"%-8d"RESET"%-15s%-15s%-30s%-10d%-15s\n",p.ID,p.name,p.surname,p.email,p.salary,p.job);
            break;
        }
    }
    if(p.ID!=ID) printf("ID not found!\n");
    fclose(fp);

}

void list_service_maintainer(){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    int x=1;
    int count=0;
    while(fscanf(fp,"\t%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(!(strcmp(p.job,"service_maintainer"))) {
            if(x){
                printf("Service maintainers:\n");
                printf(YELLOW"%-8s%-15s%-15s%-30s%-10s\n"RESET,"ID","NAME","SURNAME","EMAIL","SALARY");
                x=0;
            }
            printf(BLUE"%-8d"RESET"%-15s%-15s%-30s%-10d\n", p.ID, p.name, p.surname, p.email, p.salary);
            count++;
        }
    }
    if(count==0) printf("No Service maintainers found!");
    fclose(fp);
}

void list_administration(){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    int x=1;
    int count=0;
    while(fscanf(fp,"\t%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(!(strcmp(p.job,"administration"))) {
            if(x){
                printf("Administration stuff:\n");
                printf(YELLOW"%-8s%-15s%-15s%-30s%-10s\n"RESET,"ID","NAME","SURNAME","EMAIL","SALARY");
                x=0;
            }
            printf(BLUE"%-8d"RESET"%-15s%-15s%-30s%-10d\n", p.ID, p.name, p.surname, p.email, p.salary);
            count++;
        }
    }
    if(count==0) printf("No administration stuff found!");
    fclose(fp);

}

void list_professor(){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    int x=1;
    int count=0;
    while(fscanf(fp,"\t%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(!(strcmp(p.job,"professor"))) {
            if(x){
                printf("Professors:\n");
                printf(YELLOW"%-8s%-15s%-15s%-30s%-10s\n"RESET,"ID","NAME","SURNAME","EMAIL","SALARY");
                x=0;
            }
            printf(BLUE"%-8d"RESET"%-15s%-15s%-30s%-10d\n", p.ID, p.name, p.surname, p.email, p.salary);
            count++;
        }
    }
    if(count==0) printf("No professors found!");
    fclose(fp);


}

void list_student_affairs(){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    int x=1;
    int count=0;
    while(fscanf(fp,"\t%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(!(strcmp(p.job,"student_affairs"))) {
            if(x){
                printf("Student affairs stuff:\n");
                printf(YELLOW"%-8s%-15s%-15s%-30s%-10s\n"RESET,"ID","NAME","SURNAME","EMAIL","SALARY");
                x=0;
            }
            printf(BLUE"%-8d"RESET"%-15s%-15s%-30s%-10d\n", p.ID, p.name, p.surname, p.email, p.salary);
            count++;
        }
    }
    if(count==0) printf("No student affairs stuff found!");
    fclose(fp);

}

void list_passwords(){
    login l;
    FILE *fp=fopen("./Data/passwords.bin","rb");
    while(fread(&l,sizeof(login),1,fp)==1)
        printf("%d\t%s\n",l.ID,l.passHash);
    fclose(fp);
}

void list_leave(){
    FILE *fp=fopen("./Data/leave_requests.txt","r");
    if(fp==NULL){
        perror("Error opening leave_requests.txt");
        exit(EXIT_FAILURE);
    }
//    while(fscanf)
    fclose(fp);
}

#endif // LIST

