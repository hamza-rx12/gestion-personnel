#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lib/manage.h"
#include "lib/list.h"

//char *test(int x){
//    if(x==0)
//        return NULL;
//    else
//        return "hello";
//}

int main() {
//    list_specific(235);
//    login l;
//    char p1[30];
//
//    l.ID=235;
//
//    strcpy(l.passHash, passHasher(getpass("input password: ")));
//    FILE *fb=fopen("./Data/passwords.bin","ab");
//    if(fb==NULL){
//        perror("Error opening passwords.bin");
//        exit(EXIT_FAILURE);
//    }
//    fwrite(&l, sizeof(login),1,fb);
//    fclose(fb);
//    add_personnel();
//    modify_personnel();
//    getchar();
//    char *a;
//    int x;
//    do{
//        printf("enter word: ");
//        scanf("%d",&x);
//        a=test(x);
//    }while(a);
//    free(a);
    list_passwords();
//    add_personnel();
//    login l;
//    list_all();
//    FILE *fp=fopen("./Data/passwords.bin","rb");
//    while(fread(&l,sizeof(login),1,fp)==1)
//        printf("%d\t%s\n",l.ID,l.passHash);
    return 0;
}

