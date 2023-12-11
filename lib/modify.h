#ifndef MODIFY
#define MODIFY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

void modify_personnel(int ID,int x){
    personnel p;
    login l;
    switch(x){

    }

    //deleting inside personnel.txt
    FILE *fp=fopen("./Data/personnel.txt","r");
    FILE *ft=fopen("./Data/temp__personnel.txt","w");
    if(fp==NULL || ft==NULL){
        perror("Error with personnel files!");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6) {
        if(p.ID!=ID) fprintf(ft, "%-8d%-15s%-15s%-30s%-10d%-15s\n", p.ID, p.name, p.surname, p.email, p.salary, p.job);
    }
    fclose(fp);
    fclose(ft);
    remove("./Data/personnel.txt");
    rename("./Data/temp__personnel.txt","./Data/personnel.txt");

    //deleting inside passwords.bin
    FILE *fb=fopen("./Data/passwords.bin","rb");
    FILE *tb=fopen("./Data/temp__passwords.bin","wb");
    if(fb==NULL || tb==NULL){
        perror("Error opening passwords files!");
        exit(EXIT_FAILURE);
    }
    while(fread(&l, sizeof(login),1,fb)==1){
        if(p.ID!=ID) fwrite(&l, sizeof(login),1,fb);
    }
    fclose(fb);
    fclose(tb);


}

void modify_leave(int ID){

}

#endif // MODIFY