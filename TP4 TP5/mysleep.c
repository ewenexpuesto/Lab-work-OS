#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* I don't know which include to add so I copy pasted all from recent file */
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

/* Ne pas oublier les include */

#include <assert.h> /* adds assert */
typedef void(*sighandler_t)(int); /* the manual tells to do that */

/* But : SIGALARM se met en pause par défaut */

void and_nothing_else(int signum) {
    assert(signum==SIGALRM);
}

void mysleep(unsigned int nb)
{
    /* TODO */
    alarm(nb); /* sends a SIGALRM */
    pause();
    sighandler_t prev=signal(SIGALRM,and_nothing_else);
    if (prev==SIG_ERR) {
        perror("[signal]");
        exit(1);
    }
    alarm(nb); /* sends a SIGALRM */
    pause();
}


int main(int argc, char* argv[])
{
    if (argc!=2) {
        fprintf(stderr, "usage: %s <int>\n", argv[0]);
        return 1;
    }

    printf("%s [%d]\n", argv[0], getpid());
    mysleep(strtoul(argv[1], NULL, 10));
    printf("done.\n");

    return 0;
}
