#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    setenv("IacmpDir",        ...);
    setenv("LD_LIBRARY_PATH", ...);
    execv(...);
    fprintf(stderr, "%s: execv failed: %s\n",
            ...
           );
    return ...;
}
