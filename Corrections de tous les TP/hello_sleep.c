#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t pid = fork();
    switch (pid) {
        case -1:
            perror("[fork]");
            exit(1);
            break;
        case 0:
            sleep(1);
            printf("ell"); fflush(stdout);
            break;
        default:
            printf("h");   fflush(stdout);
            sleep(2);
            printf("o\n"); fflush(stdout);
            wait(NULL);
    }

    return 0;
}
