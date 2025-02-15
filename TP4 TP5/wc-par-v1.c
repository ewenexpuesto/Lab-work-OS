#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void child(int n) {
    sleep(n);
    exit(0);
}

int counts_number_lines(FILE f) {
    char* fptr = fopen("filename.txt", "r"); /* https://www.w3schools.com/c/c_files_read.php */
    /* finir ... */
}

int main(int argc, char* argv[]) {
    int sz=size(argv[1]);
    int i;
    /* création des fils et on attend qu'ils se terminent */
    for (i=0; i<4; i+=1) {
        pid_t pid=fork();
        if (pid==-1) {
            perror("[fork]");
            exit(1);
        }
        else if (pid==0) {
            child(i);
        }
    }
    for (i=0; i<4; i+=1) {
        wait(NULL);
    }
}