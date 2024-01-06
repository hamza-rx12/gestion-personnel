#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "variables.h"
//#include "tools.h"
#include "add.h"
#include "delete.h"
#include "modify.h"
#include "list.h"

typedef struct {
    int ID;
    char *job;
} ID_JOB;

//void design(){
//    printf(CYAN"\n"
//           "\n"
//           "                    ███████╗███╗   ██╗███████╗ █████╗ ██╗  ██╗                              \n"
//           "                    ██╔════╝████╗  ██║██╔════╝██╔══██╗██║  ██║                              \n"
//           "                    █████╗  ██╔██╗ ██║███████╗███████║███████║                              \n"
//           "                    ██╔══╝  ██║╚██╗██║╚════██║██╔══██║██╔══██║                              \n"
//           "                    ███████╗██║ ╚████║███████║██║  ██║██║  ██║                              \n"
//           "                    ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝                              \n"
//           "                                                                                            \n"
//           "        ██████╗ ███████╗██████╗ ███████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗██╗            \n"
//           "        ██╔══██╗██╔════╝██╔══██╗██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██║            \n"
//           "        ██████╔╝█████╗  ██████╔╝███████╗██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║            \n"
//           "        ██╔═══╝ ██╔══╝  ██╔══██╗╚════██║██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║            \n"
//           "        ██║     ███████╗██║  ██║███████║╚██████╔╝██║ ╚████║██║ ╚████║███████╗███████╗       \n"
//           "        ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚══════╝       \n"
//           "                                                                                            \n"
//           "███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n"
//           "████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n"
//           "██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║   \n"
//           "██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   \n"
//           "██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   \n"
//           "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n"
//           RESET
//           "");
//    printf("                                                                                  @HAMZA\n");
//
//}

ID_JOB prompt() {
    ID_JOB t;
    t.ID = 0;
    int choice = 0;
    printf("1.Login.\n"
           "2.Quit.\n"
           GREEN"Enter your choice(1 or 2): "RESET);
    scanf("%d", &choice);
    while (choice != 1 && choice != 2) {
        printf(GREEN"Enter a valid choice(1 or 2): "RESET);
        scanf("%d", &choice);
    }
    if (choice == 1) {
        login l;
        printf("ID = ");
        scanf("%d", &l.ID);
        getchar();
        strcpy(l.passHash, passHasher(getpass("Password = ")));
        if (loginChecker(l)) {
            printf("your poste = %s\n", IDtoJob(l.ID));
            t.ID = l.ID;
            t.job = IDtoJob(l.ID);
            return t;
        } else {

            printf(YELLOW"Returning to main menu...\n"RESET);
            sleep(2);
            t.job = NULL;
            return t;
        }
    } else exit(EXIT_SUCCESS);

}

int administration_prompt(int ID) {
    int choice = 0;

    while (1) {
        system("clear");
        design();
        printf(GREEN"STATUS:\t"MAGENTA"ADMINISTRATION\n"RESET);
        printf(GREEN"OPTIONS:\n"RESET
               "\t1.Show my data.\n"
               "\t2.Show professor.\n"
               "\t3.Check leave requests.\n"
               "\t4.logout.\n"
               "\t5.Quit.\n"
               GREEN"Input your choice(1-4): "RESET);
        scanf("%d", &choice);
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
            printf(GREEN"Enter a valid choice(1-4): "RESET);
            scanf("%d", &choice);
        }
        getchar();
        switch (choice) {
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
    }
}

int student_affairs_prompt(int ID) {

    int choice = 0;

    while (1) {
        system("clear");
        design();
        printf(GREEN"Status:\t"MAGENTA"STUDENT AFFAIRS\n"RESET);
        printf(GREEN"OPTIONS:\n"RESET
               "\t1.Show my data.\n"
               "\t2.Modify my data.\n"
               "\t3.Make leave request.\n"
               "\t4.logout.\n"
               "\t5.Quit.\n"
               GREEN"Input your choice(1-4): "RESET);
        scanf("%d", &choice);
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
            printf(GREEN"Enter a valid choice(1-4): "RESET);
            scanf("%d", &choice);
        }
        getchar();
        switch (choice) {
            case 1:
                system("clear");
                design();
                list_specific(ID);
                break;
            case 2:
                system("clear");
                design();
                modify_personnel(ID);
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
    }

}

int service_maintainer_prompt(int ID) {
    int choice = 0;

    while (1) {
        system("clear");
        design();
        int x, y;
        printf(GREEN"Status:\t"MAGENTA"SERVICE MAINTAINER\n"RESET);
        printf(GREEN"OPTIONS:\n"RESET
               "\t1.Show my data.\n"
               "\t2.Modify my data.\n"
               "\t3.Make leave request.\n"
               "\t4.Add personnel.\n"
               "\t5.Delete personnel.\n"
               "\t6.Modify personnel.\n"
               "\t7.List personnel.\n"
               "\t8.logout.\n"
               "\t9.Quit.\n"
               GREEN"Input your choice(1-9): "RESET);
        scanf("%d", &choice);
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5
               && choice != 6 && choice != 7 && choice != 8 && choice != 9) {
            printf(GREEN"Enter a valid choice(1-9): "RESET);
            scanf("%d", &choice);
        }
        getchar();
        switch (choice) {
            case 1://show sp
                system("clear");
                design();
                list_specific(ID);
                break;
            case 2://modify sp
                system("clear");
                design();
                modify_personnel(ID);
                break;
            case 3://leave request
                system("clear");
                design();
                list_leave();
                break;
            case 4://add personnel
                system("clear");
                design();
                add_personnel();
                break;
            case 5://delete personnel
                system("clear");
                design();
                printf(GREEN"Enter an account ID to delete: "RESET);
                scanf("%d", &x);
                if (!check_ID(x)) {
                    printf(RED"ID not found!\n"RESET);
                    break;
                } else
                    delete_personnel(x);
                break;
            case 6://modify personnel
                system("clear");
                design();
                printf(GREEN"Enter an account ID to modify: "RESET);
                scanf("%d", &x);
                if (!check_ID(x)) {
                    printf(RED"ID not found!\n"RESET);
                    break;
                } else
                    modify_personnel(x);
                break;
            case 7://list personnel
                system("clear");
                design();
                printf(GREEN"Choose listing method:\n"RESET
                       "\t1.list by profession.\n"
                       "\t2.list by ID.\n"
                       "\t3.list all.\n"
                       GREEN"Your choice (1-3): "RESET);
                scanf("%d", &x);
                while (x != 1 && x != 2 && x != 3) {
                    printf(GREEN"Input a valid choice (1-3): "RESET);
                    scanf("%d", &x);
                }
                getchar();
                switch (x) {
                    case 1:
                        system("clear");
                        design();
                        printf(GREEN"Choose a profession to list:\n"RESET
                               "\t1.Professor.\n"
                               "\t2.Student Affairs.\n"
                               "\t3.Administration.\n"
                               "\t4.Service maintainer(service info).\n"
                               GREEN"Your choice (1-4): "RESET);
                        scanf("%d", &y);
                        while (y != 1 && y != 2 && y != 3 && y != 4) {
                            printf(GREEN"Input a valid choice (1-4): "RESET);
                            scanf("%d", &y);
                        }
                        getchar();
                        switch (y) {
                            case 1:
                                system("clear");
                                design();
                                list_professor();
                                break;
                            case 2:
                                system("clear");
                                design();
                                list_student_affairs();
                                break;
                            case 3:
                                system("clear");
                                design();
                                list_administration();
                                break;
                            default:
                                system("clear");
                                design();
                                list_service_maintainer();
                                break;
                        }
                        break;

                    case 2:
                        printf(GREEN"Input a account ID: "RESET);
                        scanf("%d", &y);
                        if (!check_ID(y)) {
                            printf(RED"ID not found!\n"RESET);
                            break;
                        } else
                            system("clear");
                        design();
                        getchar();
                        list_specific(y);
                        break;
                    default:
                        system("clear");
                        design();
                        list_all();
                        break;
                }
                break;
            case 8:
                return 1;
            default:
                exit(EXIT_SUCCESS);

        }

    }
}

int professor_prompt(int ID) {
    int choice = 0;

    while (1) {
        system("clear");
        design();
        printf(GREEN"Status:\t"MAGENTA"PROFESSOR\n"RESET);
        printf(GREEN"OPTIONS:\n"RESET
               "\t1.Show my data.\n"
               "\t2.Modify my data.\n"
               "\t3.Make leave request.\n"
               "\t4.logout.\n"
               "\t5.Quit.\n"
               GREEN"Input your choice(1-5): "RESET);
        scanf("%d", &choice);
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
            printf(GREEN"Enter a valid choice(1-5): "RESET);
            scanf("%d", &choice);
        }
        getchar();
        switch (choice) {
            case 1:
                system("clear");
                design();
                list_specific(ID);
                break;
            case 2:
                system("clear");
                design();
                modify_personnel(ID);
                break;
            case 3:
                system("clear");
                design();
                add_leave_request();
                break;
            case 4:
                return 1;
            default:
                exit(EXIT_SUCCESS);

        }

    }
}

