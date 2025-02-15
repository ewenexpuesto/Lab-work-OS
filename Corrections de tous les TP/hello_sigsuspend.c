#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>

void do_nothing(int sig) { assert(sig == SIGUSR1); }

int main() {
    /* 1. ask to do nothing when signal USR1 is received */
    if (signal(SIGUSR1, do_nothing) == SIG_ERR) {
        perror("[signal]");
        exit(1);
    }

    /* 2. ask not to deliver signal USR1 for the time being */
    sigset_t mask_old;
    sigset_t mask_usr1;
    sigemptyset(&mask_usr1);
    sigaddset(&mask_usr1, SIGUSR1);
    if (sigprocmask(SIG_BLOCK, &mask_usr1, &mask_old) == -1) {
        perror("[sigprocmask]");
        exit(2);
    }
    /* also check that signal USR1 was actually delivered
     * before the call to sigprocmask */
    assert (!sigismember(&mask_old, SIGUSR1));
    
    /* 3. create a child process */
    pid_t pid = fork();
    switch (pid) {
        case -1:
            perror("[fork]");
            exit(2);
            break;
        case 0:
            /* 3a. child process:
             *     - re-enable delivery of USR1 and wait for a signal (atomicaly)
             *     - print "ell"
             *     - send USR1 to the father process
             */
            sigsuspend(&mask_old);
            printf("ell"); fflush(stdout);
            kill(getppid(), SIGUSR1);
            break;
        default:
            /* 3b. father process:
             *     - print "h"
             *     - send USR1 to the child process
             *     - re-enable delivery of USR1 and wait for a signal (atomicaly)
             *     - print "o\n"
             *     - wait for the termination of the child process
             */
            printf("h");   fflush(stdout);
            kill(pid, SIGUSR1);
            sigsuspend(&mask_old);
            printf("o\n"); fflush(stdout);
            wait(NULL);
    }

    return 0;
}
