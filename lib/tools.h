#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STATIC_SALT "$6$somesalt$"

char *passHasher(char *password){
    char *hashed_pass=crypt(password, STATIC_SALT);
    return hashed_pass;
}

int loginChecker(login l){
    login lg;
    FILE *fp=fopen("./Data/passwords.bin","rb");
    if(fp==NULL){
        perror("Error opening passwords.bin!");
        exit(EXIT_FAILURE);
    }
    while(fread(&lg,sizeof(login),1,fp)==1){
        if(lg.ID==l.ID){
            if(!strcmp(lg.passHash,l.passHash)) {
                fclose(fp);
                return 1;
            }else{
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

char *IDtoJob(int ID){
    personnel p;
    FILE *fp=fopen("./Data/personnel.txt","r");
    if(fp==NULL){
        perror("Error opening personnel.txt");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%d %s %s %s %d %s",&p.ID,p.name,p.surname,p.email,&p.salary,p.job)==6){
        if(p.ID==ID){
            fclose(fp);
            return strdup(p.job);
        }
    }
    fclose(fp);
    printf("Error finding ID %d job!\n",ID);
    exit(EXIT_FAILURE);

}