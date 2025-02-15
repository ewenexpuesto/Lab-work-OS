#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int pipefd[2];

/*
build my own cat
*/
void left_child() {
    /* close the read end of pipefd, since this child will not use it */

    FILE *file = fopen(pipefd[2], "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", pipefd[2]);
        return;
    }
    /* while we can read a character on the standard input,
     * get it and write it on the write end of pipefd */
    
    // Read and print the file
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(file);

    exit(0);
}

/*
translate : 

while read line ; do
if [ "$line" = "q" ] ; then break ; else echo "got: '$line'" ; fi
done
*/
void right_child() {
    /* close the write end of pipefd, since this child will not use it */
    wait(pipefd[2]);

    char line[1024];
    int index = 0;
    while (1) {
        /* get a line from the read end of pipefd,
         * or abort if the maximum size of 1024 is reached */
        index = 0;
        do {
            /* read a character from the read end of pipefd */
            char c;
            int statut = read(0, &c, 1);

            index++;
            if (index > 1024) {
                fprintf(stderr, "error: input is too long\n");
                exit(1);
            }
        } while (line[index-1] != '\n');

        /* check whether we should stop reading or print the line */
        if (index == 2 && line[0] == 'q') {
            break;
        } else {
            /* write the expected output on the standard output */
            char c;
            write(1, &c, 1);
        }
    }
    exit(0);
}

int main() {
    /* initialize pipefd */
    ...
    /* create/run the left and right children */
    left_child():
    right_child();
    /* close both ends of pipefd, since the main program will not use them */
    ...
    /* wait the termination of the two children */
    ...

    return 0;
}

/* QUESTION 4 */
/*

*/