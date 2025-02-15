#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    int fd1[2];
    int fd2[2];
    char ch;

    if (pipe(fd1) == -1) {
        perror("[pipe1]");
        exit(1);
    }
    if (pipe(fd2) == -1) {
        perror("[pipe2]");
        exit(2);
    }
    
    pid_t pid = fork();
    switch (pid) {
        case -1:
            perror("[fork]");
            exit(3);
            break;
        case 0:
            read(fd1[0], &ch, 1);
            printf("ell"); fflush(stdout);
            write(fd2[1], "x", 1);
            break;
        default:
            printf("h");   fflush(stdout);
            write(fd1[1], "x", 1);
            read(fd2[0], &ch, 1);
            printf("o\n"); fflush(stdout);
            wait(NULL);
    }

    return 0;
}
