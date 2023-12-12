#include <stdio.h>
#include <stdlib.h>
#include "lib/manage.h"
//#include "lib/tools.h"

int main(){
    char *job;
    ID_JOB t;
    int level1;
    int level2;
    do{
        do{
            system("clear");
            design();
            t=prompt();
            job=t.job;
            level1=t.ID;
//            printf("level1=%d\n"
//                   "job=%s\n",level1,job);
//            sleep(3);

        }while(!level1) ;

        if(!strcmp(job,"administration")){
            system("clear");
            design();
            level2= administration_prompt(level1);
        }else if(!strcmp(job,"student_affairs")){
            system("clear");
            design();
            level2= student_affairs_prompt(level1);
        }else if(!strcmp(job,"service_maintainer")){
            system("clear");
            design();
            level2= service_maintainer_prompt(level1);
        }else if(!strcmp(job,"professor")){
            system("clear");
            design();
            level2= professor_prompt(level1);
        }

    }while(level2);



































//    login l, lg;
//    l.ID = 235;
//    strcpy(l.passHash, passHasher("hello"));
//
//    // Write the login structure to a binary file
//    FILE *fp = fopen("./Data/passwords.bin", "wb");
//    if (fp == NULL) {
//        perror("Error opening file");
//        return 1;
//    }
//
//    fwrite(&l, sizeof(login), 1, fp);
//    fclose(fp);
//
//    // Read the login structure back from the binary file
//    fp = fopen("./Data/passwords.bin", "rb");
//    if (fp == NULL) {
//        perror("Error opening file");
//        return 1;
//    }
//
//    fread(&lg, sizeof(login), 1, fp);
//
//    fclose(fp);
//
//    // Print the read values
//    printf("ID: %d\nPassHash: %s\n", lg.ID, lg.passHash);


  
  return 0;
}
