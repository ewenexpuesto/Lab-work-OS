#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

/* returns 1 if str represents a non-negative integer, and 0 otherwise */
int isNumber(const char* str)
{
    for (; *str; str+=1) 
        if (*str<'0' || '9'<*str)
            return 0;
    return 1;
}

char tmp[300];
char* envv_next[4] = { tmp, tmp+100, tmp+200, NULL };

int main(int argc, char* argv[], char* envv[])
{
    if (argc == 1 && argv[0][0] != '\0') {
        /* first execution */
        if ( !isNumber(basename(argv[0])) ) {
            fprintf(stderr, "%s:usage: ./<int>\n", argv[0]);
            exit(1);
        }
        envv_next[0] = basename(argv[0]);
        envv_next[1] = ... ;
        envv_next[2] = ... ;
    } else if (argc == 1) {
        /* next executions */
        long n    = ... ;
        long fac  = ... ;
        char* cmd = ... ;
        if (n == 1) {
            printf("%s! = %ld\n", basename(cmd), fac);
            return 0;
        }
        fac = ...; n = ...;
        sprintf(envv_next[0], ...);
        sprintf(envv_next[1], ...);
        envv_next[2] = ...;
    }
    execle(...);
    fprintf(stderr, "execle(%s): %s\n", envv_next[2], strerror(errno));
    return 1;
}

