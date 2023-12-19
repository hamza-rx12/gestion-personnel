#include <stdio.h>
#include <stdlib.h>
#include "lib/manage.h"
//#include "lib/tools.h"

int main() {
    char *job;
    ID_JOB t;
    int level1;
    int level2;
    do {
        do {
            system("clear");
            design();
            t = prompt();
            job = t.job;
            level1 = t.ID;

        } while (!level1);

        if (!strcmp(job, "administration")) {
            system("clear");
            design();
            level2 = administration_prompt(level1);
        } else if (!strcmp(job, "student_affairs")) {
            system("clear");
            design();
            level2 = student_affairs_prompt(level1);
        } else if (!strcmp(job, "service_maintainer")) {
            system("clear");
            design();
            level2 = service_maintainer_prompt(level1);
        } else if (!strcmp(job, "professor")) {
            system("clear");
            design();
            level2 = professor_prompt(level1);
        }

    } while (level2);


    return 0;
}
