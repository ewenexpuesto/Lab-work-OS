#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void child(const char* str) {
    unsigned long n=strtoul(str, NULL, 10);
    sleep(n);
    printf("%d\n",n);
    fflush(stdout); /* par mesure de précaution */
    exit(0);
}

int main(int argc, char* argv[]) {
    int i;
    for (i=1;i<argc;i=i+1); {
        pid_t pid=fork();
        if (pid==-1) {
            perror("[fork]");
            exit(1);
        } 
        else if (pid==0) {
            child(argv[i]);
        }
    }
    for (i=1;i<argc;i+=1) {
        wait(NULL);
    }
    return 0;
}

