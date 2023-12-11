#include <stdio.h>
#include <stdlib.h>
#include "lib/tools.h"


int main(){

//    while(1){
//        char *p,*pc;
//        printf("Personal password = %s\n", p=getpass(""));
//        printf("Confirm password = %s\n", pc=getpass(""));
//
//
//        if (p==pc)
//            printf("Wrong password! Try again:\n");
//        else
//            break;
//    }

//    while(!strcmp(getpass("Confirm password = "),getpass("Personal password = "))){
//        printf("Wrong password! do it again:\n");
//            sleep(1);
//    }
    char p[30], pc[30];
    while(1){
        strcpy(p,getpass("Personal password = "));
        strcpy(pc,getpass("Confirm password = "));
        if (!strcmp(p,pc)) break;
        else {
            printf("Wrong password! do it again:\n");
            sleep(1);
        }
    }
    login l={1,"hello"};
//    l.ID=0;

    FILE *fp=fopen("./Data/passwords.bin","rb");
    while(fread(&l,sizeof(login),1,fp)==1){
        printf("%d\t %s\n",l.ID,l.passHash);
    }

    printf("%d\n",generate_ID());
    return 0;
}
