#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>

void do_nothing(int sig) { assert(sig == SIGUSR1); }

int main() {
    if (signal(SIGUSR1, do_nothing) == SIG_ERR) {
        perror("[signal]");
        exit(1);
    }
    
    pid_t pid = fork();
    switch (pid) {
        case -1:
            perror("[fork]");
            exit(2);
            break;
        case 0:
            pause();
            printf("ell"); fflush(stdout);
            kill(getppid(), SIGUSR1);
            break;
        default:
            printf("h");   fflush(stdout);
            kill(pid, SIGUSR1);
            pause();
            printf("o\n"); fflush(stdout);
            wait(NULL);
    }

    return 0;
}
