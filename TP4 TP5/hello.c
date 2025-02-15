#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#include <assert.h>
typedef void(*sighandler_t)(int);

void and_nothing_else(int signum) {
    assert(signum==SIGALRM);
}

void mysleep(unsigned int nb)
{
    alarm(nb);
    pause();
    sighandler_t prev=signal(SIGALRM,and_nothing_else);
    if (prev==SIG_ERR) {
        perror("[signal]");
        exit(1);
    }
    alarm(nb);
    pause();
}

/* QUESTION 1 */

/* attention, ne pas écrire pid_t pid1=fork() puis après pid_t pid2=fork(), voir photos 2 décembre */

/*
int main() {
    int pid1=fork();
    int pid2=fork();
    fprintf(stdout,"hello");

    kill(pid1,0);
    mysleep(2);
    wait(pid1);

    kill(pid2,0);
    mysleep(1);
    fprintf(stdout," world");
    wait(pid2);
}
*/

/* correction, voir photos pour le schéma exacte */

void child(int nb, const char* msg) {
    sleep(nb);
    printf(msg); /* ne pas faire confiance à l'utilisateur, ce n'est pas safe si l'utilisateur fait %d, jamais de variable en premier argument de printf*/
    printf("%s",msg);
    exit(0);
}

int main() {
    pid_t pid1=fork();
    if (pid1==-1) {
        perror("[fork1]"); exit(1);
    } else if (pid1==0) {
        /* fils */
        child(2,"\n");
        exit(0);
    }
    /* père */
    pid_t pid2=fork();
    if (pid2==-1) {
        perror("[fork 2]");
        exit(2);
    } else if (pid2==0) {
        /* second child */
        child(1,"world");
        exit(0);
    }
    /* father */
    pintf("hello");
    fflush(stdout);
}
/* fflush(stint) ne fonctionne pas, c'est une erreur */ 

/* QUESTION 2 */
/* la seule chose à changer : ajouter wait(NULL); wait(NULL);return(0); à la fin */