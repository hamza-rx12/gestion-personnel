#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "variables.h"
//#include "tools.h"
#include "add.h"
#include "delete.h"
//#include "modify.h"
#include "list.h"

typedef struct {
    int ID;
    char *job;
}ID_JOB;

void design(){
    printf(CYAN"\n"
           "\n"
           "                    ███████╗███╗   ██╗███████╗ █████╗ ██╗  ██╗                              \n"
           "                    ██╔════╝████╗  ██║██╔════╝██╔══██╗██║  ██║                              \n"
           "                    █████╗  ██╔██╗ ██║███████╗███████║███████║                              \n"
           "                    ██╔══╝  ██║╚██╗██║╚════██║██╔══██║██╔══██║                              \n"
           "                    ███████╗██║ ╚████║███████║██║  ██║██║  ██║                              \n"
           "                    ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝                              \n"
           "                                                                                            \n"
           "        ██████╗ ███████╗██████╗ ███████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗██╗            \n"
           "        ██╔══██╗██╔════╝██╔══██╗██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██║            \n"
           "        ██████╔╝█████╗  ██████╔╝███████╗██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║            \n"
           "        ██╔═══╝ ██╔══╝  ██╔══██╗╚════██║██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║            \n"
           "        ██║     ███████╗██║  ██║███████║╚██████╔╝██║ ╚████║██║ ╚████║███████╗███████╗       \n"
           "        ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚══════╝       \n"
           "                                                                                            \n"
           "███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n"
           "████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n"
           "██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║   \n"
           "██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   \n"
           "██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   \n"
           "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n"
           RESET
           "");
    printf("                                                                                  @HAMZA\n");

}

ID_JOB prompt(){
    ID_JOB t;
    t.ID=0;
    int choice=0;
    printf("1.Login.\n"
           "2.Quit.\n"
           GREEN"Enter your choice(1 or2): "RESET);
    scanf("%d",&choice);
    while(choice!=1 && choice != 2){
        printf("Enter a valid choice(1 or2): ");
        scanf("%d",&choice);
    }
    if(choice==1){
        login l;
        printf("ID = ");
        scanf("%d",&l.ID);
        getchar();
        strcpy(l.passHash,passHasher(getpass("Password = ")));
        if(loginChecker(l)){
            printf("your poste = %s\n", IDtoJob(l.ID));
            t.ID=l.ID;
            t.job=IDtoJob(l.ID);
            return t;
        }else{

            printf("Returning to main menu...\n");
            sleep(3);
            t.job=NULL;
            return t;
        }
    }else exit(EXIT_SUCCESS);

}

int administration_prompt(int ID){
    int choice=0;

    while(1){
        printf(GREEN"STATUS:\t"MAGENTA"ADMINISTRATION\n"RESET);
        printf(GREEN"OPTIONS:\n"RESET
               "\t1.Show my data.\n"
               "\t2.Show professor.\n"
               "\t3.Check leave requests.\n"
               "\t4.logout.\n"
               "\t5.Quit.\n"
               "Input your choice(1-4): ");
        scanf("%d",&choice);
        while(choice!=1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
            printf("Enter a valid choice(1-4): ");
            scanf("%d",&choice);
        }
        switch(choice){
            case 1:
                system("clear");
                design();
                list_specific(ID);
                break;
            case 2:
                system("clear");
                design();
                list_professor();
                break;
            case 3:
                system("clear");
                design();
                list_leave();
                break;
            case 4:
                return 1;
            default:
                exit(EXIT_SUCCESS);

        }
        printf("\npress enter to return.\n");
        getchar();
        getchar();

    }
}

int student_affairs_prompt(int ID){

    int choice=0;

    while(1){
        printf(GREEN"Status:\t"MAGENTA"STUDENT AFFAIRS\n"RESET);
        printf(GREEN"OPTIONS:\n"RESET
               "\t1.Show my data.\n"
               "\t2.Modify my data.\n"
               "\t3.Make leave request.\n"
               "\t4.logout.\n"
               "\t5.Quit.\n"
               "Input your choice(1-4): ");
        scanf("%d",&choice);
        while(choice!=1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
            printf("Enter a valid choice(1-4): ");
            scanf("%d",&choice);
        }
        switch(choice){
            case 1:
                system("clear");
                design();
                list_specific(ID);
                break;
            case 2:
                system("clear");
                design();
                list_professor();
                break;
            case 3:
                system("clear");
                design();
                list_leave();
                break;
            case 4:
                return 1;
            default:
                exit(EXIT_SUCCESS);

        }
        printf("\npress enter to return.\n");
        getchar();
        getchar();

    }

}

int service_maintainer_prompt(int ID){
    printf(GREEN"Status:\t"MAGENTA"SERVICE MAINTAINER\n"RESET);
}

int professor_prompt(int ID){
    printf(GREEN"Status:\t"MAGENTA"PROFESSOR\n"RESET);
}

