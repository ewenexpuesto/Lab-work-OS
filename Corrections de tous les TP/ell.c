#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    int fd = open("/tmp/fifo", O_WRONLY);
    if (fd == -1) {
        perror("[open]");
        exit(1);
    }

    printf("ell"); fflush(stdout);
    
    if (write(fd, "x", 1) == -1) {
        perror("[write]");
        exit(2);
    }

    return 0;
}
