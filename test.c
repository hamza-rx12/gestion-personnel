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
typedef struct {
    char username[30];
    int uid;
    int gid;
    char comment[60];
    char homeFolder[60];
    char shell[60];
    char passHash[256];
}userinfo;
int main() {
    FILE *file = fopen("/etc/passwd", "r");

    if (file == NULL) {
        perror("Error opening /etc/passwd");
        return 1;
    }

    char line[256];
//    char username[64], password[64], uid[64], gid[64],comment[64], home[64], shell[64];

    while (fgets(line, sizeof(line), file) != NULL) {
        char username[64], password[64], uid[64], gid[64],comment[64], home[64], shell[64];
        // Use sscanf to parse the line into variables
        if (sscanf(line, "%63[^:]:%63[^:]:%63[^:]:%63[^:]:%63[^:]:%63[^:]:%63[^:\n]",
                   username, password, uid, gid, comment,home, shell) >= 3) {
            // Process the variables as needed
            printf("Username: %s\n", username);
            if (*password != '\0') printf("Password: %s\n", password);
            if (*uid != '\0') printf("UID: %s\n", uid);
            if (*gid != '\0') printf("GID: %s\n", gid);
            if (*comment != '\0') printf("Comment: %s\n", comment);
            if (*home != '\0') printf("Home: %s\n", home);
            if (*shell != '\0') printf("Shell: %s\n", shell);
            printf("\n");
            strcpy(username,"" );
            strcpy(password,"");
            strcpy(uid,"");
            strcpy(gid,"");
            strcpy(comment,"");
            strcpy(home,"");
            strcpy(shell,"");

        } else {
            // Handle parsing error
            fprintf(stderr, "Error parsing line: %s", line);
        }
    }

    fclose(file);
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
//    list_passwords();
//    add_personnel();
//    login l;
//    list_all();
//    FILE *fp=fopen("./Data/passwords.bin","rb");
//    while(fread(&l,sizeof(login),1,fp)==1)
//        printf("%d\t%s\n",l.ID,l.passHash);
    return 0;
}

